import java.util.Arrays;

public class SuffixArray {

	public static void main(String[] args) {
		System.out.println(Arrays.toString(suffixArray("Hello world")));
	}

	public static String[] suffixArray(String word) {
		String[] suffix = new String[word.length() + 1];
		String tmp = "$";

		for (int i = suffix.length - 1; i > 0; i--) {
			suffix[i] = tmp;
			tmp = word.charAt(i - 1) + tmp;
		}
		suffix[0] = tmp;
    
		return suffix;
	}
}
