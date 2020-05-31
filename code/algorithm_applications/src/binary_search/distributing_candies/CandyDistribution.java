import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class CandyDistribution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	//testcases
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0){
            String[] input = br.readLine().split(" ");
            //n: number of candy boxes
            int n = Integer.parseInt(input[0]);
            //k: number of friends
            long k = Long.parseLong(input[1]);
            String[] input1 = br.readLine().split(" ");
            long[] arr = new long[n];
            long max = Integer.MIN_VALUE;
            for(int i=0; i<n; i++){
                arr[i] = Long.parseLong(input1[i]);
//we need to find max for the upper bound in the binary search.
                max = Math.max(max,arr[i]);
            }
            System.out.println(binarySearch(n, k, arr, max));
        }
    }
  public static long binarySearch(int n, long k, long[] arr, long max){
        long low = 1;
        long high = max;
        long mid;
        long res = 0;

        while (high>=low){
            mid = low + (high-low)/2;
            if(canDistribute(mid, n, k, arr)){
                low = mid+1;
                res = mid;
            }
            else{
                high = mid-1;
            }
        }
        return res;
    }
    
  public static boolean canDistribute(long val, int n, long k, long[] arr){
        if(k==1){
            return true;
        }
        long peopleServed = 0;
        for (int i=n-1; i>=0; i--){
//this is the number of people who can get candy
            peopleServed += arr[i]/val;
        }
        if(peopleServed>=k){
            return true;
        }
        return false;
    }
}
