class factorial_iteration
{
    public static int factorial(int n)
    {
        int product = 1;
        for(int i = 2 ; i <= n ; i++)
            product *= i;
        
        return product;
    }

    public static void Main()
    {
        System.Console.WriteLine(factorial(5));
    }

}
