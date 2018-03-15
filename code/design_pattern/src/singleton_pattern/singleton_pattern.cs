// Singleton design pattern using properties
class Singleton
{
	private static readonly Singleton _instance = new Singleton();
	public static Singleton Instance { get { return _instance; } }

	private Singleton()
	{
		// Initialize object
	}
}

class Program
{
	static void Main(string[] args)
	{
		var instance = Singleton.Instance;
	}
}