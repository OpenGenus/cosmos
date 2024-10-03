import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class EqualizeEveryone {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0){
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            String[] input = br.readLine().split(" ");
            int min = Integer.MAX_VALUE;
            for(int i=0; i<n; i++){
                arr[i] = Integer.parseInt(input[i]);
                min = Math.min(arr[i],min);
            }
            int minOperations = 0;
            for(int i=0; i<n; i++){
                minOperations += arr[i]-min;
            }
            System.out.println(minOperations);
        }

    }
}
