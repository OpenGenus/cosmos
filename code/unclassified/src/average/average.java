import java.util.*;
// Part of Cosmos by OpenGenus Foundation
class Average
{
    /**
    * @param arr array of integers to get the average of.
    * @param n number of elements.
    * @return the average calculated as sum(arr)/n
    */
    static double getAverage(ArrayList<Integer> arr)
    {
        if (arr.isEmpty()) {
            return 0.0;
        } 
        double sum = 0;
        for(int value : arr)
        {
            sum += value;
        }
        
        return sum / arr.size();
    }
    public static void main(String args[])
    {
        
        ArrayList<Integer> arr = new ArrayList<Integer>();
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter elements in array (-1)exit ");
        int n;
        while ((n = scan.nextInt()) != -1)
            arr.add(n);

        System.out.printf("Average = %2.2f\n",getAverage(arr));
    }
}
