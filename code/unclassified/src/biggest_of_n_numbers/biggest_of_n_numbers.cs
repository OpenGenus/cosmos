namespace BiggestOfNumbers
{
    public class BiggestOfNumbers
    {
        public void main()
        {
            int n , max , tmp;
            Console.WriteLine("Enter numbers of elements : ");
            n = Console.ReadLine();
            Console.WriteLine("Enter numbers : ");
            tmp = Console.ReadLine();
            max = tmp;
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
