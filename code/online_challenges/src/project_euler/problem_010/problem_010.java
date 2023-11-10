// Part of Cosmos by OpenGenus
public class Solution {

    static boolean checkp(int x)
    {
        if(x==0 || x==1)
            return false;
        if (x==2)
        {
            return true;
        }

        if(x%2==0)
        {
            return false;
        }
        else
        {
            for (int i=3; i*i<=x; )
            {
                if (x%i == 0)
                {
                    return false;
                }
                i=i+2;
            }
        }

        return true;
}

    public static void main(String[] args) {
        // TODO Auto-generated method stub

        long sum=0l;
        for(int j=2;j<=2000000;j++)
        {
            if(checkp(j)==true)
            {
                sum+=j;
            }
        }

        System.out.println(sum);


    }

}
