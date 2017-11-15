/* Part of Cosmos by OpenGenus Foundation */
import java.util.ArrayList;
import java.util.List;

public class RadixSort
{
  public static void main(String[] args)
  {
    int[] nums = {100, 5, 100, 19, 320000, 0, 67, 542, 10, 222};
    radixSort(nums);
    printArray(nums);
  }
  
  /**
   * This method sorts a passed array of positive integers using radix sort
   * @param input: the array to be sorted
   */
   public static void radixSort(int[] input)
   {
     List<Integer>[] buckets = new ArrayList[10];
     
     for(int i = 0; i < buckets.length; i++)//initialize buckets
       buckets[i] = new ArrayList<Integer>();
       
     int divisor = 1;
     String s = Integer.toString(findMax(input));
     int count = s.length();//count is the number of digits of the largest number
     
     for(int i = 0; i < count; divisor*=10, i++)
     {
       for(Integer num : input)
       {
         assert(num >= 0);
         int temp = num / divisor;
         buckets[temp % 10].add(num);
       }
    
       //Load buckets back into the input array
       int j = 0;
       for (int k = 0; k < 10; k++) 
       {
         for (Integer x : buckets[k]) 
         {
           input[j++] = x;
         }
         buckets[k].clear();
       }
     }
   }
   
   /**
    * This method returns the maximum integer in an integer array.
    * @param input: the array
    * @return the maximum integer in input
    */
    public static int findMax(int[] input)
    {
      assert(input.length != 0);
      
      int max = input[0];
      for(int i = 1; i < input.length; i++)
        if(input[i] > max)	max = input[i];
      return max;
    }
    
    /**
     * This method prints a passed array
     * @param array: the array to be printed
     */
     public static void printArray(int[] array)
     {
       System.out.print("[ ");
       for(Integer i : array)
         System.out.print(i+" ");
       System.out.print("]");
     }
}
