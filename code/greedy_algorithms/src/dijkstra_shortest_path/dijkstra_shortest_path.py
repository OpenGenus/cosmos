# Part of Cosmos by OpenGenus Foundation
def dijkstra(graph, source):

    vertices, edges = graph
    dist = dict()
    previous = dict()

    for vertex in vertices:
        dist[vertex] = float("inf")
        previous[vertex] = None

    dist[source] = 0
    Q = set(vertices)

    while len(Q) > 0:
        u = minimum_distance(dist, Q)
        print("Currently considering", u, "with a distance of", dist[u])
        Q.remove(u)

        if dist[u] == float("inf"):
            break

        n = get_neighbours(graph, u)
        for vertex in n:
            alt = dist[u] + dist_between(graph, u, vertex)
            if alt < dist[vertex]:
                dist[vertex] = alt
                previous[vertex] = u

    return previous
