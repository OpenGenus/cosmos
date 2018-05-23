import java.util.Scanner;

public class Tribonacci {
    public static void  printTribonacci(int n){
        int a=0,b=0,c=1,temp;

        if(n<1)
            return;

        System.out.print(a + " ");

        if(n>1)
            System.out.print(b + " ");

        if(n>2)
            System.out.print(c + " ");

        for(int i=3;i<n;i++) {
            temp = a + b + c;
            a = b;
            b = c;
            c = temp;

            System.out.print(c + " ");
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter n >> ");
        int n = sc.nextInt();

        printTribonacci(n);
    }
}

