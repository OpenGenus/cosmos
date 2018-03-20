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

    T _id;
    private Map<Vertex, Integer> neighbors;
    Integer cost;

    public Vertex(T id) {
      this._id = id;
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
      return _id;
    }

    public void setId(T _id) {
      this._id = _id;
    }

    public void addNeighbor(Vertex neighbor, Integer cost) {
      this.neighbors.put(neighbor, cost);

    }

  }

  public static class Graphe<T> {

    private Map<T, Vertex> _vertices;
    public Queue<Vertex> _visited;
    public Deque<T> _paths = new ArrayDeque<>();
    public HashMap<T, Integer> distances;
    public HashMap<T, T> preds;

    public Graphe(Map<T, Vertex> vertices) {
      this._vertices = vertices;
      this.preds = new HashMap<>();
      this._paths = new ArrayDeque<>();
      this.distances = new HashMap<>();
      this._visited = new PriorityQueue(new Comparator<Vertex>() {
        @Override
        public int compare(Vertex o1, Vertex o2) {
          return o1.cost.compareTo(o2.cost);
        }
      });

    }

    public void initDistance() {
      this._vertices.keySet().forEach((key) -> {
        distances.put(key, Integer.MAX_VALUE);
        this._vertices.get(key).setCost(Integer.MAX_VALUE);
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
        current = this._visited.remove();
      } catch (Exception e) {

      }
      return current;

    }

    public Map<T, Vertex> getVertices() {
      return _vertices;
    }

    public void setVertices(Map<T, Vertex> vertices) {
      this._vertices = vertices;

    }

    public void executeOnetoAll(T src) {

      this.initStart(src);
      Vertex origin = this._vertices.get(src);
      if (origin != null) {
        origin.setCost(0);
        this._visited.add(this._vertices.get(origin._id));

        while (!this._visited.isEmpty()) {

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
        if (this.getCurrentDistance((T) v._id) > (this.getCurrentDistance((T) u._id) + cout)) {
          this.distances.put((T) v._id, (this.getCurrentDistance((T) u._id) + cout));
          v.setCost((this.getCurrentDistance((T) u._id) + cout));
          this._visited.add(v);
          this.preds.put((T) v._id, (T) u._id);

        } else {
        }
      });

    }

    public void executeOnetoOne(T src, T goal) { // execution de l'algo sur n chemin de depart

    this.executeOnetoAll(src);
    Vertex origin = this._vertices.get(src);
    Vertex dest = this._vertices.get(goal);

    if (origin != null && dest != null) {
      T step = goal;
      while (origin._id != step) {
        this._paths.add(step);
        step = this.preds.get(step);
      }
      this._paths.add(src);

      this.PrintPaths(src, goal);
    } else {
      System.out.println("Path not existing");
    }

  }

  public void PrintPaths(T src, T dest) {
    System.out.println("Paths : from " + src + " to " + dest);
    while (!this._paths.isEmpty()) {
      System.out.print(this._paths.removeLast() + ", ");

    }
    System.out.println();
    System.out.println("Total cost : " + this.distances.get(dest));
  }

}

/**
* @param args the command line arguments
*/
public static void main(String[] args) {

  System.out.println("GRAPHE :");
  System.out.println(" (A)--1--(B)----6---(C)");
  System.out.println(" | \\     |           | ");
  System.out.println(" |  \\    |           | ");
  System.out.println(" 2   3   8           7 ");
  System.out.println(" |    \\  |           | ");
  System.out.println(" |     \\ |           | ");
  System.out.println("(D)-3--(E)-----5----(F)");
  System.out.println(" |                   |");
  System.out.println(" |                   |");
  System.out.println(" ----------4----------");
  System.out.println("");

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
  vertices.put(v1._id, v1);
  vertices.put(v2._id, v2);
  vertices.put(v3._id, v3);
  vertices.put(v4._id, v4);
  vertices.put(v5._id, v5);
  vertices.put(v6._id, v6);

  Graphe<String> graphe = new Graphe<String>(vertices);
  graphe.executeOnetoAll("A");
  graphe.executeOnetoOne("A", "C");
  graphe.getAllDistances();

  graphe.executeOnetoOne("B", "F");
  graphe.getAllDistances();

  /* Integer entries -------------------------------------------*/
  System.out.println("");
  System.out.println("GRAPHE :");
  System.out.println(" (1)--1--(4)----6---(6)");
  System.out.println(" | \\     |           | ");
  System.out.println(" |  \\    |           | ");
  System.out.println(" 2   3   8           7 ");
  System.out.println(" |    \\  |           | ");
  System.out.println(" |     \\ |           | ");
  System.out.println("(2)-3--(3)-----5----(5)");
  System.out.println(" |                   |");
  System.out.println(" |                   |");
  System.out.println(" ----------4----------");
  System.out.println("");

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
  vertices2.put(I1._id, I1);
  vertices2.put(I2._id, I2);
  vertices2.put(I3._id, I3);
  vertices2.put(I4._id, I4);
  vertices2.put(I5._id, I5);
  vertices2.put(I6._id, I6);

  Graphe<Integer> graphe2 = new Graphe<Integer>(vertices2);
  graphe2.executeOnetoAll(1);
  graphe2.executeOnetoOne(4, 5);
  graphe2.getAllDistances();

  /**
  * ** OUTPUT *****
  */
  
  /*
  GRAPHE :
  (A)--1--(B)----6---(C)
  | \     |           |
  |  \    |           |
  2   3   8           7
  |    \  |           |
  |     \ |           |
  (D)-3--(E)-----5----(F)
  |                   |
  |                   |
  ----------4----------

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
  (1)--1--(4)----6---(6)
  | \     |           |
  |  \    |           |
  2   3   8           7
  |    \  |           |
  |     \ |           |
  (2)-3--(3)-----5----(5)
  |                   |
  |                   |
  ----------4----------

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
