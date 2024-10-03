import java.util.Scanner;

public class Solution
{
    private static void removeDuplicates(String s)
    {
        String temp = new String("");
        for(int i=0;i<s.length();i++)
        {
            if(temp.indexOf(s.charAt(i)) == -1)
                temp.concat(s.charAt(i) +"");
        }
        s = temp;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T>0)
        {
            int n = sc.nextInt();
            String[] recipe = new String[n];
            sc.nextLine();
            for(int i=0;i<n;i++)
            {
                recipe[i] = sc.nextLine();

            }
            for(int i=0;i<n;i++)
            {
                removeDuplicates(recipe[i]);
            }
            int answer =0;

            for(char c = 'a';c<='z';c++)
            {
                int temp=0;
                for(int i=0;i<n;i++)
                {
                    if(recipe[i].indexOf(c)!=-1)
                        temp++;
                }
                if(temp==n)
                    answer++;
            }
            System.out.println(answer);
            T--;

        }
    }
}
