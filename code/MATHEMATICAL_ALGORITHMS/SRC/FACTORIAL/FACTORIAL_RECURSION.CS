class factorial_recursion
{
    public static int factorial(int n)
    {
        if(n == 1)
            return 1;
        else
            return n * factorial(n - 1);
    }

    public static void Main()
    {
        System.Console.WriteLine(factorial(5));
    }
}
