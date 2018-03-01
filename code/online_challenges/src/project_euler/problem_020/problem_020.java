import java.math.BigInteger;

public class problem_020 {
	public static BigInteger factorial(BigInteger fact) {
		if (fact.equals(BigInteger.ZERO))
			return BigInteger.ONE;
		else
			return(fact.multiply(factorial(fact.subtract(BigInteger.ONE))));
	}
	public static BigInteger addDigits(BigInteger n) {
		BigInteger  sum = BigInteger.ZERO;
		while(!n.equals(BigInteger.ZERO)) {
			sum = sum.add(n.mod(BigInteger.TEN));
			n = n.divide(BigInteger.TEN);
		}
		return sum;
	}
	
	public static void main(String []args) {
		BigInteger sum=BigInteger.ZERO;
		sum=addDigits(factorial(BigInteger.valueOf(100)));
		System.out.println("Sum of digits of 100! is "+sum.toString()); // 648
	}

}
