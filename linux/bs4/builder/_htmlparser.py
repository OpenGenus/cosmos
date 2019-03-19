"""Use the HTMLParser library to parse HTML files that aren't too bad."""

# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

__all__ = [
    'HTMLParserTreeBuilder',
    ]

from html.parser import HTMLParser

try:
    from html.parser import HTMLParseError
except ImportError as e:
    # HTMLParseError is removed in Python 3.5. Since it can never be
    # thrown in 3.5, we can just define our own class as a placeholder.
    class HTMLParseError(Exception):
        pass

import sys
import warnings

# Starting in Python 3.2, the HTMLParser constructor takes a 'strict'
# argument, which we'd like to set to False. Unfortunately,
# http://bugs.python.org/issue13273 makes strict=True a better bet
# before Python 3.2.3.
#
# At the end of this file, we monkeypatch HTMLParser so that
# strict=True works well on Python 3.2.2.
major, minor, release = sys.version_info[:3]
CONSTRUCTOR_TAKES_STRICT = major == 3 and minor == 2 and release >= 3
CONSTRUCTOR_STRICT_IS_DEPRECATED = major == 3 and minor == 3
CONSTRUCTOR_TAKES_CONVERT_CHARREFS = major == 3 and minor >= 4


from bs4.element import (
    CData,
    Comment,
    Declaration,
    Doctype,
    ProcessingInstruction,
    )
from bs4.dammit import EntitySubstitution, UnicodeDammit

from bs4.builder import (
    HTML,
    HTMLTreeBuilder,
    STRICT,
    )


HTMLPARSER = 'html.parser'

class BeautifulSoupHTMLParser(HTMLParser):

    def __init__(self, *args, **kwargs):
        HTMLParser.__init__(self, *args, **kwargs)

        # Keep a list of empty-element tags that were encountered
        # without an explicit closing tag. If we encounter a closing tag
        # of this type, we'll associate it with one of those entries.
        #
        # This isn't a stack because we don't care about the
        # order. It's a list of closing tags we've already handled and
        # will ignore, assuming they ever show up.
        self.already_closed_empty_element = []
    
    def handle_startendtag(self, name, attrs):
        # This is only called when the markup looks like
        # <tag/>.

        # is_startend() tells handle_starttag not to close the tag
        # just because its name matches a known empty-element tag. We
        # know that this is an empty-element tag and we want to call
        # handle_endtag ourselves.
        tag = self.handle_starttag(name, attrs, handle_empty_element=False)
        self.handle_endtag(name)
        
    def handle_starttag(self, name, attrs, handle_empty_element=True):
        # XXX namespace
        attr_dict = {}
        for key, value in attrs:
            # Change None attribute values to the empty string
            # for consistency with the other tree builders.
            if value is None:
                value = ''
            attr_dict[key] = value
            attrvalue = '""'
        #print "START", name
        tag = self.soup.handle_starttag(name, None, None, attr_dict)
        if tag and tag.is_empty_element and handle_empty_element:
            # Unlike other parsers, html.parser doesn't send separate end tag
            # events for empty-element tags. (It's handled in
            # handle_startendtag, but only if the original markup looked like
            # <tag/>.)
            #
            # So we need to call handle_endtag() ourselves. Since we
            # know the start event is identical to the end event, we
            # don't want handle_endtag() to cross off any previous end
            # events for tags of this name.
            self.handle_endtag(name, check_already_closed=False)

            # But we might encounter an explicit closing tag for this tag
            # later on. If so, we want to ignore it.
            self.already_closed_empty_element.append(name)
            
    def handle_endtag(self, name, check_already_closed=True):
        #print "END", name
        if check_already_closed and name in self.already_closed_empty_element:
            # This is a redundant end tag for an empty-element tag.
            # We've already called handle_endtag() for it, so just
            # check it off the list.
            # print "ALREADY CLOSED", name
            self.already_closed_empty_element.remove(name)
        else:
            self.soup.handle_endtag(name)

    def handle_data(self, data):
        self.soup.handle_data(data)

    def handle_charref(self, name):
        # XXX workaround for a bug in HTMLParser. Remove this once
        # it's fixed in all supported versions.
        # http://bugs.python.org/issue13633
        if name.startswith('x'):
            real_name = int(name.lstrip('x'), 16)
        elif name.startswith('X'):
            real_name = int(name.lstrip('X'), 16)
        else:
            real_name = int(name)

        try:
            data = chr(real_name)
        except (ValueError, OverflowError) as e:
            data = "\N{REPLACEMENT CHARACTER}"

        self.handle_data(data)

    def handle_entityref(self, name):
        character = EntitySubstitution.HTML_ENTITY_TO_CHARACTER.get(name)
        if character is not None:
            data = character
        else:
            data = "&%s;" % name
        self.handle_data(data)

    def handle_comment(self, data):
        self.soup.endData()
        self.soup.handle_data(data)
        self.soup.endData(Comment)

    def handle_decl(self, data):
        self.soup.endData()
        if data.startswith("DOCTYPE "):
            data = data[len("DOCTYPE "):]
        elif data == 'DOCTYPE':
            # i.e. "<!DOCTYPE>"
            data = ''
        self.soup.handle_data(data)
        self.soup.endData(Doctype)

    def unknown_decl(self, data):
        if data.upper().startswith('CDATA['):
            cls = CData
            data = data[len('CDATA['):]
        else:
            cls = Declaration
        self.soup.endData()
        self.soup.handle_data(data)
        self.soup.endData(cls)

    def handle_pi(self, data):
        self.soup.endData()
        self.soup.handle_data(data)
        self.soup.endData(ProcessingInstruction)


class HTMLParserTreeBuilder(HTMLTreeBuilder):

    is_xml = False
    picklable = True
    NAME = HTMLPARSER
    features = [NAME, HTML, STRICT]

    def __init__(self, *args, **kwargs):
        if CONSTRUCTOR_TAKES_STRICT and not CONSTRUCTOR_STRICT_IS_DEPRECATED:
            kwargs['strict'] = False
        if CONSTRUCTOR_TAKES_CONVERT_CHARREFS:
            kwargs['convert_charrefs'] = False
        self.parser_args = (args, kwargs)

    def prepare_markup(self, markup, user_specified_encoding=None,
                       document_declared_encoding=None, exclude_encodings=None):
        """
        :return: A 4-tuple (markup, original encoding, encoding
        declared within markup, whether any characters had to be
        replaced with REPLACEMENT CHARACTER).
        """
        if isinstance(markup, str):
            yield (markup, None, None, False)
            return

        try_encodings = [user_specified_encoding, document_declared_encoding]
        dammit = UnicodeDammit(markup, try_encodings, is_html=True,
                               exclude_encodings=exclude_encodings)
        yield (dammit.markup, dammit.original_encoding,
               dammit.declared_html_encoding,
               dammit.contains_replacement_characters)

    def feed(self, markup):
        args, kwargs = self.parser_args
        parser = BeautifulSoupHTMLParser(*args, **kwargs)
        parser.soup = self.soup
        try:
            parser.feed(markup)
        except HTMLParseError as e:
            warnings.warn(RuntimeWarning(
                "Python's built-in HTMLParser cannot parse the given document. This is not a bug in Beautiful Soup. The best solution is to install an external parser (lxml or html5lib), and use Beautiful Soup with that parser. See http://www.crummy.com/software/BeautifulSoup/bs4/doc/#installing-a-parser for help."))
            raise e
        parser.already_closed_empty_element = []

# Patch 3.2 versions of HTMLParser earlier than 3.2.3 to use some
# 3.2.3 code. This ensures they don't treat markup like <p></p> as a
# string.
#
# XXX This code can be removed once most Python 3 users are on 3.2.3.
if major == 3 and minor == 2 and not CONSTRUCTOR_TAKES_STRICT:
    import re
    attrfind_tolerant = re.compile(
        r'\s*((?<=[\'"\s])[^\s/>][^\s/=>]*)(\s*=+\s*'
        r'(\'[^\']*\'|"[^"]*"|(?![\'"])[^>\s]*))?')
    HTMLParserTreeBuilder.attrfind_tolerant = attrfind_tolerant

    locatestarttagend = re.compile(r"""
  <[a-zA-Z][-.a-zA-Z0-9:_]*          # tag name
  (?:\s+                             # whitespace before attribute name
    (?:[a-zA-Z_][-.:a-zA-Z0-9_]*     # attribute name
      (?:\s*=\s*                     # value indicator
        (?:'[^']*'                   # LITA-enclosed value
          |\"[^\"]*\"                # LIT-enclosed value
          |[^'\">\s]+                # bare value
         )
       )?
     )
   )*
  \s*                                # trailing whitespace
""", re.VERBOSE)
    BeautifulSoupHTMLParser.locatestarttagend = locatestarttagend

    from html.parser import tagfind, attrfind

    def parse_starttag(self, i):
        self.__starttag_text = None
        endpos = self.check_for_whole_start_tag(i)
        if endpos < 0:
            return endpos
        rawdata = self.rawdata
        self.__starttag_text = rawdata[i:endpos]

        # Now parse the data between i+1 and j into a tag and attrs
        attrs = []
        match = tagfind.match(rawdata, i+1)
        assert match, 'unexpected call to parse_starttag()'
        k = match.end()
        self.lasttag = tag = rawdata[i+1:k].lower()
        while k < endpos:
            if self.strict:
                m = attrfind.match(rawdata, k)
            else:
                m = attrfind_tolerant.match(rawdata, k)
            if not m:
                break
            attrname, rest, attrvalue = m.group(1, 2, 3)
            if not rest:
                attrvalue = None
            elif attrvalue[:1] == '\'' == attrvalue[-1:] or \
                 attrvalue[:1] == '"' == attrvalue[-1:]:
                attrvalue = attrvalue[1:-1]
            if attrvalue:
                attrvalue = self.unescape(attrvalue)
            attrs.append((attrname.lower(), attrvalue))
            k = m.end()

        end = rawdata[k:endpos].strip()
        if end not in (">", "/>"):
            lineno, offset = self.getpos()
            if "\n" in self.__starttag_text:
                lineno = lineno + self.__starttag_text.count("\n")
                offset = len(self.__starttag_text) \
                         - self.__starttag_text.rfind("\n")
            else:
                offset = offset + len(self.__starttag_text)
            if self.strict:
                self.error("junk characters in start tag: %r"
                           % (rawdata[k:endpos][:20],))
            self.handle_data(rawdata[i:endpos])
            return endpos
        if end.endswith('/>'):
            # XHTML-style empty tag: <span attr="value" />
            self.handle_startendtag(tag, attrs)
        else:
            self.handle_starttag(tag, attrs)
            if tag in self.CDATA_CONTENT_ELEMENTS:
                self.set_cdata_mode(tag)
        return endpos

    def set_cdata_mode(self, elem):
        self.cdata_elem = elem.lower()
        self.interesting = re.compile(r'</\s*%s\s*>' % self.cdata_elem, re.I)

    BeautifulSoupHTMLParser.parse_starttag = parse_starttag
    BeautifulSoupHTMLParser.set_cdata_mode = set_cdata_mode

    CONSTRUCTOR_TAKES_STRICT = True
