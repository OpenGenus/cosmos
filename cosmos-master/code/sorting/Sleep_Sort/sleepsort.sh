#sleep sort in shell script only for positive numbers
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
