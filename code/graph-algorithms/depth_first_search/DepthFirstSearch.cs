// Part of Cosmos by OpenGenus Foundation

using System;
using System.Collections.Generic;

namespace DFS
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

        private void dfsHelper(int current, Dictionary<int, bool> visited)
        {
            visited[current] = true;
            Console.Out.Write(current + "\n");

            foreach (int node in adjList[current])
            {
                if (visited[node] == false)
                    dfsHelper(node, visited);
            }
        }

        /// <summary>
        /// Outputs the depth first traversal of the vertices reachable from the given node
        /// </summary>
        /// <param name="startNode">The node to start the dfs from</param>
        public void DFS(int startNode)
        {
            Dictionary<int, bool> visitDict = new Dictionary<int, bool>();
            foreach (int key in adjList.Keys)
                visitDict.Add(key, false);
            dfsHelper(startNode, visitDict);
        }

    }

    //Testing with this tree:
    // Testing on this tree
    //      1
    //     / \
    //    /   \
    //   2     3
    //  / \   / \
    // 4   5 6   7

    // Expected Output:
    // Test 1:
    // 1
    // 2
    // 4
    // 5
    // 3
    // 6
    // 7
    // Test 2:
    // 2
    // 1
    // 3
    // 6
    // 7
    // 4
    // 5


    class DFSTest
    {
        static int Main(string[] args)
        {
            Graph testGraph = new Graph();
            testGraph.addEdge(1, 2);
            testGraph.addEdge(1, 3);
            testGraph.addEdge(2, 4);
            testGraph.addEdge(2, 5);
            testGraph.addEdge(3, 6);
            testGraph.addEdge(3, 7);

            Console.Out.Write("Test 1:\n");
            testGraph.DFS(1);

            Console.Out.Write("Test 2:\n");
            testGraph.DFS(2);
            return 0;
        }
    }
}