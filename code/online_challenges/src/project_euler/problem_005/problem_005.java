public class Problem005 {
	public static boolean isDivisible(long number) {
		for(long i = 1; i <= 20; ++i) {
			if(number % i != 0)
				return false;
		}
		return true;
	}
	public static void main(String []args) {
		long number = 1;
		while(!isDivisible(number)) {
			++number;
		}
		System.out.println(number);
	}
}
