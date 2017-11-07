import java.util.*;
/*
	@author Kanika Saini (https://github.com/kanikasaini)
*/
class ReverseIntUsingRecursion
{
public static void main(String[] args) throws Exception
{
	int reversed= reverse(1234);
	System.out.println(sum); //prints 4321
}
static int sum=0;
public static int reverse(int num)
{	
	if (num!=0)
	{
		int r = num%10;
		sum = sum*10 + r;
		reverse(num/10);
	}	
	return sum;
}
}
