#!/bin/bash
echo -e "please press 'SPACEBAR' and not 'ENTER' after each input\n"
read -p "Enter The numbers " NM
#Here 'sum' is the sum of numbers 'len' is the length of the integer string inserted 'count' is the count of numbers in integer string
sum=0
len=`echo ${#NM}`
i=1
size=0
count=0
##########################################################################################################

#A loop to read each number add it to 'sum' and increment count simultaneously


while [ "$size" -lt "$len" ]
do 
	a=`echo "$NM"|cut -d " " -f $i`
	if [[ -z "$a" ]]
	then
		if [[ "$i" -eq 1 ]]
		then
			echo -e "ENter The numbers again no element on position $i\n"
		else
			i=$[$i+1]
			size=$[$size+1]
		fi
	else
		sum=$[$sum+$a]
		count=$[$count+1]
		la=`echo "${#a}"`
		size=$[$size+$la]
		i=$[$i+1]
	fi
done
##########################################################################################################


#calculate the average and print the result

res=`echo "scale=2;$sum/$count"|bc`
echo -e "Avergae is $res\n"
##########################################################################################################
