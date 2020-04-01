import java.util.*;

public class Bundling {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i = 1; i<=t; i++){
            int N = sc.nextInt();
            int K = sc.nextInt();
            String[] a = new String[N];
            for(int j = 0; j<N; j++){
                a[j] = sc.next();
            }
            Arrays.sort(a);
            int sum = 0;
            for(int z = 0; z<N; z+=K){
                String[] sub = Arrays.copyOfRange(a,z,z+K);
                int ans = commonPrefix(sub, K);
                sum += ans;
            }
            System.out.println("Case #" + i + ": " + sum);
        }
    }

    static int findMinLength(String arr[], int n) { 
        int min = Integer.MAX_VALUE; 
        for (int i = 0; i <= (n - 1); i++) { 
            if (arr[i].length() < min) { 
                min = arr[i].length(); 
            } 
        } 
        return min; 
    } 
    
    static boolean allContainsPrefix(String arr[], int n, String str, int start, int end) { 
        for (int i = 0; i <= (n - 1); i++) { 
            String arr_i = arr[i]; 
                
            for (int j = start; j <= end; j++) 
                if (arr_i.charAt(j) != str.charAt(j)) 
                    return false; 
        } 
        return true; 
    } 
    
    // A Function that returns the longest common prefix 
    // from the array of strings 
    static int commonPrefix(String arr[], int n) { 
        int index = findMinLength(arr, n); 
        String prefix = ""; // Our resultant string 
    
        // We will do an in-place binary search on the 
        // first string of the array in the range 0 to 
        // index 
        int low = 0, high = index-1; 
        while (low <= high) { 
                
            // Same as (low + high)/2, but avoids  
            // overflow for large low and high 
            int mid = low + (high - low) / 2; 
    
            if (allContainsPrefix(arr, n, arr[0], low,  mid)) { 
                // If all the strings in the input array 
                // contains this prefix then append this 
                // substring to our answer 
                prefix = prefix + arr[0].substring(low, mid + 1); 
    
                // And then go for the right part 
                low = mid + 1; 
            }  
            else // Go for the left part { 
                high = mid - 1; 
            } 
        } 
        return prefix.length(); 
    } 
}