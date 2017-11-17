import java.util.*;

public class KaratsubaMultiply {

	public static int[] karatsubaMultiply(int[] a, int[] b) {
		if (a.length < b.length) a = Arrays.copyOf(a, b.length);
		if (a.length > b.length) b = Arrays.copyOf(b, a.length);
		int n = a.length;
		int[] res = new int[n + n];
		if (n <= 10) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					res[i + j] = res[i + j] + a[i] * b[j];
		} else {
			int k = n >> 1;
			int[] a1 = Arrays.copyOfRange(a, 0, k);
			int[] a2 = Arrays.copyOfRange(a, k, n);
			int[] b1 = Arrays.copyOfRange(b, 0, k);
			int[] b2 = Arrays.copyOfRange(b, k, n);

			int[] a1b1 = karatsubaMultiply(a1, b1);
			int[] a2b2 = karatsubaMultiply(a2, b2);

			for (int i = 0; i < k; i++)
				a2[i] = a2[i] + a1[i];
			for (int i = 0; i < k; i++)
				b2[i] = b2[i] + b1[i];

			int[] r = karatsubaMultiply(a2, b2);
			for (int i = 0; i < a1b1.length; i++)
				r[i] = r[i] - a1b1[i];
			for (int i = 0; i < a2b2.length; i++)
				r[i] = r[i] - a2b2[i];

			System.arraycopy(r, 0, res, k, r.length);

			for (int i = 0; i < a1b1.length; i++)
				res[i] = res[i] + a1b1[i];
			for (int i = 0; i < a2b2.length; i++)
				res[i + n] = res[i + n] + a2b2[i];
		}
		return res;
	}

	// Usage example
	public static void main(String[] args) {
		// (3*x^2+2*x+1) * (4*x+3) = 12*x^3 + 17*x^2 + 10*x + 3
		System.out.println(Arrays.equals(new int[]{3, 10, 17, 12, 0, 0}, karatsubaMultiply(new int[]{1, 2, 3}, new int[]{3, 4})));
	}
}
