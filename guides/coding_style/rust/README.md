# Cosmos Guides
> Your personal library of every algorithm and data structure code that you will ever encounter

# Rust Style Guide
([Source](https://github.com/rust-lang/rust-guidelines))

### Opening braces always go on the same line.

``` rust
fn foo() {
    ...
}

fn frobnicate(a: Bar, b: Bar,
              c: Bar, d: Bar)
              -> Bar {
    ...
}

trait Bar {
    fn baz(&self);
}

impl Bar for Baz {
    fn baz(&self) {
        ...
    }
}

frob(|x| {
    x.transpose()
})
```

### `match` arms get braces, except for single-line expressions.

``` rust
match foo {
    bar => baz,
    quux => {
        do_something();
        do_something_else()
    }
}
```

### `return` statements get semicolons.

``` rust
fn foo() {
    do_something();

    if condition() {
        return;
    }

    do_something_else();
}
```

### Trailing commas
A trailing comma should be included whenever the
closing delimiter appears on a separate line:

```rust
Foo { bar: 0, baz: 1 }

Foo {
    bar: 0,
    baz: 1,
}

match a_thing {
    None => 0,
    Some(x) => 1,
}
```

### Avoid block comments.

Use line comments:

``` rust
// Wait for the main task to return, and set the process error code
// appropriately.
```

Instead of:

``` rust
/*
 * Wait for the main task to return, and set the process error code
 * appropriately.
 */
```

## Doc comments

Doc comments are prefixed by three slashes (`///`) and indicate
documentation that you would like to be included in Rustdoc's output.
They support
[Markdown syntax](https://en.wikipedia.org/wiki/Markdown)
and are the main way of documenting your public APIs.

The supported markdown syntax includes all of the extensions listed in the
[GitHub Flavored Markdown]
(https://help.github.com/articles/github-flavored-markdown) documentation,
plus superscripts.

### Summary line

The first line in any doc comment should be a single-line short sentence
providing a summary of the code. This line is used as a short summary
description throughout Rustdoc's output, so it's a good idea to keep it
short.

### Sentence structure

All doc comments, including the summary line, should begin with a
capital letter and end with a period, question mark, or exclamation
point. Prefer full sentences to fragments.

The summary line should be written in
[third person singular present indicative form]
(http://en.wikipedia.org/wiki/English_verbs#Third_person_singular_present).
Basically, this means write "Returns" instead of "Return".

For example:

``` rust
/// Sets up a default runtime configuration, given compiler-supplied arguments.
///
/// This function will block until the entire pool of M:N schedulers has
/// exited. This function also requires a local task to be available.
///
/// # Arguments
///
/// * `argc` & `argv` - The argument vector. On Unix this information is used
///                     by `os::args`.
/// * `main` - The initial procedure to run inside of the M:N scheduling pool.
///            Once this procedure exits, the scheduling pool will begin to shut
///            down. The entire pool (and this function) will only return once
///            all child tasks have finished executing.
///
/// # Return value
///
/// The return value is used as the process return code. 0 on success, 101 on
/// error.
```

### Avoid inner doc comments.

Use inner doc comments _only_ to document crates and file-level modules:

``` rust
//! The core library.
//!
//! The core library is a something something...
```

% Imports

The imports of a crate/module should consist of the following
sections, in order, with a blank space between each:

* `extern crate` directives
* external `use` imports
* local `use` imports
* `pub use` imports

For example:

```rust
// Crates.
extern crate getopts;
extern crate mylib;

// Standard library imports.
use getopts::{optopt, getopts};
use std::os;

// Import from a library that we wrote.
use mylib::webserver;

// Will be reexported when we import this module.
pub use self::types::Webdata;
```

### Avoid `use *`, except in tests.

Glob imports have several downsides:
* They make it harder to tell where names are bound.
* They are forwards-incompatible, since new upstream exports can clash
  with existing names.

When writing a [`test` submodule](../testing/README.md), importing `super::*` is appropriate
as a convenience.

### Prefer fully importing types/traits while module-qualifying functions.

For example:

```rust
use option::Option;
use mem;

let i: int = mem::transmute(Option(0));
```

% Whitespace [FIXME: needs RFC]

* Lines must not exceed 99 characters.
* Use 4 spaces for indentation, _not_ tabs.
* No trailing whitespace at the end of lines or files.

### Spaces

* Use spaces around binary operators, including the equals sign in attributes:

``` rust
#[deprecated = "Use `bar` instead."]
fn foo(a: uint, b: uint) -> uint {
    a + b
}
```

* Use a space after colons and commas:

``` rust
fn foo(a: Bar);

MyStruct { foo: 3, bar: 4 }

foo(bar, baz);
```

* Use a space after the opening and before the closing brace for
  single line blocks or `struct` expressions:

``` rust
spawn(proc() { do_something(); })

Point { x: 0.1, y: 0.3 }
```

### Line wrapping

* For multiline function signatures, each new line should align with the
  first parameter. Multiple parameters per line are permitted:

``` rust
fn frobnicate(a: Bar, b: Bar,
              c: Bar, d: Bar)
              -> Bar {
    ...
}

fn foo<T: This,
       U: That>(
       a: Bar,
       b: Bar)
       -> Baz {
    ...
}
```

* Multiline function invocations generally follow the same rule as for
  signatures. However, if the final argument begins a new block, the
  contents of the block may begin on a new line, indented one level:

``` rust
fn foo_bar(a: Bar, b: Bar,
           c: |Bar|) -> Bar {
    ...
}

// Same line is fine:
foo_bar(x, y, |z| { z.transpose(y) });

// Indented body on new line is also fine:
foo_bar(x, y, |z| {
    z.quux();
    z.rotate(x)
})
```

### Alignment

Idiomatic code should not use extra whitespace in the middle of a line
to provide alignment.


``` rust
// Good
struct Foo {
    short: f64,
    really_long: f64,
}

// Bad
struct Bar {
    short:       f64,
    really_long: f64,
}

// Good
let a = 0;
let radius = 7;

// Bad
let b        = 0;
let diameter = 7;
```


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
