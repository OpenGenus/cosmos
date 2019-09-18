#!/bin/bash
echo "Nested functions"

# First function
function1()
{
	echo "Function 1 body"
	function2;
}

# Second function
function2()
{
	echo "Function 2 body"
}

function1

