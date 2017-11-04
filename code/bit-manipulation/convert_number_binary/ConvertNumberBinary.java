// Part of Cosmos by OpenGenus Foundation
public class ConvertNumberBinary {
	public static void main(String[] args) {
		String binary = toBinary(20);
		System.out.println(binary);

		int number = toNumber("10101");
		System.out.println(number);
	}

	public static String toBinary(int n) {
		StringBuilder binary = new StringBuilder("");
		while (n > 0) {
			if ((n&1) == 0)
				binary.append('0');
			else
				binary.append('1');

			n >>= 1;
		}
		return binary.toString();
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
