/*
A positive integer is called a palindrome if its representation in the decimal system is the same when read from left to right and from right to left. For a given positive integer K of not more than 1000000 digits, write the value of the smallest palindrome larger than K to output. Numbers are always displayed without leading zeros.

Input
The first line contains integer t, the number of test cases. Followed by t lines containing integers K.

Output
For each K, output the smallest palindrome larger than K.

Example
Input:
2
808
2133
Output:
818
2222
*/

import java.util.*;

class Test {
    public static void main(String arg[]) throws java.lang.Exception {
        Scanner s = new Scanner(System.in);
        int t, n, i;
        t = s.nextInt();
        String str = s.nextLine();
        while(t-->0)
        {
            str = s.nextLine().trim();
            char a[] = str.toCharArray();
            int b[] = new int[a.length];
            for(i=0; i<a.length; i++)
            {
                b[i] = (int)a[i]-48;
            }
            int ans[] = palindrom(b);
            for(i=0; i<ans.length; i++)
            {
                System.out.print(ans[i]+"");
            }
            System.out.println();
        }
    }
    
    public static int [] palindrom (int a[])
    {
        int i, j, n;
        n = a.length;
        if(n%2==0)
        {
            j=n/2;
            i=j-1;
        }
        else
        {
            j=(n/2)+1;
            i=(n/2)-1;
        }
        while(i>=0 && j<n && a[i]==a[j])
        {
            i--;
            j++;
        }
        
        if(i==-1 && j==n)
        {
            if(n%2==0)
            {
                j=(n/2);
                i=j-1;
            }
            else
            {
                j=(n/2);
                i=(n/2);
            }
            
            int c=1;
            while(c!=0 && i>=0 && j<n)
            {
                if(i!=j)
                {
                    a[i] += c;
                    a[j] += c;
                }
                else
                {
                    a[i] += c;
                }
                
                if(a[i]==10)
                {
                    a[i]=0;
                    a[j]=0;
                    c=1;
                }
                else
                {
                    c=0;
                }
                i--;
                j++;
            }
            if(c!=0)
            {
                int a1[] = new int[n+1];
                a1[0]=a1[n]=1;
                a=a1;
            }
        }
        else
        {
            if(a[j]<a[i])
            {
                while(i>=0 && j<n)
                {
                    a[j]=a[i];
                    i--; j++;
                }
            }
            else
            {
                int c=1;
                int i1, j1;
                if(n%2==0)
                {
                    j1=(n/2);
                    i1=j1-1;
                }
                else
                {
                    j1=(n/2);
                    i1=(n/2);
                }
                while(i1>=i && j1<=j && c!=0)
                {
                    if(i1!=j1)
                    {
                        a[i1] += c;
                        a[j1] += c;
                    }
                    else
                    {
                        a[i1] += c;
                    }
                    
                    if(a[i1]==10)
                    {
                        a[i1]=a[j1]=0;
                        c=1;
                    }
                    else
                    {
                        c=0;
                    }
                    i1--;
                    j1++;
                }
            }
            while(i>=0 && j<n)
            {
                a[j]=a[i];
                i--;
                j++;
            }
        }
        return a;
    }
}
