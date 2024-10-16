# Implement a Shell in C

The Shell include some feature as follows,
1. It is able to run all the single-process commands.
2. It is able to run all the two-process pipelines.
3. It is able to handle input and output redirection.
4. It is able to execute commands in the background.


## What is a Makefile
A makefile is a file containing a set of directives used by a make build automation tool to generate a target/goal. This is convenient when working with multiple C files and header files.

## How to make this work - Using the Makefile
First step: make clean
Second step: make all
Last step: ./Shell

## Note
"cd" is **not** a built-in command, so you need to build a "cd" function and use system call "chdir" to implement "cd".

##
You are, of course, free and encouraged to add more features to the shell. 
