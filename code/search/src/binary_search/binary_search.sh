#!/bin/bash
#read Limit
echo Enter array limit
read limit

#read Elements
echo Enter elements
n=1
while [ $n -le $limit ]
do
	read num
	eval arr$n=$num
	n=`expr $n + 1`
done

#read Search Key Element
echo Enter key element
read key
low=1
high=$n
found=0
#Find middle element
#for(( low=0,found=0,high=$((n-1)) ; l<=u ; ))
while [ $found -eq 0 -a $high -gt $low ]
do
	mid=`expr \( $low + $high \) / 2`
	eval t=\$arr$mid
	if [ $key -eq $t ] #Compare the value of the middle element with the target value. MATCH
	then
		found=1
	elif [ $key -lt $t ] #Compare the value of the middle element with the target value. LESS
	then
		high=`expr $mid - 1`
	else
		low=`expr $mid + 1` #Compare the value of the middle element with the target value. GREATER
	fi
done # Repeat

if [ $found -eq 0 ]
then
	echo Unsuccessfull search
else
	echo Successfull search
fi
