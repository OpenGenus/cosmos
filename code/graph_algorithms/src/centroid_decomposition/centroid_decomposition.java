import java.util.*;

public class CentroidDecomposition {

	static void calcSizes(List<Integer>[] tree, int[] size, boolean[] deleted, int u, int p) {
		size[u] = 1;
		for (int v : tree[u]) {
			if (v == p || deleted[v]) continue;
			calcSizes(tree, size, deleted, v, u);
			size[u] += size[v];
		}
	}

	static int findTreeCentroid(List<Integer>[] tree, int[] size, boolean[] deleted, int u, int p, int vertices) {
		for (int v : tree[u]) {
			if (v == p || deleted[v]) continue;
			if (size[v] > vertices / 2) {
				return findTreeCentroid(tree, size, deleted, v, u, vertices);
			}
		}
		return u;
	}

	static void decompose(List<Integer>[] tree, int[] size, boolean[] deleted, int u, int total) {
		calcSizes(tree, size, deleted, u, -1);
		int centroid = findTreeCentroid(tree, size, deleted, u, -1, total);
		calcSizes(tree, size, deleted, centroid, -1);
		deleted[centroid] = true;

		System.out.println(centroid);

		for (int v : tree[centroid]) {
			if (deleted[v]) continue;
			decompose(tree, size, deleted, v, size[v]);
		}
	}

	public static void centroidDecomposition(List<Integer>[] tree) {
		int n = tree.length;
		decompose(tree, new int[n], new boolean[n], 0, n);
	}

	public static void main(String[] args) {
		int n = 4;
		List<Integer>[] tree = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
		tree[3].add(0);
		tree[0].add(3);
		tree[3].add(1);
		tree[1].add(3);
		tree[3].add(2);
		tree[2].add(3);
		centroidDecomposition(tree);
	}
}
