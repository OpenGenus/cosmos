#sleep sort in shell script only for positive numbers
# Part of Cosmos by OpenGenus Foundation
function f(){
	sleep "$1"
	echo "$1"
}
while [ -n "$1" ]
do
	f "$1" &
	shift
done
wait 
