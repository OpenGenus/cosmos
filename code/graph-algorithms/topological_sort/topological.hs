module Topological where

import Data.List

-- Part of Cosmos by OpenGenus

-- Note: this implementation is not the most efficient.
-- With a better DAG datastructure, this would be O(V+E)
-- But if the number of sources of the graph is generally low,
-- this implementation approximates that.
topo' [] _ _ = []
topo' (r:rs) graph nodes = r : (topo' (rs ++ newRoots) graph' nodes')
  where
    nodes' = delete r nodes
    graph' = filter (\(a, b) -> a /= r) graph
    newRoots = filter (\n -> not (n `elem` rs)
                        && all (\(a, b) -> b /= n) graph') nodes'


topo relation list = topo' roots graph nodes
  where
    roots = filter (\n -> all (\(a, b) -> b /= n) graph) nodes
    graph = [(a,b) | a <- list, b <- list, a /= b, a `relation` b]
    nodes = (nub list)

main = print $ [200,199..1] == topo (>=) [1..200]
