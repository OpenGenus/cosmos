// Part of Cosmos by OpenGenus
public class Solution{

    public static void main(String[] args) {
        // TODO Auto-generated method stub

    long largest=0l;
    int flag=0;
    long sum=1000;
    for(long a=1;a<sum/3;a++)
    {
        long asq=a*a;
        long b=((a*a)-(a-sum)*(a-sum))/(2*(a-sum));
        long bsq=b*b;
        long c=sum-a-b;
        long csq=c*c;
        if(asq+bsq==csq)
        {
            flag=1;
            if(a*b*c>largest)
            {
                largest=a*b*c;
            }
        }

    }

    if(largest!=0)
    {
        System.out.println(largest);
    }
    if(flag==0)
    {
        System.out.println(-1);
    }

}
}
