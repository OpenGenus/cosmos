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

selection_sort() {
    i=0
    while [ $i -lt $((ARRAYSZ-1)) ]; do
	minIdx=$i
	for j in $( seq $((i+1)) $((ARRAYSZ-1)) ); do
	    if [ ${array[$minIdx]} -gt ${array[$j]} ]; then
		minIdx=$j
	    fi
	done
	if [ $minIdx -ne $i ]; then
	    tmp=${array[$minIdx]}
	    array[$minIdx]=${array[$i]}
	    array[$i]=$tmp
	fi
	i=$((i+1))
    done
}

create_array
print_array

selection_sort
echo
print_array
verify_sort
