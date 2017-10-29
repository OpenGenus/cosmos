([Source](https://doc.rust-lang.org/book/second-edition/ch01-01-installation.html))

## Installing on Windows

On Windows, go to https://rustup.rs and follow the instructions to download rustup-init.exe. Run that and follow the rest of the instructions it gives you.

The rest of the Windows-specific commands in the book will assume that you are using cmd as your shell. If you use a different shell, you may be able to run the same commands that Linux and Mac users do. If neither work, consult the documentation for the shell you are using.
Custom installations

If you have reasons for preferring not to use rustup.rs, please see the Rust installation page for other options.

## Updating

Once you have Rust installed, updating to the latest version is easy. From your shell, run the update script:

```
$ rustup update
```

## Uninstalling

Uninstalling Rust is as easy as installing it. From your shell, run the uninstall script:

```
$ rustup self uninstall
```