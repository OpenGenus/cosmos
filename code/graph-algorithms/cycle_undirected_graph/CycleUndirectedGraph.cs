// Part of Cosmos by OpenGenus Foundation

using System;
using System.Collections.Generic;

namespace CycleUndirectedGraph
{
    class Graph
    {
        protected Dictionary<int, HashSet<int>> adjList;

        public Graph()
        {
            adjList = new Dictionary<int, HashSet<int>>();
        }

        /// <summary>
        /// Adds an edge from node1 to node2 in the graph
        /// </summary>
        public void addEdge(int node1, int node2)
        {
            if (!adjList.ContainsKey(node1))
                adjList.Add(node1, new HashSet<int>());
            if (!adjList.ContainsKey(node2))
                adjList.Add(node2, new HashSet<int>());

            adjList[node1].Add(node2);
            adjList[node2].Add(node1);
        }

        private bool cyclicHelper(int current, Dictionary<int, bool> visited)
        {
            visited[current] = true;

            foreach(int node in adjList[current])
            {
                if (!visited[node])
                    if (cyclicHelper(node, visited, current))
                        return true;
            }

            return false;
        }

        private bool cyclicHelper(int current, Dictionary<int, bool> visited, int parent)
        {
            visited[current] = true;

            foreach (int node in adjList[current])
            {
                if (!visited[node])
                {
                    if (cyclicHelper(node, visited, current))
                        return true;
                }
                else if (node != parent)
                    return true;
            }

            return false;
        }

        /// <summary>
        /// Returns true if the graph contains a cycle, false otherwise
        /// </summary>
        public bool isCyclic()
        {
            if (adjList.Count == 0)
                return false;

            Dictionary<int, bool> visitDict = new Dictionary<int, bool>();

            foreach (int key in adjList.Keys)
                visitDict.Add(key, false);

            List<int> keyListCopy = new List<int>(visitDict.Keys);

            foreach (int key in keyListCopy)
            {
                if (!visitDict[key])
                    if (cyclicHelper(key, visitDict))
                        return true;
            }

            return false;
        }
    }

    // Testing with this graph first:
    // 1 - 0 - 3
    // |  /    |
    // 2       4
    // Followed by this graph:
    // 0 - 1 - 2

    // Expected Output:
    // Test 1:
    // True
    // Test 2:
    // False
    class UndirectedCycleTest
    {
        static int Main(string[] args)
        {
            Graph testGraph = new Graph();
            testGraph.addEdge(1, 0);
            testGraph.addEdge(1, 2);
            testGraph.addEdge(2, 0);
            testGraph.addEdge(0, 3);
            testGraph.addEdge(3, 4);
            Console.Out.WriteLine("Test 1:");
            Console.Out.WriteLine(testGraph.isCyclic());

            testGraph = new Graph();
            testGraph.addEdge(0, 1);
            testGraph.addEdge(1, 2);
            Console.Out.WriteLine("Test 2:");
            Console.Out.WriteLine(testGraph.isCyclic());
            return 0;
        }
    }
}
