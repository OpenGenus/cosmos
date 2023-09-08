public boolean bfs(String a, String b) {
		HashMap<String, Boolean> hmap = new HashMap<>();

		pair temp = new pair(a, a);
		LinkedList<pair> queue = new LinkedList<>();
		queue.addLast(temp);
		while (!queue.isEmpty()) {
			hmap.put(queue.getFirst().vname, true);
			if (vces.get(queue.getFirst().vname).nbrs.containsKey(b)) {
				System.out.println(queue.getFirst().anssofar + b);
				return true;
			}
			ArrayList<String> arr = new ArrayList<>(vces.get(queue.getFirst().vname).nbrs.keySet());
			for (int i = 0; i < arr.size(); i++) {
				if (!hmap.containsKey(arr.get(i))) {
					queue.addLast(new pair(arr.get(i), queue.getFirst().anssofar + arr.get(i)));
				}
			}
			queue.removeFirst();
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
	