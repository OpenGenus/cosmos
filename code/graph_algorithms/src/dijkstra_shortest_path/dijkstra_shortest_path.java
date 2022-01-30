/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

import java.util.ArrayDeque;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;

/**
*
* @author cheikhSall
*/
public class Dijkstra {

  public static class Vertex<T> {

	T id;
	private Map<Vertex, Integer> neighbors;
	Integer cost;

	public Vertex(T id) {
	  this.id = id;
	  this.neighbors = new HashMap<>();
	  cost = Integer.MAX_VALUE;
	}

	public Map<Vertex, Integer> getNeighbors() {
	  return neighbors;
	}

	public void setNeighbors(Map<Vertex, Integer> neighbors) {
	  this.neighbors = neighbors;
	}

	public Number getCost() {
	  return cost;
	}

	public void setCost(Integer cost) {
	  this.cost = cost;
	}

	public T getId() {
	  return id;
	}

	public void setId(T id) {
	  this.id = id;
	}

	public void addNeighbor(Vertex neighbor, Integer cost) {
	  this.neighbors.put(neighbor, cost);

	}

  }

  public static class Graphe<T> {

	private Map<T, Vertex> vertices;
	public Queue<Vertex> visited;
	public Deque<T> paths = new ArrayDeque<>();
	public HashMap<T, Integer> distances;
	public HashMap<T, T> preds;

	public Graphe(Map<T, Vertex> vertices) {
	  this.vertices = vertices;
	  this.preds = new HashMap<>();
	  this.paths = new ArrayDeque<>();
	  this.distances = new HashMap<>();
	  this.visited = new PriorityQueue(new Comparator<Vertex>() {
		@Override
		public int compare(Vertex o1, Vertex o2) {
		  return o1.cost.compareTo(o2.cost);
		}
	  });

	}

	public void initDistance() {
	  this.vertices.keySet().forEach((key) -> {
		distances.put(key, Integer.MAX_VALUE);
		this.vertices.get(key).setCost(Integer.MAX_VALUE);
	  });

	}

	public void initStart(T dep) {

	  initDistance();
	  this.distances.put(dep, 0);

	}

	public Integer getCurrentDistance(T id) {
	  return this.distances.get(id);

	}

	public Vertex extractMin() {
	  Vertex current = null;
	  try {
		current = this.visited.remove();
	  } catch (Exception e) {

	  }
	  return current;

	}

	public Map<T, Vertex> getVertices() {
	  return vertices;
	}

	public void setVertices(Map<T, Vertex> vertices) {
	  this.vertices = vertices;

	}

	public void executeOnetoAll(T src) {

	  this.initStart(src);
	  Vertex origin = this.vertices.get(src);
	  if (origin != null) {
		origin.setCost(0);
		this.visited.add(this.vertices.get(origin.id));

		while (!this.visited.isEmpty()) {

		  Vertex u = this.extractMin();

		  this.findMinimalDistancesInNeighbor(u);

		}

	  } else {
		System.out.println("vertex not existing");
	  }

	}

	public void getAllDistances() {
	  System.out.println("Distances : ");
	  this.distances.keySet().forEach((vertex) -> {
		System.out.println("vertex " + vertex + " cost =  " + this.distances.get(vertex).intValue());

	  });

	}

	private void findMinimalDistancesInNeighbor(Vertex u) {

	  u.getNeighbors().keySet().forEach((key) -> {
		int cout = (int) u.getNeighbors().get(key);
		Vertex v = (Vertex) key;
		if (this.getCurrentDistance((T) v.id) > (this.getCurrentDistance((T) u.id) + cout)) {
		  this.distances.put((T) v.id, (this.getCurrentDistance((T) u.id) + cout));
		  v.setCost((this.getCurrentDistance((T) u.id) + cout));
		  this.visited.add(v);
		  this.preds.put((T) v.id, (T) u.id);

		} else {
		}
	  });

	}

	public void executeOnetoOne(T src, T goal) { // execution de l'algo sur n chemin de depart

	this.executeOnetoAll(src);
	Vertex origin = this.vertices.get(src);
	Vertex dest = this.vertices.get(goal);

	if (origin != null && dest != null) {
	  T step = goal;
	  while (origin.id != step) {
		this.paths.add(step);
		step = this.preds.get(step);
	  }
	  this.paths.add(src);

	  this.printPaths(src, goal);
	} else {
	  System.out.println("Path not existing");
	}
		   System.out.println();
  }

  public void printPaths(T src, T dest) {
	System.out.println("Paths : from " + src + " to " + dest);
	while (!this.paths.isEmpty()) {
	  System.out.print(this.paths.removeLast() + ", ");

	}
	System.out.println();
	System.out.println("Total cost : " + this.distances.get(dest));
  }
  
  
  public void printGraph(){
		  this.vertices.keySet().forEach((key) -> {
						
		  this.vertices.get(key).getNeighbors().keySet().forEach((neighbor) -> {
							  Vertex v = (Vertex) neighbor;
							  int cost = (int) this.vertices.get(key).getNeighbors().get(neighbor);
			System.out.println("("+this.vertices.get(key).id +")" +"---"+ cost+"--->"+"("+v.id+")");
		
	  });

	  });
  
			System.out.println();
  }
  

}

/**
* @param args the command line arguments
*/
public static void main(String[] args) {

 
  Vertex<String> v1 = new Vertex<String>("A");
  Vertex<String> v2 = new Vertex<String>("D");
  Vertex<String> v3 = new Vertex<String>("E");
  Vertex<String> v4 = new Vertex<String>("B");
  Vertex<String> v5 = new Vertex<String>("F");
  Vertex<String> v6 = new Vertex<String>("C");

  v1.addNeighbor(v2, 2);
  v1.addNeighbor(v3, 3);
  v1.addNeighbor(v4, 1);

  v2.addNeighbor(v1, 2);
  v2.addNeighbor(v3, 3);
  v2.addNeighbor(v5, 4);

  v3.addNeighbor(v1, 3);
  v3.addNeighbor(v2, 3);
  v3.addNeighbor(v4, 8);
  v3.addNeighbor(v5, 5);

  v4.addNeighbor(v1, 1);
  v4.addNeighbor(v6, 6);
  v4.addNeighbor(v3, 8);

  v5.addNeighbor(v6, 7);
  v5.addNeighbor(v3, 5);
  v5.addNeighbor(v2, 4);

  v6.addNeighbor(v4, 6);
  v6.addNeighbor(v5, 7);

  Map<String, Vertex> vertices = new HashMap<String, Vertex>();
  vertices.put(v1.id, v1);
  vertices.put(v2.id, v2);
  vertices.put(v3.id, v3);
  vertices.put(v4.id, v4);
  vertices.put(v5.id, v5);
  vertices.put(v6.id, v6);

  Graphe<String> graphe = new Graphe<String>(vertices);
   System.out.println("GRAPHE :");
   graphe.printGraph();
 
  graphe.executeOnetoAll("A");
  graphe.executeOnetoOne("A", "C");
  graphe.getAllDistances();

  graphe.executeOnetoOne("B", "F");
  graphe.getAllDistances();

  /* Integer entries -------------------------------------------*/
  System.out.println();

  Vertex< Integer> I1 = new Vertex<Integer>(1);
  Vertex<Integer> I2 = new Vertex<Integer>(2);
  Vertex<Integer> I3 = new Vertex<Integer>(3);
  Vertex<Integer> I4 = new Vertex<Integer>(4);
  Vertex<Integer> I5 = new Vertex<Integer>(5);
  Vertex<Integer> I6 = new Vertex<Integer>(6);

  I1.addNeighbor(I2, 2);
  I1.addNeighbor(I3, 3);
  I1.addNeighbor(I4, 1);

  I2.addNeighbor(I1, 2);
  I2.addNeighbor(I3, 3);
  I2.addNeighbor(I5, 4);

  I3.addNeighbor(I1, 3);
  I3.addNeighbor(I2, 3);
  I3.addNeighbor(I4, 8);
  I3.addNeighbor(I5, 5);

  I4.addNeighbor(I1, 1);
  I4.addNeighbor(I6, 6);
  I4.addNeighbor(I3, 8);

  I5.addNeighbor(I6, 7);
  I5.addNeighbor(I3, 5);
  I5.addNeighbor(I2, 4);

  I6.addNeighbor(I4, 6);
  I6.addNeighbor(I5, 7);

  Map<Integer, Vertex> vertices2 = new HashMap<Integer, Vertex>();
  vertices2.put(I1.id, I1);
  vertices2.put(I2.id, I2);
  vertices2.put(I3.id, I3);
  vertices2.put(I4.id, I4);
  vertices2.put(I5.id, I5);
  vertices2.put(I6.id, I6);

  Graphe<Integer> graphe2 = new Graphe<Integer>(vertices2);
  System.out.println("GRAPHE :");
  graphe2.printGraph();
  graphe2.executeOnetoAll(1);
  graphe2.executeOnetoOne(4, 5);
  graphe2.getAllDistances();

  /**
  * ** OUTPUT *****
 
 
GRAPHE :
(A)---1--->(B)
(A)---2--->(D)
(A)---3--->(E)
(B)---6--->(C)
(B)---1--->(A)
(B)---8--->(E)
(C)---6--->(B)
(C)---7--->(F)
(D)---4--->(F)
(D)---2--->(A)
(D)---3--->(E)
(E)---8--->(B)
(E)---5--->(F)
(E)---3--->(D)
(E)---3--->(A)
(F)---7--->(C)
(F)---4--->(D)
(F)---5--->(E)

Paths : from A to C
A, B, C, 
Total cost : 7

Distances : 
vertex A cost =  0
vertex B cost =  1
vertex C cost =  7
vertex D cost =  2
vertex E cost =  3
vertex F cost =  6
Paths : from B to F
B, A, D, F, 
Total cost : 7

Distances : 
vertex A cost =  1
vertex B cost =  0
vertex C cost =  6
vertex D cost =  3
vertex E cost =  4
vertex F cost =  7

GRAPHE :
(1)---3--->(3)
(1)---2--->(2)
(1)---1--->(4)
(2)---3--->(3)
(2)---4--->(5)
(2)---2--->(1)
(3)---5--->(5)
(3)---3--->(2)
(3)---8--->(4)
(3)---3--->(1)
(4)---8--->(3)
(4)---1--->(1)
(4)---6--->(6)
(5)---5--->(3)
(5)---4--->(2)
(5)---7--->(6)
(6)---7--->(5)
(6)---6--->(4)

Paths : from 4 to 5
4, 1, 2, 5, 
Total cost : 7

Distances : 
vertex 1 cost =  1
vertex 2 cost =  3
vertex 3 cost =  4
vertex 4 cost =  0
vertex 5 cost =  7
vertex 6 cost =  6



  */
}

}
