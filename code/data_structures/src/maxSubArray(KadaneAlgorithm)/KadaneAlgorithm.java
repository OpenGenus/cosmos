import java.util.*;

class KadaneAlgorithm {
  static int maxSubarraySum(int a[], int n) {
    long max = a[0];
    long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum > max)
        max = sum;
      if (sum < 0)
        sum = 0;
    }
    return max;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = sc.nextInt();
    }
    int ans = maxSubarraySum(arr, n);
    System.out.println(ans);
  }
}