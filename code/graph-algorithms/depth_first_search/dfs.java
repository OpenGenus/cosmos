/* Part of Cosmos by OpenGenus Foundation */

public static void main(String[] args) {
		Graph g=new Graph();
		g.addVertex("A");
		g.addVertex("B");
		g.addVertex("C");
		g.addVertex("D");
		g.addVertex("E");
		g.addVertex("F");
		g.addVertex("G");
		

		g.addEdge("A", "B", 10);
		g.addEdge("A", "D", 40);
		g.addEdge("B", "C", 10);
		g.addEdge("C", "D", 10);
		g.addEdge("D", "E", 2);
		g.addEdge("E", "F", 3);
		g.addEdge("E", "G", 8);
		
		g.addEdge("F", "G", 3);
		System.out.println(g.dfs("A","G"));
	}
}


	public static void addVertex(String a) {
		if (vtx.containsKey(a))
			return;
		vertex temp = new vertex();
		vtx.put(a, temp);
	}


	public static void addEdge(String a, String b, int weight) {
		if (!vtx.containsKey(a) || !vtx.containsKey(b))
			return;
		vtx.get(a).edgen.put(b, weight);
		vtx.get(b).edgen.put(a, weight);
		return;
	}

	public static boolean dfs(String a, String b) {
		HashMap<String, Boolean> hmap = new HashMap<>();

		pair temp = new pair(a, a);
		LinkedList<pair> stack = new LinkedList<>();
		stack.addFirst(temp);
		while (!stack.isEmpty()) {
			pair jojo = stack.getFirst();
			hmap.put(jojo.vname, true);
			stack.removeFirst();

			if (vtx.get(jojo.vname).edgen.containsKey(b)) {
				System.out.println(jojo.anssofar + b);
				return true;
			}

			ArrayList<String> arr = new ArrayList<>(vtx.get(jojo.vname).edgen.keySet());

			for (int i = 0; i < arr.size(); i++) {
				if (!hmap.containsKey(arr.get(i))) {
					stack.addFirst(new pair(arr.get(i), jojo.anssofar + arr.get(i)));
				}
			}
		}
		return false;
	}
	class pair {
		String vname;
		String anssofar;


		pair(String vname, String anssofar) {
			this.vname = vname;
			this.anssofar = anssofar;
		}
	}
