#!/bin/bash
echo "Current File Name: $0"    # $0 Stores the first word of the entered command (the name of the shell program)
echo "Process number of current Shell: $$"    # $$ Expands to the decimal process ID of the invoked shell
echo "Process Number of last background command: $!"   # $! Expands to the decimal process ID of the most recent background command executed from the current shell.
echo "Exit ID of last executed command: $?"   # $? Stores the exit value of the last command that was executed.
