import java.util.*;
public class Main
{
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		int indexI,indexJ,k,product=1,number,totalNumbers,sum=0;
		totalNumbers=sc.nextInt();
		int numbers[]=new int[totalNumbers];
		int remainders[]=new int[totalNumbers];
		int finalProduct[]=new int[totalNumbers];
		int inverseModulo[]=new int[totalNumbers];
		
		
		for(indexI=0;indexI<totalNumbers;indexI++)
		{
		    numbers[indexI]=sc.nextInt();
		    product=product*numbers[indexI];
		}
		
		
		for(indexI=0;indexI<totalNumbers;indexI++)
		{
		    remainders[indexI]=sc.nextInt();
		}
		
		
		for(indexI=0;indexI<totalNumbers;indexI++)
		{
		    finalProduct[indexI]=product/numbers[indexI];
		    indexJ=1;
		    while((finalProduct[indexI]*indexJ)%numbers[indexI]!=1)
		    indexJ++;
		    inverseModulo[indexI]=indexJ;
		    sum=sum+finalProduct[indexI]*inverseModulo[indexI]*remainders[indexI];
		}
		
		System.out.println((sum%product));
		
	}
}

/*
Input:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}
Output: 11
*/
