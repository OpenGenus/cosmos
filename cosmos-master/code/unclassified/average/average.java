import java.util.*;
// Part of Cosmos by OpenGenus Foundation
class average
{
    static double avrg(int arr[], int n)
    {
        int sum = 0;
        double avg = 0.0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
        }
        avg = sum/n;
        return avg;
    }
    public static void main(String args[])
    {
        int n;
	int[] arr = new int[1000];
        System.out.print("Enter n = ");
        Scanner s1 = new Scanner(System.in);
        n = s1.nextInt();
        System.out.println("Enter elements in array");
        for(int i=0;i<n;i++)
        {
            arr[i] = s1.nextInt();
        }
        double avg = avrg(arr, n);
        System.out.println("Average = " + avg);
    }
}
