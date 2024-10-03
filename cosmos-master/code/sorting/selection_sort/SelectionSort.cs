// Part of Cosmos by OpenGenus Foundation
public class SelectionSort
{
    public static void Main(string[] args)
    {
        int[] items = new int[] {52, 62, 143, 73, 22, 26, 27, 14, 62, 84, 15 };
        Sort(items);
        
        System.Console.WriteLine("Sorted: ");
        
        for (int i = 0; i < items.Length; i++)
          System.Console.Write(items[i] + " ");
    }
  
    private static void Sort(int[] items)
    {
        for (int i = 0; i < items.Length - 1; i++)
        {
            int minIndex = i;
            
            for (int j = i + 1; j < items.Length; j++)
                if (items[j] < items[minIndex])
                    minIndex = j;
                  
            int temp = items[minIndex];
            
            items[minIndex] = items[i];
            items[i] = temp;
        }
    }
}
