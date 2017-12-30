#!/bin/bash

#Function to start the Program


function start(){
echo -e "\t\t1.[E]nter in Queue"
echo -e "\t\t2. [D]elete from Queue"
echo -e "\t\t3. [T]erminate the Program"
read OP
}



# Function to Insert Values Into Queue


function insert(){
read -p "How many Elements would you like to Enter " NM
for ((a=0;$a<$NM;a++))
do
	read -p "Enter The value : " arr[$a]
done
echo -e "New Queue is ${arr[@]}\n"
}


#Function to Delete Values From Queue
#Here arr is one stack and arr2 is another stack

function delete(){
read -p "How Many Elements to be Deleted : " ED
c=`echo "${arr[@]}"`
int=`echo "${#arr[@]}"`
int=$[$int -1]
if [[ -z "$c" ]]
then
echo -e "Queue is Empty\n"
fi
if [[ "$ED" -gt "$int" ]]
then
echo -e "The Number of Elements to be Deleted is Greater than the Number of elements in Queue\n"
else
if [[ -n "$c" ]]
then
ed=$[$int-$ED]
q=0
while [ $ed -ne 0 ]
do
arr2[q]=`echo "${arr[$int]}"`
q=$[$q+1]
int=$[$int-1]
ed=$[$ed-1]
done
for((i=0;$i<=$int;i++))
do
echo -e "Delete Elements are ${arr[$i]}\n"
unset arr[$i]
done
echo -e "New Queue ${arr2[@]}\n "
else
echo -e "Empty Queue\n"
fi
fi
}
while :
do
start
case $OP in
"E"|"e")
	clear
	insert
;;
"D"|"d") 
	clear
	delete
;;
"T"|"t")
	clear
	break
;;
*)
clear
echo -e "Please Choose Again\nEnter The First Letter of each Choice that is either 'E','D' or 'T'\n"
;;
esac	
done
