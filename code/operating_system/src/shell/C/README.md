# Implement a Shell in C

The Shell include some feature as follows,
1. It is able to run all the single-process commands.
2. It is able to run all the two-process pipelines.
3. It is able to handle input and output redirection.
4. It is able to execute commands in the background.

## How to work - Using Makefile
First step: make clean
Second step: make all
Last step: ./Shell

## Note
"cd" is not a built-in command !
So I need to build a "cd" function and use system call "chdir" to implement "cd"

You are, of course, free to add more features to the shell. 