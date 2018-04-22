import java.util.*;
// Part of Cosmos by OpenGenus Foundation
class Average
{
    /**
    * @param arr array of integers to get the average of.
    * @param n number of elements.
    * @return the average calculated as sum(arr)/n
    */
    static double avrg(int arr[], int n)
    {
        if (n == 0) return 0.0;
        int sum = 0;
        double avg = 0.0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
        }
        avg = (double)sum/n;
        return avg;
    }
    public static void main(String args[])
    {
        int n;
	int[] arr = new int[1000];
        System.out.print("Enter n = ");
        Scanner s1 = new Scanner(System.in);
        n = s1.nextInt();
        if (n > 0) System.out.println("Enter elements in array");
        for(int i=0;i<n;i++)
        {
            arr[i] = s1.nextInt();
        }
        double avg = avrg(arr, n);
        System.out.println("Average = " + avg);
    }
}
