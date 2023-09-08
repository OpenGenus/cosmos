factorial ()  
{
local number=$1
if [ $number -eq 0 ]
then
    Factorial=1
else
    let "next = number - 1"
    factorial $next
    Factorial=`echo $number \* $Factorial | bc`
#   let "Factorial = $number * $Factorial"
fi
return $Factorial 2>/dev/null
}
