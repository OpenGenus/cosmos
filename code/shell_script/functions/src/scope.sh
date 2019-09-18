#!/bin/bash
# Declaring a global variable
gvar="I am the global variable!!!"

# Define a function
function1()
{	
	# Declaring a local variable
	lvar="I am the local variable"
	echo "$gvar"
	echo "$lvar"
}

# Call the function
function1
