Skip to content
This repository
Search
Pull requests
Issues
Marketplace
Explore
 @faisal1337
 Sign out
 Watch 20
  Star 85  Fork 45 cs50/libcs50
 Code  Issues 2  Pull requests 1 Insights 
Branch: develop Find file Copy pathlibcs50/src/cs50.h
80275e4  26 days ago
@crossroads1112 crossroads1112 added get_long (#109)
4 contributors @dmalan @crossroads1112 @kzidane @dlloyd09
RawBlameHistory     
223 lines (196 sloc)  9.81 KB
/**
 * CS50 Library for C
 * https://github.com/cs50/libcs50
 *
 * Based on Eric Roberts' genlib.c and simpio.c.
 *
 * Copyright (c) 2017.
 * All rights reserved.
 *
 * BSD 3-Clause License
 * http://www.opensource.org/licenses/BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the name of CS50 nor the names of its contributors may be used
 *   to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _CS50_H
#define _CS50_H

#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Our own data type for string variables.
 */
typedef char *string;

/**
 * Temporarily used to make arguments to get_* (but not Get*) optional.
 * Inspired by https://gustedt.wordpress.com/2010/06/08/detect-empty-macro-arguments/
 */

#define CONCAT(a, b) a ## b 
#define SECOND(first, second, ...) second
#define NOT_(...) SECOND(__VA_ARGS__, 0)
#define NOT_SENTINEL_0 ignore_me, 1
#define NOT(cond) NOT_(CONCAT(NOT_SENTINEL_, cond))
#define BOOL(cond) NOT(NOT(cond))

#define IF_ELSE(cond) IF_ELSE_(BOOL(cond))
#define IF_ELSE_(cond) CONCAT(IF_, cond)
#define IF_1(...) __VA_ARGS__ IF_1_ELSE
#define IF_0(...) IF_0_ELSE
#define IF_1_ELSE(...)
#define IF_0_ELSE(...) __VA_ARGS__

#define ARG(_0, _1, _2, _3, _4, _5, _6, _7,                 \
            _8, _9, _10, _11, _12, _13, _14, _15,           \
            _16, _17, _18, _19, _20, _21, _22, _23,         \
            _24, _25, _26, _27, _28, _29, _30, _31,         \
            _32, _33, _34, _35, _36, _37, _38, _39,         \
            _40, _41, _42, _43, _44, _45, _46, _47,         \
            _48, _49, _50, _51, _52, _53, _54, _55,         \
            _56, _57, _58, _59, _60, _61, _62, _63,         \
            _64, _65, _66, _67, _68, _69, _70, _71,         \
            _72, _73, _74, _75, _76, _77, _78, _79,         \
            _80, _81, _82, _83, _84, _85, _86, _87,         \
            _88, _89, _90, _91, _92, _93, _94, _95,         \
            _96, _97, _98, _99, _100, _101, _102, _103,     \
            _104, _105, _106, _107, _108, _109, _110, _111, \
            _112, _113, _114, _115, _116, _117, _118, _119, \
            _120, _121, _122,_123, _124, _125, ...) _125


#define HAS_COMMA(...) ARG(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1,  \
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,   \
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,   \
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,   \
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,   \
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,   \
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,   \
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,   \
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,   \
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0)
                     
#define TRIGGER(...) ,
 
#define IS_PAREN(...)       HAS_COMMA(TRIGGER __VA_ARGS__)
#define IS_CALLABLE(...)    HAS_COMMA(__VA_ARGS__ ())
#define IS_ANYTHING(...)    NOT(HAS_COMMA(TRIGGER __VA_ARGS__ ()))

#define ISEMPTY(...) ALL_FALSE(HAS_COMMA(__VA_ARGS__),      \
                               IS_PAREN(__VA_ARGS__),       \
                               IS_CALLABLE(__VA_ARGS__),    \
                               IS_ANYTHING(__VA_ARGS__))
 
#define CONCAT5(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4
#define ALL_FALSE(_0, _1, _2, _3) HAS_COMMA(CONCAT5(FALSE_SENTINEL_, _0, _1, _2, _3))
#define FALSE_SENTINEL_0000 ,

#define WARN_MSG "GCC warning \"As of Jan 1, 2018 all 'get_' functions require at least one argument (a prompt). Please see reference.cs50.net/cs50 for more information.\""
#define WARN(func)  do { _Pragma(WARN_MSG); func; } while (0)

// TODO: Remove these two lines once no-argument function calls are deprecated
#undef WARN
#define WARN(func) func

/** 
 * If compiler isn't GCC or Clang it may not support __extension__, 
 * better to suppress this error and hope for the best 
 */
#ifndef __GNUC__
    #define __extension__
#endif

/**
 * Prints an error message, formatted like printf, to standard error, prefixing it with
 * file name and line number from which function was called (which a macro provides).
 *
 * This function is not intended to be called directly. Instead, call the macro of the same name,
 * which expects fewer arguments.
 *
 * Inspired by http://www.gnu.org/software/libc/manual/html_node/Variable-Arguments-Output.html
 * http://www.gnu.org/software/libc/manual/html_node/Error-Messages.html#Error-Messages, and
 * https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html.
 */
void eprintf(const string file, int line, const string format, ...) __attribute__((format(printf, 3, 4)));

/**
 * Macro that allows function of the same name to be called without specifying caller's
 * file name or line number explicitly.
 */
#define eprintf(...) eprintf(__FILE__, __LINE__, __VA_ARGS__)

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent char; if text is not a single char, user is prompted
 * to retry. If line can't be read, returns CHAR_MAX.
 */
char get_char(const string format, ...) __attribute__((format(printf, 1, 2)));
char GetChar(void) __attribute__((deprecated));
#define get_char(...) __extension__ IF_ELSE(ISEMPTY(__VA_ARGS__))(WARN(get_char(NULL)))(get_char(__VA_ARGS__))

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent double as precisely as possible; if text does not represent
 * a double or if value would cause underflow or overflow, user is
 * prompted to retry. If line can't be read, returns DBL_MAX.
 */
double get_double(const string format, ...) __attribute__((format(printf, 1, 2)));
double GetDouble(void) __attribute__((deprecated));
#define get_double(...) __extension__ IF_ELSE(ISEMPTY(__VA_ARGS__))(WARN(get_double(NULL)))(get_double(__VA_ARGS__))

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent float as precisely as possible; if text does not represent
 * a float or if value would cause underflow or overflow, user is prompted
 * to retry. If line can't be read, returns FLT_MAX.
 */
float get_float(const string format, ...) __attribute__((format(printf, 1, 2)));
float GetFloat(void) __attribute__((deprecated));
#define get_float(...) __extension__ IF_ELSE(ISEMPTY(__VA_ARGS__))(WARN(get_float(NULL)))(get_float(__VA_ARGS__))

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent int; if text does not represent an int in [-2^31, 2^31 - 1)
 * or would cause underflow or overflow, user is prompted to retry. If line
 * can't be read, returns INT_MAX.
 */
int get_int(const string format, ...) __attribute__((format(printf, 1, 2)));
int GetInt(void) __attribute__((deprecated));
#define get_int(...) __extension__ IF_ELSE(ISEMPTY(__VA_ARGS__))(WARN(get_int(NULL)))(get_int(__VA_ARGS__))

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent long long; if text does not represent a long long in
 * [-2^63, 2^63 - 1) or would cause underflow or overflow, user is
 * prompted to retry. If line can't be read, returns LLONG_MAX.
 *
 * This will be deprecated in favor of get_long.
 */
long long get_long_long(const string format, ...) __attribute__((format(printf, 1, 2)));
long long GetLongLong(void) __attribute__((deprecated));
#define get_long_long(...) __extension__ IF_ELSE(ISEMPTY(__VA_ARGS__))(WARN(get_long_long(NULL)))(get_long_long(__VA_ARGS__))

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent long; if text does not represent a long in
 * [-2^63, 2^63 - 1) or would cause underflow or overflow, user is
 * prompted to retry. If line can't be read, returns LONG_MAX.
 */
long get_long(const string format, ...) __attribute__((format(printf, 1, 2)));
#define get_long(...) IF_ELSE(ISEMPTY(__VA_ARGS__))(WARN(get_long(NULL)))(get_long(__VA_ARGS__))

/**
 * Prompts user for a line of text from standard input and returns
 * it as a string (char *), sans trailing line ending. Supports
 * CR (\r), LF (\n), and CRLF (\r\n) as line endings. If user
 * inputs only a line ending, returns "", not NULL. Returns NULL
 * upon error or no input whatsoever (i.e., just EOF). Stores string
 * on heap, but library's destructor frees memory on program's exit.
 */
string get_string(va_list *args, const string format, ...) __attribute__((format(printf, 2, 3)));
string GetString(void) __attribute__((deprecated));
#define get_string(...) __extension__ IF_ELSE(ISEMPTY(__VA_ARGS__))(WARN(get_string(NULL, NULL)))(get_string(NULL, __VA_ARGS__))

#endif
© 2017 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
API
Training
Shop
Blog
About