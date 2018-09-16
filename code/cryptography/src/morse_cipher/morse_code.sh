#!/bin/bash
#get the file and be ready to decrypt one time internet file download is required




pwd=$PWD
#check if file doesnt exist
if ! [[ -f "$pwd/morse_code.txt" ]]
then
curl http://www.qsl.net/we6w/text/morse.txt >> morse.txt 2>/dev/null
sed -i '17,367d' morse.txt
cat morse.txt|grep -vi morse > morse_code.txt
rm -f morse.txt
fi



#function to encrypt the msg




function encrypt(){
col1=`cat morse_code.txt|awk '{print $1,$2}'`
col2=`cat morse_code.txt|awk '{print $3,$4}'`
col3=`cat morse_code.txt|awk '{print $5,$6}'`
col4=`cat morse_code.txt|awk '{print $7,$8}'`
while read -n1 char
do
echo "$col1"|grep -i $char 2>/dev/null
echo "$col2"|grep -i $char 2>/dev/null
echo "$col3"|grep -i $char 2> /dev/null
echo "$col4"|grep -i $char 2> /dev/null
done<$pwd/msg.txt
}


#Program begins

read -p "Enter The Message    " MS
echo "$MS" > $pwd/msg.txt
encrypt
rm -f $pwd/msg.txt
