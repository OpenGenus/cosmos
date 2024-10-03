//Part of Cosmos by OpenGenus Foundation

using System;
using System.Collections.Generic;


namespace BFS
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

        private void bfsHelper(int current, Dictionary<int, bool> visited, Queue<int>nodeQueue)
        {
            if (visited[current])
                return;
            visited[current] = true;
            Console.Out.WriteLine(current);

            foreach(int node in adjList[current])
            {
                if (visited[node] == false)
                    nodeQueue.Enqueue(node);
            }

            if (nodeQueue.Count != 0)
            {

                bfsHelper(nodeQueue.Dequeue(), visited, nodeQueue);
            }

        }


        /// <summary>
        /// Outputs the breadth first traversal of the vertices reachable from the given node
        /// </summary>
        /// <param name="startNode">The node to start the bfs from</param>
        public void BFS(int startNode)
        {
            Dictionary<int, bool> visitDict = new Dictionary<int, bool>();
            foreach (int key in adjList.Keys)
                visitDict.Add(key, false);
            Queue<int> nextNodes = new Queue<int>();
            bfsHelper(startNode, visitDict, nextNodes);
        }
    }

    //Testing with this tree:
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
    // 3
    // 4
    // 5
    // 6
    // 7
    // Test 2:
    // 2
    // 1
    // 4
    // 5
    // 3
    // 6
    // 7


    class BFSTest
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

            Console.Out.WriteLine("Test 1:");
            testGraph.BFS(1);

            Console.Out.WriteLine("Test 2:");
            testGraph.BFS(2);
            return 0;
        }
    }

}
