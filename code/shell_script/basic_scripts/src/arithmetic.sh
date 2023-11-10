#!/bin/bash
echo "Arithmetic Operations on Shell";
read -p "Enter an Real value: " val1
read -p "Enter another Real value: " val2
echo "Addition: $(($val1+$val2))"
echo "Subtraction: $(($val1-$val2))"
echo "Multiplication: $(($val1*$val2))"
div=$(($val1/$val2))
echo "Division: ${div}"
