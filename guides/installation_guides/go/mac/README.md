# Go Installation Guide

### Install Go

`brew install go`


### Create Go Directories

`mkdir $HOME/Go`
`mkdir -p $HOME/Go/src/github.com/<username>` (This is the directory where you should create your Go projects.)


### Setup Go paths

`export GOPATH=$HOME/Go`
`export GOROOT=/usr/local/opt/go/libexec`
`export PATH=$PATH:$GOPATH/bin`
`export PATH=$PATH:$GOROOT/bin`


### Get the Go Document (optional)

`go get golang.org/x/tools/cmd/godoc`


### Additional Go Resources

[How to Write Go Code](https://golang.org/doc/code.html)
[How I Start Go tutorial](http://howistart.org/posts/go/1/index.html)
[Learn X in Y minutes](https://learnxinyminutes.com/docs/go/)

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
