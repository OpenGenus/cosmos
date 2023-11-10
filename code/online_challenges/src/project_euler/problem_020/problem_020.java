import java.math.BigInteger;

public class Problem_020 {
	public static BigInteger factorial(BigInteger number) {
		if (number.equals(BigInteger.ZERO))
			return BigInteger.ONE;
		return (number.multiply(factorial(number.subtract(BigInteger.ONE))));
	}
	public static BigInteger addDigits(BigInteger n) {
		BigInteger sum = BigInteger.ZERO;
		while(!n.equals(BigInteger.ZERO)) {
			sum = sum.add(n.mod(BigInteger.TEN));
			n = n.divide(BigInteger.TEN);
		}
		return sum;
	}
	
	public static void main(String []args) {
		BigInteger sum = BigInteger.ZERO;
		sum = addDigits(factorial(BigInteger.valueOf(100)));
		System.out.println(sum.toString());
	}

}
