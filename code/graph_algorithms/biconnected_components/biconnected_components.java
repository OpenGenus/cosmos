import java.util.*;

public class Biconnectivity {

	List<Integer>[] graph;
	boolean[] visited;
	Stack<Integer> stack;
	int time;
	int[] tin;
	int[] lowlink;
	List<List<Integer>> edgeBiconnectedComponents;
	List<Integer> cutPoints;
	List<String> bridges;

	public List<List<Integer>> biconnectivity(List<Integer>[] graph) {
		int n = graph.length;
		this.graph = graph;
		visited = new boolean[n];
		stack = new Stack<>();
		time = 0;
		tin = new int[n];
		lowlink = new int[n];
		edgeBiconnectedComponents = new ArrayList<>();
		cutPoints = new ArrayList<>();
		bridges = new ArrayList<>();

		for (int u = 0; u < n; u++)
			if (!visited[u])
				dfs(u, -1);

		return edgeBiconnectedComponents;
	}

	void dfs(int u, int p) {
		visited[u] = true;
		lowlink[u] = tin[u] = time++;
		stack.add(u);
		int children = 0;
		boolean cutPoint = false;
		for (int v : graph[u]) {
			if (v == p)
				continue;
			if (visited[v]) {
				lowlink[u] = Math.min(lowlink[u], tin[v]); // or lowlink[u] = Math.min(lowlink[u], lowlink[v]);
			} else {
				dfs(v, u);
				lowlink[u] = Math.min(lowlink[u], lowlink[v]);
				cutPoint |=  tin[u] <= lowlink[v];
				if (tin[u] < lowlink[v]) // or if (lowlink[v] == tin[v])
					bridges.add("(" + u + "," + v + ")");
				++children;
			}
		}
		if (p == -1)
			cutPoint = children >= 2;
		if (cutPoint)
			cutPoints.add(u);
		if (tin[u] == lowlink[u]) {
			List<Integer> component = new ArrayList<>();
			while (true) {
				int x = stack.pop();
				component.add(x);
				if (x == u)
					break;
			}
			edgeBiconnectedComponents.add(component);
		}
	}

	public static List<Integer>[] ebcTree(List<Integer>[] graph, List<List<Integer>> components) {
		int[] comp = new int[graph.length];
		for (int i = 0; i < components.size(); i++)
			for (int u : components.get(i))
				comp[u] = i;
		List<Integer>[] g = Stream.generate(ArrayList::new).limit(components.size()).toArray(List[]::new);
		for (int u = 0; u < graph.length; u++)
			for (int v : graph[u])
				if (comp[u] != comp[v])
					g[comp[u]].add(comp[v]);
		return g;
	}

	public static void main(String[] args) {
		List<Integer>[] graph = Stream.generate(ArrayList::new).limit(6).toArray(List[]::new);

		int[][] esges = {{0, 1}, {1, 2}, {0, 2}, {2, 3}, {1, 4}, {4, 5}, {5, 1}};
		for (int[] edge : esges) {
			graph[edge[0]].add(edge[1]);
			graph[edge[1]].add(edge[0]);
		}

		Biconnectivity bc = new Biconnectivity();
		List<List<Integer>> components = bc.biconnectivity(graph);

		System.out.println("edge-biconnected components:" + components);
		System.out.println("cut points: " + bc.cutPoints);
		System.out.println("bridges:" + bc.bridges);
		System.out.println("condensation tree:" + Arrays.toString(ebcTree(graph, components)));
	}
}
