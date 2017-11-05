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