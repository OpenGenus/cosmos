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
# Call multiplication for 3 and 4 == 12
multiply 3 4
# Call Addition for 5 and 4 == 9
add 5 4
# Store answer (always stores final function call returned value)
ans=$?
echo "$ans"

