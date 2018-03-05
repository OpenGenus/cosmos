public class Problem005 {
	public static boolean isDivisible(long number) {
		boolean flag = true;
		for(long i = 1; i <= 20; ++i) {
			if(number % i != 0)
				flag = false;
		}
		return flag;
	}
	public static void main(String []args) {
		long i = 1;
		while(true) {
			if(isDivisible(i))
				break;
			++i;
		}
		System.out.println(i);
	}
}
