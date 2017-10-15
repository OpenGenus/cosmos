#!/bin/bash
# Part of Cosmos by OpenGenus Foundation
declare -a array
ARRAYSZ=10

create_array() {
    i=0
    while [ $i -lt $ARRAYSZ ]; do
	array[${i}]=${RANDOM}
	i=$((i+1))
    done
}

print_array() {
    i=0
    while [ $i -lt $ARRAYSZ ]; do
	echo ${array[${i}]}
	i=$((i+1))
    done
}

verify_sort() {
    i=1
    while [ $i -lt $ARRAYSZ ]; do
	if [ ${array[$i]} -lt ${array[$((i-1))]} ]; then
	    echo "Array did not sort, see elements $((i-1)) and $i."
	    exit 1
	fi
	i=$((i+1))
    done
    echo "Array sorted correctly."
}

insertion_sort() {
    i=1
    while [ $i -lt ${ARRAYSZ} ]; do
	j=$i
	while [ $j -gt 0 ] && [ ${array[$((j-1))]} -gt ${array[$j]} ]; do
	    tmp=${array[$((j-1))]}
	    array[$((j-1))]=${array[$j]}
	    array[$j]=$tmp;
	    j=$((j-1))
	done
	i=$((i+1))
    done
}

create_array
print_array

insertion_sort
echo
print_array
verify_sort
