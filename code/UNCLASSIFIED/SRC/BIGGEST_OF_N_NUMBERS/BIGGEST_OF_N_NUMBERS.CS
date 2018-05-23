namespace BiggestOfNumbers
{
    public class BiggestOfNumbers
    {
        public void main()
        {
            Console.WriteLine("Enter numbers of elements : ");
            int n = Console.ReadLine();
            Console.WriteLine("Enter numbers : ");
            int tmp = Console.ReadLine();
            int max = tmp;
            for(int i=0; i<n-1; i++)
            {
                tmp = Console.ReadLine();
                if (max<tmp)
                {
                    max = tmp;
                }
            }
            Console.WriteLine("Maximum is {0}",max);
        }
    }
}
