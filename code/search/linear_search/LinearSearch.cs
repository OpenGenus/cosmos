// Part of Cosmos by OpenGenus
public class LinearSearch
{
    public static void Main(string[] args)
    {
        int[] items = new int[] { 10, 12, 52, 634, 24, 743, 234, 7, 25, 742, 76, 25};
    
        int itemToFind = 634;
        int itemIndex = linearSearch(items, itemToFind);
        if(itemIndex != -1)
            System.Console.WriteLine(itemToFind + " found at " + itemIndex);
        else
            System.Console.WriteLine(itemToFind + " not found!");
    }
    
    public static int linearSearch(int[] items, int itemToFind)
    {
        for(int i = 0; i < items.Length; i++)
        {
            if(items[i] == itemToFind)
            {
                return i;
            }
        }
        return -1;
    }
}