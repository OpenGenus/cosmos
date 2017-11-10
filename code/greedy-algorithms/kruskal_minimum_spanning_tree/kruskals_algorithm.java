import java.util.*;

@SuppressWarnings("unchecked")

/*
 * This program runs an empirical test of Kruskal's minimum spanning
 * tree algorithm, making use of an efficient disjoint-set data
 * structure.
 *
 * The program generates two random, complete graphs G_1 = (V_1, E_1) and
 * G_2 = (V_2, E_2) each consisting of n vertices and n-choose-2 edges.
 * G_1 is a graph whose edges E_1 are of random weight in the range [0, 1].
 * G_2 is a graph whose vertices V_2 are labeled with random coordinates in
 * the unit square, and E_2 consists of edges whose weights are the
 * Euclidean distances between any two vertices in V_2.
 *
 * The program generates these graphs and runs Kruskal's minimum spanning
 * tree algorithm on them, printing the total weight of the tree for each
 * test.
 *
 * The program should be invoked from the command line with two integers:
 * the seed that should be used for the random number generator, and the
 * number of vertices in the randomly generated graphs.
 */
public class Kruskal {
  public static void main(String[] args) {
    /* Take program arguments */
    int seed, n;

    try {
      seed = Integer.parseInt(args[0]);
      n = Integer.parseInt(args[1]);
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("Usage: java Kruskal <seed> <number of vertices>");
      return;
    }

    int ne = (n * (n - 1)) / 2;     // Number of edges in a complete graph

    /* Run the tests for size n */
    float test1 = randomEdgeWeightTest(seed, n, ne);
    float test2 = randomVertexDistanceTest(seed, n, ne);

    System.out.printf("Test results for size %d:\n", n);
    System.out.printf("\trandom edge weight test: %f\n", test1);
    System.out.printf("\trandom vertex distance test: %f\n", test2);
  }


  /*
   * Generates edges of a complete graph where each edge has a random
   * weight in [0, 1] and returns the total weight of its minimum spanning
   * tree using Kruskal's algorithm.
   */
  public static float randomEdgeWeightTest(int seed, int n, int ne) {
    /* Initialize random number generator */
    Random r = new Random(seed);

    /* Create a list of vertices */
    ArrayList<Vertex> vertices = new ArrayList<Vertex>(n);

    /* Create a list of edges */
    ArrayList<Edge> edges = new ArrayList<Edge>(ne);

    for (int i = 0; i < n; i++)
      vertices.add(new Vertex(0, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        edges.add(new Edge(vertices.get(i), vertices.get(j), r.nextFloat()));
      }
    }

    /* Create the disjoint-set data structure */
    DisjointSet d = new DisjointSet(vertices);

    /* Create a list of edges */
    ArrayList<Edge> tree = new ArrayList<Edge>();

    /* Java's modified version of mergesort guarantees nlog(n) time here */
    Collections.sort(edges);

    /* Kruskal's algorithm */
    for (Edge e : edges) {
      Vertex u = e.getU();
      Vertex v = e.getV();
      if (d.find(u.getNode()) != d.find(v.getNode())) {
        /* Vertices v and u are not in the same component */
        tree.add(e);

        /* Union them in the tree */
        d.union(u.getNode(), v.getNode());
      }
    }

    /* Return the sum of the weights of all edges in the tree */
    return Edge.sum(tree);
  }


  /*
   * Generates vertices containing random coordinates inside the unit
   * square and calculates the weights of each edge (u, v) as the Euclidean
   * distance between the vertices u and v, and returns the total weight of the
   * graph's minimum spanning tree using Kruskal's algorithm.
   */
  public static float randomVertexDistanceTest(int seed, int n, int ne) {
    /* Initialize random number generator */
    Random r = new Random(seed);

    /* Create a list of vertices */
    ArrayList<Vertex> vertices = new ArrayList<Vertex>(n);

    /* Create a list of edges */
    ArrayList<Edge> edges = new ArrayList<Edge>(ne);

    /* Generate vertices with random x and y coordinates */
    for (int i = 0; i < n; i++)
      vertices.add(new Vertex(r.nextFloat(), r.nextFloat()));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        Vertex a = vertices.get(i);
        Vertex b = vertices.get(j);

        /*
         * Use a simplified distance formula to calculate the distance
         * between vertices a and b
         */
        Edge e = new Edge(a, b, Vertex.simpleDistance(a, b));
        edges.add(e);
      }
    }

    /* Create the disjoint-set data structure */
    DisjointSet d = new DisjointSet(vertices);

    /* Create a list of edges */
    ArrayList<Edge> tree = new ArrayList<Edge>();

    /* Java's modified version of mergesort guarantees nlog(n) time here */
    Collections.sort(edges);

    /* Kruskal's algorithm */
    for (Edge e : edges) {
      Vertex u = e.getU();
      Vertex v = e.getV();
      if (d.find(u.getNode()) != d.find(v.getNode())) {
        /* Vertices v and u are not in the same component */
        tree.add(e);

        /* Union them in the tree */
        d.union(u.getNode(), v.getNode());
      }
    }


    /*
     * Before summing, complete the final vertex distance calculation; we
     * achieve a slight speed-up here because there will be strictly less
     * than nC2 edges in the minimum spanning tree.
     */
    float sum = 0;

    for (Edge e : tree) {
      sum += Math.sqrt(e.getWeight());
    }

    /* Now return the sum */
    return sum;
  }
}


/*
 * Class representing a single vertex, holding a pointer to a node in
 * the disjoint-set data structure. Also contains facilities for calculating
 * simple and Euclidean distances.
 */
class Vertex {
  private float x;
  private float y;
  private Node n;

  public Vertex(float x, float y) {
    this.x = x;
    this.y = y;
  }

  public void setNode(Node n) { this.n = n; }
  public Node getNode() { return this.n; }

  public static float simpleDistance(Vertex a, Vertex b) {
    return (float) (Math.pow((b.y - a.y), 2) + Math.pow((b.x - a.x), 2));
  }

  public static float euclideanDistance(Vertex a, Vertex b) {
    return (float) Math.sqrt(Vertex.simpleDistance(a, b));
  }
}


/*
 * Class representing a single edge, holding pointers to the vertices
 * it connects. Also includes facilities for calculating sums of edge
 * weights.
 */
class Edge implements Comparable {
  private float weight;
  private Vertex u, v;

  public Edge(Vertex u, Vertex v) {
    this.u = u;
    this.v = v;
  }

  public Edge(Vertex u, Vertex v, float w) {
    this(u, v);
    this.weight = w;
  }

  public float getWeight() { return this.weight; }
  public void setWeight(float w) { this.weight = w; }
  public Vertex getU() { return this.u; }
  public Vertex getV() { return this.v; }

  public int compareTo(Object o) {
    Edge other = (Edge) o;

    if (this.getWeight() < other.getWeight())
      return -1;
    else if (this.getWeight() > other.getWeight())
      return 1;
    else
      return 0;
  }

  public static float sum(List<Edge> edges) {
    float sum = 0;

    for (Edge e : edges) {
      sum += e.getWeight();
    }

    return sum;
  }
}


/*
 * Implementation of a node, to be used with the DisjointSet tree
 * structure.
 */
class Node {
  int rank;      // the approximate count of nodes below this node
  int index;     // a unique index for each node in the tree
  Node parent;

  public Node(int r, int i, Node p) {
    this.rank = r;
    this.index = i;
    this.parent = p;
  }
}


/*
 * A simple implementation of the disjoint-set data structure.
 * Elements of disjoint sets are represented in a tree, in
 * which each node references its parent.
 * A "union by rank" strategy is used to optimize the combination
 * of two trees, making sure to always attach a smaller tree to the
 * root of the larger tree.
 */
class DisjointSet {
  private int nodeCount = 0;
  private int setCount = 0;

  ArrayList<Node> rootNodes;

  /*
   * Returns the index of the set that n is currently in.
   * The index of the root node of each set uniquely identifies the set.
   * This is used to determine whether two elements are in the
   * same set.
   */
  public int find(Node n) {
    Node current = n;

    /* Ride the pointer up to the root node */
    while (current.parent != null)
      current = current.parent;

    Node root = current;

    /*
     * Ride the pointer up to the root node again, but make each node below
     * a direct child of the root. This alters the tree such that future
     * calls will reach the root more quickly.
     */
    current = n;
    while (current != root) {
      Node temp = current.parent;
      current.parent = root;
      current = temp;
    }

    return root.index;
  }


  /*
   * Combines the sets containing nodes i and j.
   */
  public void union(Node i, Node j) {
    int indexI = find(i);
    int indexJ = find(j);

    /* Are these nodes already part of the same set? */
    if (indexI == indexJ) return;

    /* Get the root nodes of each set (this will run in constant time) */
    Node a = this.rootNodes.get(indexI);
    Node b = this.rootNodes.get(indexJ);

    /* Attach the smaller tree to the root of the larger tree */
    if (a.rank < b.rank) {
      a.parent = b;
    } else if (a.rank > b.rank) {
      b.parent = a;
    } else {
      b.parent = a;
      a.rank++;
    }

    this.setCount--;
  }


  /*
   * Takes a list of n vertices and creates n disjoint singleton sets.
   */
  public void makeSets(List<Vertex> vertices) {
    for (Vertex v : vertices)
      makeSet(v);
  }


  /*
   * Creates a singleton set containing one vertex.
   */
  public void makeSet(Vertex vertex) {
    Node n = new Node(0, rootNodes.size(), null);
    vertex.setNode(n);
    this.rootNodes.add(n);
    this.setCount++;
    this.nodeCount++;
  }


  public DisjointSet(List<Vertex> vertices) {
    this.rootNodes = new ArrayList<Node>(vertices.size());
    makeSets(vertices);
}
