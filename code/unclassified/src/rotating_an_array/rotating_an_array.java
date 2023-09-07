import java.io.*;
import java.util.*;
// Part of Cosmos by OpenGenus Foundation
//Rotating an array given array size n and a number k
//example 1 3 2 4 5 when rotated with k=2 forms 4 5 1 3 2 
public class Main{
    public static void main(String[] args){
      Scanner scn = new Scanner(System.in);
      int n1 = scn.nextInt();
      int[] arr1=new int[n1];                                             
      for(int i=0;i<arr1.length;i++)
      {
          arr1[i]= scn.nextInt();
      }
      int k = scn.nextInt();
      rotate(arr1,k);
      display(arr1);
    }
    
public static void rotate(int a1[],int k)
{
    k=k%a1.length;
    if(k<0)
    {
        k=k+a1.length;
    }
    reverse(a1,0,a1.length-1-k);
    reverse(a1,a1.length-k,a1.length-1);
    reverse(a1,0,a1.length-1);
}
    
  public static void reverse(int a1[],int start,int end)
  {
      int temp=0;
              while(end>start)
              {
                  temp=a1[end];
                  a1[end]=a1[start];
                  a1[start]=temp;                           
                  
                  end--;
                  start++;
                  
              }
  }
              
     public static void display(int a1[])
  {
     for(int i=0;i<a1.length;i++)
     {
         System.out.print(a1[i]+" ");
     }
                  
              }
              

  
}
