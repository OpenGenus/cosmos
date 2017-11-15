import java.util.*;

public class Coloring {

	int minColors;
	int[] bestColoring;

	public int minColors(boolean[][] graph) {
		int n = graph.length;
		bestColoring = new int[n];
		int[] id = new int[n + 1];
		int[] deg = new int[n + 1];
		for (int i = 0; i <= n; i++)
			id[i] = i;
		bestColoring = new int[n];
		int res = 1;
		for (int from = 0, to = 1; to <= n; to++) {
			int best = to;
			for (int i = to; i < n; i++) {
				if (graph[id[to - 1]][id[i]])
					++deg[id[i]];
				if (deg[id[best]] < deg[id[i]])
					best = i;
			}
			int t = id[to];
			id[to] = id[best];
			id[best] = t;
			if (deg[id[to]] == 0) {
				minColors = n + 1;
				dfs(graph, id, new int[n], from, to, from, 0);
				from = to;
				res = Math.max(res, minColors);
			}
		}
		return res;
	}

	void dfs(boolean[][] graph, int[] id, int[] coloring, int from, int to, int cur, int usedColors) {
		if (usedColors >= minColors)
			return;
		if (cur == to) {
			for (int i = from; i < to; i++)
				bestColoring[id[i]] = coloring[i];
			minColors = usedColors;
			return;
		}
		boolean[] used = new boolean[usedColors + 1];
		for (int i = 0; i < cur; i++)
			if (graph[id[cur]][id[i]])
				used[coloring[i]] = true;
		for (int i = 0; i <= usedColors; i++) {
			if (!used[i]) {
				int tmp = coloring[cur];
				coloring[cur] = i;
				dfs(graph, id, coloring, from, to, cur + 1, Math.max(usedColors, i + 1));
				coloring[cur] = tmp;
			}
		}
	}

	public static void main(String[] args) {
		Random rnd = new Random(1);
		for (int step = 0; step < 1000; step++) {
			int n = rnd.nextInt(10) + 1;
			boolean[][] g = new boolean[n][n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < i; j++)
					if (rnd.nextBoolean()) {
						g[i][j] = true;
						g[j][i] = true;
					}
			int res1 = new Coloring().minColors(g);
			int res2 = colorSlow(g);
			if (res1 != res2)
				throw new RuntimeException();
		}
	}

	static int colorSlow(boolean[][] g) {
		int n = g.length;
		for (int allowedColors = 1; ; allowedColors++) {
			long colors = 1;
			for (int i = 0; i < n; i++)
				colors *= allowedColors;
			m1:
			for (long c = 0; c < colors; c++) {
				int[] col = new int[n];
				long cur = c;
				for (int i = 0; i < n; i++) {
					col[i] = (int) (cur % allowedColors);
					cur /= allowedColors;
				}
				for (int i = 0; i < n; i++)
					for (int j = 0; j < i; j++)
						if (g[i][j] && col[i] == col[j])
							continue m1;
				return allowedColors;
			}
		}
	}
}
