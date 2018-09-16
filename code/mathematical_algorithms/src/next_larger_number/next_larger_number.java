// Part of Cosmos by OpenGenus Foundation
public class NextGreaterNumber 
{
    private void swap(int[] number, int i, int j)
    {
        int temp  = number[i];
        number[i] = number[j];
        number[j] = temp;
    }
     
    private void sortSubarray(int[] number, int i, int j)
    {
        
        while (i < j)
        {
            swap(number, i, j);
            i += 1;
            j -= 1;
        }
    }
     
    public void findNextGreaterNumber(int[] number)
    {
        int lastDigitSeen = number[number.length-1], i, j;
        for (i = number.length-2; i >= 0; i--)
        {
           
            if (lastDigitSeen > number[i])
            {
                break;
            }
            lastDigitSeen = number[i];
        }
         
        if (i >= 0) // we found the digit breaking the sorted ordering
        {
           
            for (j = number.length-1; j > i; j--)
            {
                if (number[j] > number[i])
                {
                    break;
                }
            }
             
           
            swap(number, i, j);
             
            
            sortSubarray(number, i+1, number.length-1);
        }
    }
     
     
    public static void main(String[] args) 
    {
        NextGreaterNumber solution = new NextGreaterNumber();
         
        int[] number = {6,9,3,8,6,5,2};
         
        solution.findNextGreaterNumber(number);
         
        System.out.println("Next greater number is: ");
        for (int i = 0; i < number.length; i++)
        {
            System.out.print(number[i]);
        }
    }
}
