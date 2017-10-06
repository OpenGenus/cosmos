public class convert_number_binary {
	public static void main(String[] args) {
		String binary = toBinary(20);
		System.out.println(binary);

		int number = toNumber("10101");
		System.out.println(number);
	}

	public static String toBinary(int n) {
		String binary = "";
		while (n > 0) {
			if ((n&1) == 0)
				binary = '0' + binary;
			else
				binary = '1' + binary;

			n >>= 1;
		}
		return binary;
	}

	public static int toNumber(String s) {
		int number = 0;
		int n = s.length();
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == '1') {
				number += (1 << (n - 1 - i));
			}
		}
		return number;
	}
}