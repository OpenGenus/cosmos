//Part of Cosmos by OpenGenus Foundation

using System;
using System.Collections.Generic;


namespace CycleDirectedGraph
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
        /// <param name="node1"></param>
        /// <param name="node2"></param>
        public void addEdge(int node1, int node2)
        {
            if (!adjList.ContainsKey(node1))
                adjList.Add(node1, new HashSet<int>());

            adjList[node1].Add(node2);
        }

        private bool cyclicHelper(int current, Dictionary<int, bool> visited, Dictionary<int, bool> recStack)
        {
            if(!visited.ContainsKey(current))
                return false;
            if(!visited[current])
            {
                visited[current] = true;
                recStack[current] = true;

                foreach (int node in adjList[current])
                {
                    if (!visited.ContainsKey(node))
                        continue;
                    if (!visited[node] && cyclicHelper(node, visited, recStack))
                        return true;
                    else if (recStack[node])
                        return true;
                }
            }
            recStack[current] = false;
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
            Dictionary<int, bool> recurDict = new Dictionary<int, bool>();

            foreach (int key in adjList.Keys)
            {
                visitDict.Add(key, false);
                recurDict.Add(key, false);
            }

            List<int> keyListCopy = new List<int>(visitDict.Keys);

            foreach(int key in keyListCopy)
            {
                if (!visitDict[key])
                    if (cyclicHelper(key, visitDict, recurDict))
                        return true;
                    
            }
            return false;
        }
    }


    // Testing with this graph first:
    //      3
    //      |
    // 1 -> 2 -> 5 -> 6
    // Followed by this graph
    //      3
    //    / |
    //  <
    // 1 -> 2 -> 5 -> 6

    // Expected Output:
    // Test 1:
    // False
    // Test 2:
    // True
    class DirectedCycleTest
    {
        static int Main(string[] args)
        {
            Graph testGraph = new Graph();
            testGraph.addEdge(1, 2);
            testGraph.addEdge(2, 3);
            testGraph.addEdge(2, 5);
            testGraph.addEdge(5, 6);
            Console.Out.WriteLine("Test 1:");
            Console.Out.WriteLine(testGraph.isCyclic());

            testGraph.addEdge(3, 1);
            Console.Out.WriteLine("Test 2:");
            Console.Out.WriteLine(testGraph.isCyclic());
            return 0;
        }
    }
}
