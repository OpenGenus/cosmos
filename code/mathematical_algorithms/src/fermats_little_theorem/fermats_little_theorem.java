import java.util.*;
class Main
{
    public static long power(long a, long b, long mod)
    {
        if (b == 0)
            return 1;
        long sp = power(a, b / 2, mod);
        sp %= mod;
        sp = (sp * sp) % mod;
        if ((b & 1) == 1)
            return (sp * a) % mod;
        return sp % mod;
    }
    public static long stoi(String a, long mod)
    {
        long ans = 0;
        for (int i = 0; i < a.length(); i++)
            ans = ((ans * 10) % mod + a.charAt(i) - '0') % mod;
        return ans;
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        long t, n, m, mod = 1000000007;
        t = sc.nextLong();
        String a, b;
        while (t-- > 0)
        {
            a = sc.next();
            b = sc.next();
            n = stoi(a, mod);
            m = stoi(b, mod - 1); // Fermats theorem
            System.out.println(power(n, m, mod));
        }
    }
}
/*

Sample Input :

5
3 2
4 5
7 4
34534985349875439875439875349875 93475349759384754395743975349573495
34543987529435983745230948023948 3498573497543987543985743989120393097595572309482304

Sample Output :

9
1024
2401
735851262
985546465

*/
