#!/bin/bash
i=1; #initialize variable to 1
for (( ; ; )) #infinite loop
do
	echo "$i"
	i=$(($i+1))
	if [ $i -eq 10 ]
	then
		break;
	fi
done
