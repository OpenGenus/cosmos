# Part of Cosmos by OpenGenus Foundation

import random
import math

# Euclidean Distance
def euclidean(x, y):
    return math.sqrt(sum([(a - b) ** 2 for a, b in zip(x, y)]))


# K-Centers Algorithm
def k_centers(vertices, k, distance=euclidean):
    centers = set()
    centers.add(random.choice(vertices))
    for i in range(k - 1):
        min_distance = dict()
        for vertex in vertices:
            if vertex not in centers:
                min_distance[vertex] = min(
                    [distance(vertex, center) for center in centers]
                )
        next_center = max(min_distance, key=min_distance.get)
        centers.add(next_center)
    return centers
