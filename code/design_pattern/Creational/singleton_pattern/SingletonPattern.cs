using System;

public sealed class Singleton
{
    private readonly static Lazy<Singleton> _singletonInstance = new Lazy<Singleton>(()=>new Singleton());

    private Singleton(){}

    public static Singleton Instance => _singletonInstance.Value;
}

public class SingletonPattern
{
    public static void Main(string[] args)
    {
        Singleton instance = Singleton.Instance;
        Console.WriteLine(instance == Singleton.Instance);
    }
}