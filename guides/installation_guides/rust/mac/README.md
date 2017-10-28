([Source](https://doc.rust-lang.org/book/second-edition/ch01-01-installation.html))

## Installing on Linux or Mac

If you’re on Linux or a Mac, all you need to do is open a terminal and type this:

```
$ curl https://sh.rustup.rs -sSf | sh
```

This will download a script and start the installation. You may be prompted for your password. If it all goes well, you’ll see this appear:

Rust is installed now. Great!

Of course, if you disapprove of the curl | sh pattern, you can download, inspect and run the script however you like.

The installation script automatically adds Rust to your system PATH after your next login. If you want to start using Rust right away, run the following command in your shell:

```
$ source $HOME/.cargo/env
```

Alternatively, add the following line to your ~/.bash_profile:

```
$ export PATH="$HOME/.cargo/bin:$PATH"
```

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