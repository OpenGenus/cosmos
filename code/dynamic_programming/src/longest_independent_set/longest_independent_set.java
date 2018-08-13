import java.util.*;

class Node {
	int id,lis;
	LinkedList<Node> child = new LinkedList<Node>();
	Node (int id) {
		this.id = id;
		this.lis = 0;
	}
}

class Graph {
	
	private HashMap<Integer,Node> nodeLookup = new HashMap<Integer,Node>();
	private Node root;
	
	public Graph(int root) {
		this.root = new Node(root);
		nodeLookup.put(root, this.root);
	}
	
	public HashMap<Integer, Node> getNodes(){
		return nodeLookup;
	}
	
	private Node getNode(int id) {
		Node n = nodeLookup.get(id);
		if(n==null) {
			n = new Node(id);
			nodeLookup.put(id, n);
		}
		return n;
	}
	
	public int LIS() {
		return lisUtil(this.root);
	}
	
	public int lisUtil(Node root) {
		if(root==null) return 0;
		else if(root.lis!=0) return root.lis;
		else if(root.child.size()==0) return 1;
		
		int lis_child = 0;
		Iterator<Node> itr = root.child.listIterator();
		while(itr.hasNext()) lis_child += lisUtil(itr.next());
		
		int lis_grdchld = 1;
		itr = root.child.listIterator();
		while(itr.hasNext()) {
			Node child = itr.next();
			Iterator<Node> grandChildren = child.child.listIterator();
			while(grandChildren.hasNext()) lis_grdchld += lisUtil(grandChildren.next());
		}
		
		return root.lis = Math.max(lis_child,lis_grdchld);
	}
	
	public void addEdge(int s,int d) {
		Node source = getNode(s);
		Node dest = getNode(d);
		source.child.add(dest);
	}
}

public class LIS {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int root = s.nextInt();
		Graph graph = new Graph(root);
		int n = s.nextInt();
		for(int i = 0;i<n;i++) graph.addEdge(s.nextInt(), s.nextInt());

		int lis = graph.LIS();
		
		System.out.println(lis);
	}

}
