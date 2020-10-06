import java.util.Scanner;

public class Stupmach {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while (t-- >0){
            int n = s.nextInt();
            int arr[] = new int[n];
            for (int i = 0; i < n; i++){
                arr[i] = s.nextInt();
            }

            long maxtokens = 0;
            int min = arr[0];
            for (int i = 0;i < n; i++){
                if (min <= arr[i]) {
                    maxtokens += min;
                }
                else {
                    min = arr[i];
                    maxtokens += min;
                }
            }
            System.out.println(maxtokens);
        }
    }
}
 /*
 TEST CASE
INPUT
1
3
2 1 3

OUTPUT
4
 */

