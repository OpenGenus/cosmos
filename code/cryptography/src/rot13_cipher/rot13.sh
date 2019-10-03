#!/bin/sh

# Run rot13 on a string
rot13()
{
    str=$1
    result=$(echo -n "$str" | tr '[A-Za-z]' '[N-ZA-Mn-za-m]')
    echo $result
}

# Example
# $ ./rot13.sh "Hello world!"
# $ Uryyb jbeyq!

if [ "$#" -ne 1 ] ; then
    echo "Usage: $0 <string>"
    exit 1
fi

rot13 "$1"
