import java.util.*;

public class BronKerbosh {

	public static int BronKerbosch(long[] g, long cur, long allowed, long forbidden, int[] weights) {
		if (allowed == 0 && forbidden == 0) {
			int res = 0;
			for (int u = Long.numberOfTrailingZeros(cur); u < g.length; u += Long.numberOfTrailingZeros(cur >> (u + 1)) + 1)
				res += weights[u];
			return res;
		}
		if (allowed == 0)
			return -1;
		int res = -1;
		int pivot = Long.numberOfTrailingZeros(allowed | forbidden);
		long z = allowed & ~g[pivot];
		for (int u = Long.numberOfTrailingZeros(z); u < g.length; u += Long.numberOfTrailingZeros(z >> (u + 1)) + 1) {
			res = Math.max(res, BronKerbosch(g, cur | (1L << u), allowed & g[u], forbidden & g[u], weights));
			allowed ^= 1L << u;
			forbidden |= 1L << u;
		}
		return res;
	}

	// random test
	public static void main(String[] args) {
		Random rnd = new Random(1);
		for (int step = 0; step < 1000; step++) {
			int n = rnd.nextInt(16) + 1;
			long[] g = new long[n];
			int[] weights = new int[n];
			for (int i = 0; i < n; i++)
				weights[i] = rnd.nextInt(1000);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < i; j++)
					if (rnd.nextBoolean()) {
						g[i] |= 1L << j;
						g[j] |= 1L << i;
					}
			int res1 = BronKerbosch(g, 0, (1L << n) - 1, 0, weights);
			int res2 = maxCliqueSlow(g, weights);
			if (res1 != res2)
				throw new RuntimeException();
		}
	}

	static int maxCliqueSlow(long[] g, int[] weights) {
		int res = 0;
		int n = g.length;
		for (int set = 0; set < 1 << n; set++) {
			boolean ok = true;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < i; j++)
					ok &= (set & (1 << i)) == 0 || (set & (1 << j)) == 0 || (g[i] & (1L << j)) != 0;
			if (ok) {
				int cur = 0;
				for (int i = 0; i < n; i++)
					if ((set & (1 << i)) != 0)
						cur += weights[i];
				res = Math.max(res, cur);
			}
		}
		return res;
	}
}
