import java.util.*;
// Part of Cosmos by OpenGenus Foundation
class Average
{
    /**
    * @param arr array of integers to get the average of.
    * @param n number of elements.
    * @return the average calculated as sum(arr)/n
    */
    static double avrg(Vector<Integer> arr)
    {
        if (arr.isEmpty()) return 0.0;
        double sum = 0;
        double avg = 0.0;
        final int SIZE = arr.size();
        for(int i = 0;i < SIZE; i++)
        {
            sum += arr.get(i);
        }
        
        return sum / SIZE;
    }
    public static void main(String args[])
    {
        int n;
        // int[] arr = new int[1000];
        Vector<Integer> arr = new Vector<Integer>();
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter elements in array (-1)exit ");
        
        while ((n = scan.nextInt()) != -1)
            arr.add(n);

        double avg = avrg(arr);
        System.out.printf("Average = %2.2f\n",avg);
    }
}
