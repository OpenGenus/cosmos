#!/bin/bash
read -p "ENter the IPv4 address " IP
for i in `seq 1 4`
do
arr[i]=`echo "$IP"|cut -d "." -f "$i"`
done
for i in `seq 1 4`
do
	a=${arr[i]}
	case "$a" in
			[0-255])
				flag=1
				;;
			*)
				flag=0
				;;
			esac
done
if [[ "$flag" -eq 1 ]]
then
echo "Valid IP"
else
echo "Invalid IP"
fi
