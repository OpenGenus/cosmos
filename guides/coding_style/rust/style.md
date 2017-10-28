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

Avoid block comments.

Use line comments:

// Wait for the main task to return, and set the process error code
// appropriately.

Instead of:

/*
 * Wait for the main task to return, and set the process error code
 * appropriately.
 */

Doc comments

Doc comments are prefixed by three slashes (///) and indicate documentation that you would like to be included in Rustdoc's output. They support Markdown syntax and are the main way of documenting your public APIs.

The supported markdown syntax includes all of the extensions listed in the [GitHub Flavored Markdown] (https://help.github.com/articles/github-flavored-markdown) documentation, plus superscripts.
Summary line

The first line in any doc comment should be a single-line short sentence providing a summary of the code. This line is used as a short summary description throughout Rustdoc's output, so it's a good idea to keep it short.
Sentence structure

All doc comments, including the summary line, should begin with a capital letter and end with a period, question mark, or exclamation point. Prefer full sentences to fragments.

The summary line should be written in [third person singular present indicative form] (http://en.wikipedia.org/wiki/English_verbs#Third_person_singular_present). Basically, this means write "Returns" instead of "Return".

For example:

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

Code snippets

Avoid inner doc comments.

Use inner doc comments only to document crates and file-level modules:

//! The core library.
//!
//! The core library is a something something...