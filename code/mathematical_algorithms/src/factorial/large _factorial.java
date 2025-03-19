import java.util.Scanner;

// calculates factorial of number till 2000 as around (2000)!

class Factorial{
    static long val[];

    public static int max(int a,int b)
    {
        return a>b?a:b;
    }

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int num;
        int val[]=new int[100000];
        for(int x=0;x<100000;x++)
        {
            val[x]=0;
        }
        val[0]=1;
        int maxIndex=0;
        num=sc.nextInt();
        for(int x=2;x<=num;x++)
        {
            for(int y=0;y<=maxIndex;y++)
            {
                val[y]*=x;
            }
            int index=0;
            while(index<=maxIndex)
            {
                val[index+1]+=val[index]/10;
                val[index]=val[index]%10;
                index++;
            }
            while(val[index]>=10){

                val[index+1]+=val[index]/10;
                val[index]=val[index]%10;
                index++;
            }
            maxIndex=max(index,maxIndex);
        }

        String s="";
        for(int x=0;x<=maxIndex;x++)
        {
            s=val[x]+s;
        }
        System.out.println(num+"! = "+ s);
    }
}
