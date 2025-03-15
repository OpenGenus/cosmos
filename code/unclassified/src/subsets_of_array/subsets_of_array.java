import java.io.*;
import java.util.*;
// Part of Cosmos by OpenGenus Foundation
public class Main{
  public static void main(String[] args) {
      Scanner scn = new Scanner(System.in);
      int n = scn.nextInt();
   
      int[] arr1=new int[n];  
      for(int i=0;i<arr1.length;i++)
             {
                 arr1[i]= scn.nextInt();
             }
     int t= (int) Math.pow(2,n);
    for(int i=0;i<t;i++)
    {
      int dn = getValueInBase(i, 2);
      int div=(int) Math.pow(10,arr1.length-1);
          for(int j=0;j<arr1.length;j++)
          {
                int dig=dn/div;
                if(dig==0)
                {
                    System.out.print("-	");
                }
                else
                {
                    System.out.print(arr1[j]+"	");
                }
                dn=dn%div;
                div=div/10;
        
          }
          System.out.println();
   
    }
  }
  
   public static int getValueInBase(int n, int b)
   {
       int count=0;
       int dig;
       int sum=0;
       while(n!=0)
       {
           dig=n%b;
           dig=dig*(int) Math.pow(10,count);
           sum=sum+dig;
           count++;
           n=n/b;
       }
       return sum;
  }
}
