// Part of Cosmos by OpenGenus Foundation

class AutomorphicNumber{
	public static void main(String[] args){
		// From range 0 to 1000000,
		// it will find which one is Automorphic Number.
		// If it is Automorphic Number,
		// then program will print it with its square value.
		for(long x=0; x<=1000000; x++)
			if(automorphic(x))
				// Square numbers can get really big.
				// So, if you want to try with a bigger number, I suggest
				// to use java.math.BigInteger instead of long data type.
				System.out.println(x+" "+(x*x));
	}

	public static boolean automorphic(long num){
		// Convert num into string data type.
		String strNum = Long.toString(num);

		// Convert num^2 into string data type. Like in the comment before,
		// use BigInteger, if you want to try a really big number.
		String strSquareNum = Long.toString(num*num);

		// Find the length of both converted num and num^2.
		int lenNum = strNum.length();
		int lenSquareNum = strSquareNum.length();

		// Return the value of (the last lenNum digits of num^2 == num)
		return strSquareNum.substring(lenSquareNum-lenNum).equals(strNum);
	}
}
