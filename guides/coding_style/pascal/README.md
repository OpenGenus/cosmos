# Cosmos Guides
> Your personal library of every algorithm and data structure code that you will ever encounter

# Pascal Coding Style

[Pascal](https://en.wikipedia.org/wiki/Pascal_\(programming_language\)) is a general-purpose compiled procedural programming language created in 1970 by [Niklaus Wirth](https://en.wikipedia.org/wiki/Niklaus_Wirth) as a consequence of his ALGOL project. The language lives on in various implementations, most notably the [Free Pascal](https://wiki.freepascal.org/Main_Page) compiler. Python was partly inspired by Pascal.

## Keywords

Write all keywords in `silent_snake_case`. You do not need to scream or shout.

## Spaces

Don't use spaces around operators, colons, parentheses, variable lists, etc.

```pascal
{ correct }
a:=a+b;
a:=(a+b)*c;
{ incorrect }
a := a + b ;
a := ( a + b ) * c ;

{ correct }
var
  a,b,c : int;
{ incorrect }
var
  a, b, c : int ;

{ correct }
function do_something(a: int, var b: int): int;
{ incorrect }
function DO_SOMETHING( a : int, var b : int ) : int ;  { shouldn't shout, superfluous spaces }
```

## Blocks

For any blocks, always move the `begin` and `end` keywords onto the next line indented to the same next level.

```pascal
{ correct }
if true then
  begin
  { ... }
  end;

{ incorrect }
if true then begin
  { ... }
  end;

if true then begin { ... } end;
```

## Indentation

**DO NOT USE TABS**.

There is no standard tab size, resulting in inconsistent and chaotic viewing in editors. Indentation size is always _2 spaces_ wide for each level. Think Python, all sections within a block are indented to the same level, and each block increases the indentation level. Classes are an exception to this rule though.

### Classes (Exception)

As mentioned, classes do not follow the same indentation rules as all other blocks (at least not exactly). In the case of classes, sections are indented at the same level as the class name definition, rather than being indented up a level.

```pascal
node = class(node)
protected
  x : int;
public
  t
end;
```

## Newlines

Put 2 blank lines between any procedures, functions, and the like. Think Python spacing: 2 blank lines for procedure/funciton/object/data definitions, and 1 blank line between anything nested inside those.

```pascal
{ spacing within a function/procedure }
procedure do_nothing;
  { note indentation consistency }
  var
    x,y: int;
  
  function do_little: boolean;
    begin
      result:=true;
    end;
  
  procedure do_nothing_either;
  begin
  end;
  
  begin
  end;


{ spacing between one function/procedure and the next }
procedure do_something;
begin
  writeln('Hello, World!');
end;
```

### Note on functions

Do not use the function name as the return variable, but instead use `result`.

```pascal
{ correct }
function knight: boolean;
  begin
    result:=true;
  end;

{ incorrect }
function knave: boolean;
  begin
    knave:=false;
  end;
```

## Comments

Comments should use `{}`s, be lower case, and have spaces on both sides.

```pascal
{ this is a correct comment }

{this is not}
{ THIS IS NOT }
(* this is not *)
```

## If-Else

The `else` at the end of a consecutive chain of `if`s is not indented.

```pascal
if cond then
  { ... }
else if cond then
    { ... }
else if cond then
    { ... }
else
    { ... }
```

## Final Note

Like most of Wirth's other languages, things are flexible and left up to your best judgement if not otherwise specified. That's part of the joys of Pascal!

For more information, and to see examples of what this would look like in practice, check out [this link](https://wiki.freepascal.org/Coding_style#FCL).

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
