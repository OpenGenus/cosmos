"""
Betweenness Centrality
Alex Day
Part of Cosmos by OpenGenus Foundation

Based on the paper:
Brandes, Ulrik. "A faster algorithm for betweenness centrality." Journal of mathematical sociology 25.2 (2001): 163-177.
"""
from collections import defaultdict
import numpy as np
from queue import Queue
import networkx as nx


def betweenness_centrality(G, num_pivots: int = None):
    """
    Return the betweenness centrality for every node in the given graph.

    Args
    ----
    G (networkx.Graph): Unweighted graph to calculate the betweenness on
    num_pivots (int, Optional): Number of pivots to use when approximating
                                betweenness. Higher values give better
                                approximations at the cost of more computation

    Returns
    -------
    Dict[int, float]: Mapping of nodes to their betweenness centrality
    """

    # Define a dict for all betweenness centrailities
    Cb = defaultdict(int)

    # If a number of pivots was passed in define a random subset of G
    # to start searching from
    if num_pivots:
        starting_nodes = np.random.choice(G, size=(num_pivots))

    # If no pivots were passed through then the starting set is all
    # nodes in the graph
    else:
        starting_nodes = G

    # Loop through each node in the starting set and calculate the
    # Betweenness centrality for each node with respect to s. This value
    # is then appended to a running sum for each node. This is calculated
    # by using BFS to find the geodesic path to each node from s
    for s in starting_nodes:
        # Stack to store the closed set for the BFS. This will eventually
        # return the nodes in the order that we calculate the betweenness
        # centrality of so that we calculate from the furthest to the
        # closest. Or at least we never calculate a closer node before
        # a node further away.
        S = []
        # Mapping of nodes to all their parents
        P = defaultdict(list)
        # Shortest path from s to some node
        sigma = defaultdict(int)
        # Define the shortest path from start to start as 1 so to "seed"
        # the array
        sigma[s] = 1
        # d is the "depth" of every node, -1 if a node has not been visited
        # except for the start node which is s by definition
        d = defaultdict(lambda: -1)
        d[s] = 0

        # FIFO Search starting at s
        Q = Queue()
        Q.put(s)
        while not Q.empty():
            # Get the next node to search the neighbors of
            v = Q.get()

            # Add v to the closed set
            S.append(v)

            # For every neighbor of the current node
            for w in G[v]:

                # If w has not been visited before
                if d[w] < 0:
                    # Add w to the list of nodes to visit
                    Q.put(w)
                    # Update the depth for node w with the current
                    # depth + 1
                    d[w] = d[v] + 1

                # If the v is a direct parent of w then there exists
                # a geodesic path to w from s through v
                if d[w] == d[v] + 1:
                    # Sigma represents the total number of geodesic
                    # paths through w. The total number of geodesic
                    # paths for w is updated to include all geodesic
                    # paths to its parent because there now exits a
                    # geodesic path to w through v by definition
                    sigma[w] = sigma[w] + sigma[v]
                    # Add v as a parent of node w
                    P[w].append(v)

        # Delta is the addition to the centrality betweenness for this
        # iteration of the algorithm
        delta = [0 for v in G]
        # S returns verteces in order of non-increasing distance from s
        while S:
            # Get the next furthest away node from the start
            w = S.pop()
            # For every parent of the current node
            for v in P[w]:
                # THe amount to increase this node is summed over all parents
                # to be the number of paths through the parent over the number
                # of paths through this node scaled by 1 + the number of
                # shortest paths through this node
                delta[v] = delta[v] + (sigma[v] / sigma[w]) * (1 + delta[w])
            # Increment the centrality betweenness for each node except the
            # starting node for this iteration. The value of delta is equal
            # to (for each node) the total number of geodesic paths from s
            # to all nodes including that node over the total number of
            # geodesic paths from s
            if w is not s:
                Cb[w] = Cb[w] + delta[w]

    # Cast the default dict of betweennesses to a regular dict and return it
    return dict(Cb)
