#!/bin/bash
# Lomuto partition scheme.
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

partition() { #lo is $1, hi is $2
    pivot=${array[$2]}
    i=$(($1-1))
    j=$1
    while [ $j -lt $2 ]; do
	if [ ${array[$j]} -lt $pivot ]; then
	    i=$((i+1))
	    tmp=${array[$i]}
	    array[$i]=${array[$j]}
	    array[$j]=$tmp
	fi
	j=$((j+1))
    done
    if [ ${array[$2]} -lt ${array[$((i+1))]} ]; then
	tmp=${array[$((i+1))]}
	array[$((i+1))]=${array[$2]}
	array[$2]=$tmp
    fi
    partition_ret=$((i+1))
}

quicksort() { #lo is $1, hi is $2
    if [ $1 -lt $2 ]; then
	partition $1 $2
	local pret=$partition_ret
	quicksort $1 $((pret - 1))
	quicksort $((pret + 1)) $2
    fi
}

create_array
print_array

quicksort 0 $((ARRAYSZ-1))

echo
print_array
verify_sort
