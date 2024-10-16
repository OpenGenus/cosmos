#!/bin/bash

add()
{
	return $(($1+$2))
}
multiply()
{
	return $(($1*$2))
}
# Call Addition for 3 and 4 == 7
add 3 4
echo "$?"

# Call multiplication for 3 and 4 == 12
multiply 3 4
echo "$?"

# Call Addition for 5 and 4 == 9
add 5 4
echo "$?"

