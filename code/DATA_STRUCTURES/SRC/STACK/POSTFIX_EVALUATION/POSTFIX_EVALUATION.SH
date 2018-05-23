#!/bin/bash
#Read the Expression


read -p "Enter The Exppression " EX


#Here q variable will act as top pointer in stack pointing to topmost element

q=-1

#cnt variable will count so that we an read each character

cnt=1

#Here re is the variable for regular expression check 


 
re='^-?[0-9]+([.][0-9]+)?$'


#function to make required calculations
function calculate(){
	upr=${arr[q]}
	k=$[$q-1]
	lwr=${arr[k]}
	res=$[$lwr $c $upr]
	arr[k]=$res
	q=$k
}

#Here The operations are performed

while :
do
c=`echo "$EX"|cut -d " " -f "$cnt"`

#Here check if length of c is nonzero


if [[ -n $c ]]
then

#Here c is checked if not a number

if ! [[ $c =~ $re ]]
then
	calculate          #This is a function defined Above 
else
	q=$[$q+1]
	arr[q]=$c
fi
else
break
fi
cnt=$[$cnt+1]
done
echo -e "Result of Expression is ${arr[0]}\n"






