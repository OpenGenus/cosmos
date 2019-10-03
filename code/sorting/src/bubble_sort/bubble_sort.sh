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

bubble_sort() {
    while true; do
	did_swap=0
	i=1
	while [ $i -lt $ARRAYSZ ]; do
	    if [ ${array[$((i-1))]} -gt ${array[$i]} ]; then
		tmp=${array[$((i-1))]}
		array[$((i-1))]=${array[$i]}
		array[$i]=$tmp;
		did_swap=1
	    fi
	    i=$((i+1))
	done
	if [ $did_swap -eq 0 ]; then
	    break
	fi
    done	
}

create_array
print_array

bubble_sort
echo
print_array
verify_sort
