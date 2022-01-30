import java.util.*;
class Tribonacci {
    public static void main(String args[] ) throws Exception {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int a[] = new int[n+1];
        a[1]=0;
        a[2]=0;
        a[3]=1;
        for (int i = 4; i <= n; i++) 
        {
            a[i]=a[i-1]+a[i-2]+a[i-3];
        }
        for(int i=1;i<=n;i++){
            System.out.println(a[i]);
        }
    }
}