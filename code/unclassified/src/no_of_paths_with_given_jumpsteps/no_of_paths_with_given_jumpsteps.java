import java.io.*;
import java.util.*;

public class Main {
    static int k; //stands for the maximum jump across the steps
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        System.out.println("enter no of steps");
        int n=scn.nextInt();
        System.out.println("enter maximum jump that can be made across steps");
        k=scn.nextInt();
        if(k<=n)
        {
        gts(n,""); //gts is short for get total steps
        }

    }
    public static void gts(int n,String ans) {
     
        if(n==0) //base case
        {
            System.out.println(ans);
            return;
        }
        if(n<0)
        {
          return;
      }

for(int i=1;i<=k;i++)
{
       gts(n-i,ans+String.valueOf(i));
}
      
}
}
