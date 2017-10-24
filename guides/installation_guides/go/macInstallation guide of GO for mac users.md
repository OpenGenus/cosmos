# Cosmos Guides
> Your personal library of every algorithm and data structure code that you will ever encounter


---
## Installing Go on Mac OS x

#### Easiest way to do this is by using Homebrew.
#### You can install homebrew using terminal by:

```$ ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" ```

#### After this, all you need to do is to install Go and it has to be able to crosscompile.

```$ brew install go --cross-compile-common ```

#### Now Go is installed on your Mac but you need to do a few more things.
#### So, all your Go code will live inside a workplace by convention hence we need to tell Go where we want this workspace to be. So we’ll #### create a folder named “Go” in home directory and set environment to use this location.

```$ mkdir $HOME/Go
$ export GOPATH=$HOME/Go 
```

#### If we restart our machine now, Go wouldn’t be able to find this workplace so we’ll set an export.

```$ open $HOME/.bash_profile
export GOPATH=$HOME/Go
export PATH=$PATH:$GOPATH/bin 
```

#### These last few steps will ensure Go workspace will always be set.

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
