/*

// design pattern | OOP patterns | singleton pattern | singleton pattern | JAVA
// Part of Cosmos by OpenGenus Foundation

*/



/**
 * Singleton Design Pattern
 * 
 * @author Sagar Rathod
 * @version 1.0
 * 
 */

class Singleton {
	
	private volatile transient static Singleton singletonInstance;
	
	private Singleton() {}
	
	public static synchronized Singleton getInstance() {
		
		if ( singletonInstance == null ) {
			singletonInstance = new Singleton();
		}
		return singletonInstance;
	}
}

public class SingletonPattern {
	
	public static void main(String[] args) {
		
		Singleton instance = Singleton.getInstance();
		System.out.println(instance == Singleton.getInstance());
	}
}
