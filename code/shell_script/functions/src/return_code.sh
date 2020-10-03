#!/bin/bash
function1()
{
	return $(($1*$2))
}
echo "Multiplication in Shell using Functions"
echo "Enter two numbers"
read num1
read num2
function1 $num1 $num2
mul=$?
echo "Multiplied value is $mul"
