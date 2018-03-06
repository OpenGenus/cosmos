public class Problem005 {
	public static boolean isDivisible(int number) {
		for(int i = 1; i <= 20; ++i) {
			if(number % i != 0)
				return false;
		}
		return true;
	}
	public static void main(String []args) {
		int number = 1;
		while(!isDivisible(number)) {
			++number;
		}
		System.out.println(number);
	}
}
