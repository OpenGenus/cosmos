using System;
using System.Collections.Generic;
using System.Linq;

namespace TopologicalSort {
    static class Program {
        static void Main() {
            //
            // digraph G {
            //   "7"  -> "11"
            //   "7"  -> "8"
            //   "5"  -> "11"
            //   "3"  -> "8"
            //   "3"  -> "10"
            //   "11" -> "2"
            //   "11" -> "9"
            //   "11" -> "10"
            //   "8"  -> "9"
            // }

            var ret = TopologicalSort(
                new HashSet<int>(new[] {7, 5, 3, 8, 11, 2, 9, 10}),
                new HashSet<Tuple<int, int>>(
                    new [] {
                        Tuple.Create(7, 11),
                        Tuple.Create(7, 8),
                        Tuple.Create(5, 11),
                        Tuple.Create(3, 8),
                        Tuple.Create(3, 10),
                        Tuple.Create(11, 2),
                        Tuple.Create(11, 9),
                        Tuple.Create(11, 10),
                        Tuple.Create(8, 9)
                    }
                )
            );
            System.Diagnostics.Debug.Assert(ret.SequenceEqual(new[] {7, 5, 11, 2, 3, 8, 9, 10}));
        }

        /// <summary>
        /// Topological Sorting (Kahn's algorithm) 
        /// </summary>
        /// <remarks>https://en.wikipedia.org/wiki/Topological_sorting</remarks>
        /// <typeparam name="T"></typeparam>
        /// <param name="nodes">All nodes of directed acyclic graph.</param>
        /// <param name="edges">All edges of directed acyclic graph.</param>
        /// <returns>Sorted node in topological order.</returns>
        static List<T> TopologicalSort<T>(HashSet<T> nodes, HashSet<Tuple<T, T>> edges) where T : IEquatable<T> {
            // Empty list that will contain the sorted elements
            var L = new List<T>();

            // Set of all nodes with no incoming edges
            var S = new HashSet<T>(nodes.Where(n => edges.All(e => e.Item2.Equals(n) == false)));

            // while S is non-empty do
            while (S.Any()) {

                //  remove a node n from S
                var n = S.First();
                S.Remove(n);

                // add n to tail of L
                L.Add(n);

                // for each node m with an edge e from n to m do
                foreach (var e in edges.Where(e => e.Item1.Equals(n)).ToList()) {
                    var m = e.Item2;

                    // remove edge e from the graph
                    edges.Remove(e);

                    // if m has no other incoming edges then
                    if (edges.All(me => me.Item2.Equals(m) == false)) {
                        // insert m into S
                        S.Add(m);
                    }
                }
            }

            // if graph has edges then
            if (edges.Any()) {
                // return error (graph has at least one cycle)
                return null;
            } else {
                // return L (a topologically sorted order)
                return L;
            }
        }
    }
}