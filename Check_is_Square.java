public class Check_is_Square {

	static boolean checkIsSquare(int number)
	{
		double sqrt = Math.sqrt(number);
		int x = (int) sqrt;
		if(Math.pow(sqrt,2) == Math.pow(x,2))
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	public static void main(String[] args) {
		int a = 9;
		int b = 10;
		
		System.out.println("Is " + a + " a square number? " + checkIsSquare(a));  //true
		System.out.println("Is " + b + " a square number? " + checkIsSquare(b));  //false
	}

}
