# Cosmos Guides
> Your personal library of every algorithm and data structure code that you will ever encounter

# Ruby Style Guide
([Source](https://github.com/github/rubocop-github/blob/master/STYLEGUIDE.md))

This style guide is licensed under the [MIT License](https://github.com/github/rubocop-github/blob/master/LICENSE).

* Use soft-tabs with a two space indent.

* Keep each line of code to a readable length. Unless you have a reason to, keep lines to fewer than 100 characters.

* Never leave trailing whitespace.

* End each file with a [newline](https://github.com/bbatsov/ruby-style-guide#newline-eof).

* Use spaces around operators, after commas, colons and semicolons, around `{`
  and before `}`.

``` ruby
sum = 1 + 2
a, b = 1, 2
1 > 2 ? true : false; puts "Hi"
[1, 2, 3].each { |e| puts e }
```

* No spaces after `(`, `[` or before `]`, `)`.

``` ruby
some(arg).other
[1, 2, 3].length
```

* No spaces after `!`.

``` ruby
!array.include?(element)
```

* Indent `when` as deep as `case`.

``` ruby
case
when song.name == "Misty"
  puts "Not again!"
when song.duration > 120
  puts "Too long!"
when Time.now.hour > 21
  puts "It's too late"
else
  song.play
end

kind = case year
       when 1850..1889 then "Blues"
       when 1890..1909 then "Ragtime"
       when 1910..1929 then "New Orleans Jazz"
       when 1930..1939 then "Swing"
       when 1940..1950 then "Bebop"
       else "Jazz"
       end
```

* Use empty lines between `def`s and to break up a method into logical
  paragraphs.

``` ruby
def some_method
  data = initialize(options)

  data.manipulate!

  data.result
end

def some_method
  result
end
```

## Classes

* Avoid the usage of class (`@@`) variables due to their unusual behavior
in inheritance.

``` ruby
class Parent
  @@class_var = "parent"

  def self.print_class_var
    puts @@class_var
  end
end

class Child < Parent
  @@class_var = "child"
end

Parent.print_class_var # => will print "child"
```

    As you can see all the classes in a class hierarchy actually share one
    class variable. Class instance variables should usually be preferred
    over class variables.

* Use `def self.method` to define singleton methods. This makes the methods
  more resistant to refactoring changes.

``` ruby
class TestClass
  # bad
  def TestClass.some_method
    # body omitted
  end

  # good
  def self.some_other_method
    # body omitted
  end
```

* Avoid `class << self` except when necessary, e.g. single accessors and aliased
  attributes.

``` ruby
class TestClass
  # bad
  class << self
    def first_method
      # body omitted
    end

    def second_method_etc
      # body omitted
    end
  end

  # good
  class << self
    attr_accessor :per_page
    alias_method :nwo, :find_by_name_with_owner
  end

  def self.first_method
    # body omitted
  end

  def self.second_method_etc
    # body omitted
  end
end
```

* Indent the `public`, `protected`, and `private` methods as much the
  method definitions they apply to. Leave one blank line above them.

``` ruby
class SomeClass
  def public_method
    # ...
  end

  private
  def private_method
    # ...
  end
end
```

* Avoid explicit use of `self` as the recipient of internal class or instance
  messages unless to specify a method shadowed by a variable.

``` ruby
class SomeClass
  attr_accessor :message

  def greeting(name)
    message = "Hi #{name}" # local variable in Ruby, not attribute writer
    self.message = message
  end
end
```

## Collections

* Prefer `%w` to the literal array syntax when you need an array of
strings.

``` ruby
# bad
STATES = ["draft", "open", "closed"]

# good
STATES = %w(draft open closed)
```

* Use `Set` instead of `Array` when dealing with unique elements. `Set`
  implements a collection of unordered values with no duplicates. This
  is a hybrid of `Array`'s intuitive inter-operation facilities and
  `Hash`'s fast lookup.

* Use symbols instead of strings as hash keys.

``` ruby
# bad
hash = { "one" => 1, "two" => 2, "three" => 3 }

# good
hash = { one: 1, two: 2, three: 3 }
```

## Documentation

Use [TomDoc](http://tomdoc.org) to the best of your ability. It's pretty sweet:

``` ruby
# Public: Duplicate some text an arbitrary number of times.
#
# text  - The String to be duplicated.
# count - The Integer number of times to duplicate the text.
#
# Examples
#
#   multiplex("Tom", 4)
#   # => "TomTomTomTom"
#
# Returns the duplicated String.
def multiplex(text, count)
  text * count
end
```

## Exceptions

* Don't use exceptions for flow of control.

``` ruby
# bad
begin
  n / d
rescue ZeroDivisionError
  puts "Cannot divide by 0!"
end

# good
if d.zero?
  puts "Cannot divide by 0!"
else
  n / d
end
```

* Rescue specific exceptions, not `StandardError` or its superclasses.

``` ruby
# bad
begin
  # an exception occurs here
rescue
  # exception handling
end

# still bad
begin
  # an exception occurs here
rescue Exception
  # exception handling
end
```

## Hashes

Use the Ruby 1.9 syntax for hash literals when all the keys are symbols:

``` ruby
# good
user = {
  login: "defunkt",
  name: "Chris Wanstrath"
}

# bad
user = {
  :login => "defunkt",
  :name => "Chris Wanstrath"
}

```

Use the 1.9 syntax when calling a method with Hash options arguments or named arguments:

``` ruby
# good
user = User.create(login: "jane")
link_to("Account", controller: "users", action: "show", id: user)

# bad
user = User.create(:login => "jane")
link_to("Account", :controller => "users", :action => "show", :id => user)
```

If you have a hash with mixed key types, use the legacy hashrocket style to avoid mixing styles within the same hash:

``` ruby
# good
hsh = {
  :user_id => 55,
  "followers-count" => 1000
}

# bad
hsh = {
  user_id: 55,
  "followers-count" => 1000
}
```

## Keyword Arguments

[Keyword arguments](http://magazine.rubyist.net/?Ruby200SpecialEn-kwarg) are recommended but not required when a method's arguments may otherwise be opaque or non-obvious when called. Additionally, prefer them over the old "Hash as pseudo-named args" style from pre-2.0 ruby.

So instead of this:
``` ruby
def remove_member(user, skip_membership_check=false)
  # ...
end

# Elsewhere: what does true mean here?
remove_member(user, true)
```

Do this, which is much clearer.
``` ruby
def remove_member(user, skip_membership_check: false)
  # ...
end

# Elsewhere, now with more clarity:
remove_member user, skip_membership_check: true
```

## Naming

* Use `snake_case` for methods and variables.

* Use `CamelCase` for classes and modules.  (Keep acronyms like HTTP,
  RFC, XML uppercase.)

* Use `SCREAMING_SNAKE_CASE` for other constants.

* The names of predicate methods (methods that return a boolean value)
  should end in a question mark. (i.e. `Array#empty?`).

* The names of potentially "dangerous" methods (i.e. methods that modify `self` or the
  arguments, `exit!`, etc.) should end with an exclamation mark. Bang methods
  should only exist if a non-bang method exists. ([More on this](http://dablog.rubypal.com/2007/8/15/bang-methods-or-danger-will-rubyist)).

## Percent Literals

* Use `%w` freely.

``` ruby
STATES = %w(draft open closed)
```

* Use `%()` for single-line strings which require both interpolation
  and embedded double-quotes. For multi-line strings, prefer heredocs.

``` ruby
# bad (no interpolation needed)
%(<div class="text">Some text</div>)
# should be "<div class=\"text\">Some text</div>"

# bad (no double-quotes)
%(This is #{quality} style)
# should be "This is #{quality} style"

# bad (multiple lines)
%(<div>\n<span class="big">#{exclamation}</span>\n</div>)
# should be a heredoc.

# good (requires interpolation, has quotes, single line)
%(<tr><td class="name">#{name}</td>)
```

* Use `%r` only for regular expressions matching *more than* one '/' character.

``` ruby
# bad
%r(\s+)

# still bad
%r(^/(.*)$)
# should be /^\/(.*)$/

# good
%r(^/blog/2011/(.*)$)
```

## Regular Expressions

* Avoid using $1-9 as it can be hard to track what they contain. Named groups
  can be used instead.

``` ruby
# bad
/(regexp)/ =~ string
...
process $1

# good
/(?<meaningful_var>regexp)/ =~ string
...
process meaningful_var
```

* Be careful with `^` and `$` as they match start/end of line, not string endings.
  If you want to match the whole string use: `\A` and `\z`.

``` ruby
string = "some injection\nusername"
string[/^username$/]   # matches
string[/\Ausername\z/] # don't match
```

* Use `x` modifier for complex regexps. This makes them more readable and you
  can add some useful comments. Just be careful as spaces are ignored.

``` ruby
regexp = %r{
  start         # some text
  \s            # white space char
  (group)       # first group
  (?:alt1|alt2) # some alternation
  end
}x
```

## Requires

Always `require` dependencies used directly in a script at the start of the same file.
Resources that will get autoloaded on first use—such as Rails models, controllers, or
helpers—don't need to be required.

``` ruby
require "set"
require "time"

%w(foo bar).to_set
Time.parse("2015-10-21")
```

This not only loads the necessary dependencies if they haven't already, but acts as
documentation about the libraries that the current file uses.

## Strings

* Prefer string interpolation instead of string concatenation:

``` ruby
# bad
email_with_name = user.name + " <" + user.email + ">"

# good
email_with_name = "#{user.name} <#{user.email}>"
```

* Use double-quoted strings. Interpolation and escaped characters
  will always work without a delimiter change, and `'` is a lot more
  common than `"` in string literals.

``` ruby
# bad
name = 'Bozhidar'

# good
name = "Bozhidar"
```

* Avoid using `String#+` when you need to construct large data chunks.
  Instead, use `String#<<`. Concatenation mutates the string instance in-place
  and is always faster than `String#+`, which creates a bunch of new string objects.

``` ruby
# good and also fast
html = ""
html << "<h1>Page title</h1>"

paragraphs.each do |paragraph|
  html << "<p>#{paragraph}</p>"
end
```

## Syntax

* Use `def` with parentheses when there are arguments. Omit the
  parentheses when the method doesn't accept any arguments.

 ``` ruby
 def some_method
   # body omitted
 end

 def some_method_with_arguments(arg1, arg2)
   # body omitted
 end
 ```

* Never use `for`, unless you know exactly why. Most of the time iterators
  should be used instead. `for` is implemented in terms of `each` (so
  you're adding a level of indirection), but with a twist - `for`
  doesn't introduce a new scope (unlike `each`) and variables defined
  in its block will be visible outside it.

``` ruby
arr = [1, 2, 3]

# bad
for elem in arr do
  puts elem
end

# good
arr.each { |elem| puts elem }
```

* Never use `then` for multi-line `if/unless`.

``` ruby
# bad
if some_condition then
  # body omitted
end

# good
if some_condition
  # body omitted
end
```

* Avoid the ternary operator (`?:`) except in cases where all expressions are extremely
  trivial. However, do use the ternary operator(`?:`) over `if/then/else/end` constructs
  for single line conditionals.

``` ruby
# bad
result = if some_condition then something else something_else end

# good
result = some_condition ? something : something_else
```

* Use one expression per branch in a ternary operator. This
  also means that ternary operators must not be nested. Prefer
  `if/else` constructs in these cases.

``` ruby
# bad
some_condition ? (nested_condition ? nested_something : nested_something_else) : something_else

# good
if some_condition
  nested_condition ? nested_something : nested_something_else
else
  something_else
end
```

* The `and` and `or` keywords are banned. It's just not worth it. Always use `&&` and `||` instead.

* Avoid multi-line `?:` (the ternary operator), use `if/unless` instead.

* Favor modifier `if/unless` usage when you have a single-line
  body.

``` ruby
# bad
if some_condition
  do_something
end

# good
do_something if some_condition
```

* Never use `unless` with `else`. Rewrite these with the positive case first.

``` ruby
# bad
unless success?
  puts "failure"
else
  puts "success"
end

# good
if success?
  puts "success"
else
  puts "failure"
end
```

* Don't use parentheses around the condition of an `if/unless/while`.

``` ruby
# bad
if (x > 10)
  # body omitted
end

# good
if x > 10
  # body omitted
end
```

* Prefer `{...}` over `do...end` for single-line blocks.  Avoid using
  `{...}` for multi-line blocks (multiline chaining is always
  ugly). Always use `do...end` for "control flow" and "method
  definitions" (e.g. in Rakefiles and certain DSLs).  Avoid `do...end`
  when chaining.

``` ruby
names = ["Bozhidar", "Steve", "Sarah"]

# good
names.each { |name| puts name }

# bad
names.each do |name|
  puts name
end

# good
names.select { |name| name.start_with?("S") }.map { |name| name.upcase }

# bad
names.select do |name|
  name.start_with?("S")
end.map { |name| name.upcase }
```

    Some will argue that multiline chaining would look OK with the use of {...}, but they should
    ask themselves - is this code really readable and can't the block's contents be extracted into
    nifty methods?

* Avoid `return` where not required.

``` ruby
# bad
def some_method(some_arr)
  return some_arr.size
end

# good
def some_method(some_arr)
  some_arr.size
end
```

* Use spaces around the `=` operator when assigning default values to method parameters:

``` ruby
# bad
def some_method(arg1=:default, arg2=nil, arg3=[])
  # do something...
end

# good
def some_method(arg1 = :default, arg2 = nil, arg3 = [])
  # do something...
end
```

While several Ruby books suggest the first style, the second is much more prominent
in practice (and arguably a bit more readable).

* Using the return value of `=` (an assignment) is ok.

``` ruby
# bad
if (v = array.grep(/foo/)) ...

# good
if v = array.grep(/foo/) ...

# also good - has correct precedence.
if (v = next_value) == "hello" ...
```

* Use `||=` freely to initialize variables.

``` ruby
# set name to Bozhidar, only if it's nil or false
name ||= "Bozhidar"
```

* Don't use `||=` to initialize boolean variables. (Consider what
  would happen if the current value happened to be `false`.)

``` ruby
# bad - would set enabled to true even if it was false
enabled ||= true

# good
enabled = true if enabled.nil?
```

* Avoid using Perl-style special variables (like `$0-9`, `$`,
  etc. ). They are quite cryptic and their use in anything but
  one-liner scripts is discouraged. Prefer long form versions such as
  `$PROGRAM_NAME`.

* Never put a space between a method name and the opening parenthesis.

``` ruby
# bad
f (3 + 2) + 1

# good
f(3 + 2) + 1
```

* If the first argument to a method begins with an open parenthesis,
  always use parentheses in the method invocation. For example, write
`f((3 + 2) + 1)`.

* Use `_` for unused block parameters.

``` ruby
# bad
result = hash.map { |k, v| v + 1 }

# good
result = hash.map { |_, v| v + 1 }
```

* Don't use the `===` (threequals) operator to check types. `===` is mostly an
  implementation detail to support Ruby features like `case`, and it's not commutative.
  For example, `String === "hi"` is true and `"hi" === String` is false.
  Instead, use `is_a?` or `kind_of?` if you must.

  Refactoring is even better. It's worth looking hard at any code that explicitly checks types.


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
