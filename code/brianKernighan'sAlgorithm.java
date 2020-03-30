import java.util.*;
public class Main
{  static int countSetBits(int n)
   {   
       if(n==0)
       return 0;
       else 
       return 1+countSetBits(n&(n-1));
   }
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		int number,count=0;
		 number=sc.nextInt();
		 System.out.println(countSetBits(number));
	}
}
/*
Input - number=9
Output - 2 */
