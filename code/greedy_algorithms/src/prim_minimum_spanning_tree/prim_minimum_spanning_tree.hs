-- Author: Matthew McAlister
-- Title: Prim's Minimum Spanning Tree Algorithm in Haskell

import qualified Data.List as List

type Edge = (Char, Char, Int)
type Graph = [Edge]

-- This is a sample graph that can be used.
-- graph :: Graph
-- graph = [('a','b',4),('a','h',10),('b','a',4),('b','c',8),('b','h',11),('c','b',8),('c','d',7),('c','f',4),('c','i',2),('d','c',7),('d','e',9),('d','f',14),('e','d',9),('e','f',10),('f','c',4),('f','d',14),('f','e',10),('f','g',2),('g','f',2),('g','h',1),('g','i',6),('h','a',10),('h','b',11),('h','g',1),('h', 'i',7),('i','c',2),('i','g',6),('i','h',7)]

prim :: Graph -> Graph
prim g = List.delete ('a','z', 0) (treeBuilder g "" (getGraphNodes g))

weight :: Graph -> Int
weight g = weight' g

weight':: Graph -> Int
-- ^ Returns the weight of the MST
weight' [] = 0;
weight' (g:gs) = third g + weight' gs

first :: Edge -> Char
-- ^ Returns the first value from the tuple
first (x,_,_) = x

second :: Edge -> Char
-- ^ Returns the second value from the tuple
second (_,x,_) = x

third :: Edge -> Int
-- ^ Returns the third value from the tuple
third (_,_,x) = x

lowestWeight :: [Edge] -> Edge
-- ^ Returns the Edge with the lowest weight from a list of Edges
lowestWeight [] = ('a','z',0)
lowestWeight (v:vs) = determineLowerWeight v (if null vs then v else lowestWeight vs)

determineLowerWeight :: Edge -> Edge -> Edge
-- ^ Returns the Edge with the lower weight
determineLowerWeight m n
  | third m < third n = m
  | third n < third m = n
  | third n == third m = m

reverseEdges :: [Edge] -> [Edge]
-- ^ Returns a [Edge] with the first and second reversed
reverseEdges [] = []
reverseEdges (e:es) = [reverseEdge e] ++ reverseEdges es ++ []

reverseEdge :: Edge -> Edge
-- ^ Returns an Edge with the first and second reversed
reverseEdge e = (second e, first e, third e)

getGraphNodes :: Graph -> [Char]
-- ^ Builds a list of unique Nodes
getGraphNodes [] = []
getGraphNodes (g:gs) = List.nub (first g:second g:[] ++ getGraphNodes gs ++ [])

getConnectedEdges :: [Char] -> Graph -> [Edge]
-- ^ Returns a list of Edges connected to the supplied Node from the supplied Graph
getConnectedEdges c g = [x | x <- g, first x `elem` c || second x `elem` c]

reduceGraph :: Graph -> Graph
-- ^ Returns a Graph with unique Edges by comparing the current edge to the reverse of all other Edges
reduceGraph [] = []
reduceGraph g = reduceGraph' g ++ reduceGraph (tail g) ++ []

reduceGraph' :: [Edge] -> [Edge]
-- ^ Compares this Edge to the reverse of the other Edges and returns the appropriate unique output
reduceGraph' (g:gs) = if notElem g (reverseEdges gs) then [g] else []

removeUsedNodeFromList :: Char -> [Char] -> [Char]
removeUsedNodeFromList c l = List.delete c l

treeBuilder :: Graph -> [Char] -> [Char] -> [Edge]
-- ^ Take a Graph, a list of Chars that are USED, and a list of Chars that are UNUSED and returns a tree
treeBuilder g cus cun = if null cun then [] else [lowestWeightEdge g cus cun] ++ treeBuilder g (treeBuilder'addList g cus cun) (treeBuilder'delList g cus cun) ++ []

treeBuilder'addList :: Graph -> [Char] -> [Char] -> [Char]
-- ^ Adds the Nodes from the lowestWeightEdge to the USED list
treeBuilder'addList g cus cun = addEdgeNodesToList (lowestWeightEdge g cus cun) cus

treeBuilder'delList :: Graph -> [Char] -> [Char] -> [Char]
-- ^ Deletes the Nodes from the lowestWeightEdge to the UNUSED list
treeBuilder'delList g cus cun = delEdgeNodesFromList (lowestWeightEdge g cus cun) cun

addEdgeNodesToList :: Edge -> [Char] -> [Char]
-- ^ Adds the Nodes from an Edge to a List of Chars
addEdgeNodesToList n l = first n: second n : l

delEdgeNodesFromList :: Edge -> [Char] -> [Char]
-- ^ Deletes the Nodes from an Edge from a List of Chars
delEdgeNodesFromList n l = delFirst n (delSecond n l)

delFirst :: Edge -> [Char] -> [Char]
-- ^ Deletes the first Edge node from the list
delFirst n l = List.delete (first n) l

delSecond :: Edge -> [Char] -> [Char]
-- ^ Deletes the second Edge node from the list
delSecond n l = List.delete (second n) l

lowestWeightEdge :: Graph -> [Char] -> [Char] -> Edge
-- ^ From a Graph, a list of USED nodes, and a list of UNUSED nodes, the lowest edge weight is determined
lowestWeightEdge g cus cun = lowestWeight (getEdges g cus cun)

getEdges :: Graph -> [Char] -> [Char] -> [Edge]
-- ^ From a Graph, a list of USED nodes, and a list of UNUSED nodes, the connected Edges are determined
getEdges g cus cun = [x | x <- getConnectedEdges cus g, first x `elem` cun || second x `elem` cun]
