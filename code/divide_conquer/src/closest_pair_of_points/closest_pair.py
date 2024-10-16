#  divide conquer | structure to represent a point | Python
#  Part of Cosmos by OpenGenus Foundation

import math


def dist(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)


def closest_pair(ax, ay):
    # It's quicker to assign variable
    ln_ax = len(ax)

    if ln_ax <= 3:
        # A call to bruteforce comparison
        return brute(ax)

    # Division without remainder, need int
    mid = ln_ax // 2

    # Two-part split
    Qx = ax[:mid]
    Rx = ax[mid:]

    # Determine midpoint on x-axis
    midpoint = ax[mid][0]
    Qy = list()
    Ry = list()

    # split ay into 2 arrays using midpoint
    for x in ay:
        if x[0] <= midpoint:
            Qy.append(x)
        else:
            Ry.append(x)

    # Call recursively both arrays after split
    (p1, q1, mi1) = closest_pair(Qx, Qy)
    (p2, q2, mi2) = closest_pair(Rx, Ry)

    # Determine smaller distance between points of 2 arrays
    if mi1 <= mi2:
        d = mi1
        mn = (p1, q1)
    else:
        d = mi2
        mn = (p2, q2)

    # Call function to account for points on the boundary
    (p3, q3, mi3) = closest_split_pair(ax, ay, d, mn)

    # Determine smallest distance for the array
    if d <= mi3:
        return mn[0], mn[1], d
    else:
        return p3, q3, mi3


def closest_split_pair(p_x, p_y, delta, best_pair):
    # store length - quicker
    ln_x = len(p_x)

    # select midpoint on x-sorted array
    mx_x = p_x[ln_x // 2][0]

    # Create a subarray of points not further than delta from
    # midpoint on x-sorted array
    s_y = [x for x in p_y if mx_x - delta <= x[0] <= mx_x + delta]
    # assign best value to delta
    best = delta
    # store length of subarray for quickness
    ln_y = len(s_y)
    for i in range(ln_y - 1):
        for j in range(i + 1, min(i + 7, ln_y)):
            p, q = s_y[i], s_y[j]
            dst = dist(p, q)
            if dst < best:
                best_pair = p, q
                best = dst
    return best_pair[0], best_pair[1], best


def solution(a):
    ax = sorted(a, key=lambda x: x[0])  # Presorting x-wise
    ay = sorted(a, key=lambda x: x[1])  # Presorting y-wise
    p1, p2, mi = closest_pair(ax, ay)  # Recursive D&C function
    return (p1, p2, mi)


def brute(ax):
    mi = dist(ax[0], ax[1])
    p1 = ax[0]
    p2 = ax[1]
    ln_ax = len(ax)
    if ln_ax == 2:
        return p1, p2, mi
    for i in range(ln_ax - 1):
        for j in range(i + 1, ln_ax):
            if i != 0 and j != 1:
                d = dist(ax[i], ax[j])
                if d < mi:  # Update min_dist and points
                    mi = d
                    p1, p2 = ax[i], ax[j]
    return p1, p2, mi


solution_tuple = solution(
    [
        (0, 0),
        (7, 6),
        (2, 20),
        (12, 5),
        (16, 16),
        (5, 8),
        (19, 7),
        (14, 22),
        (8, 19),
        (7, 29),
        (10, 11),
        (1, 13),
    ]
)
print("Point 1 =>", solution_tuple[0])
print("Point 2 =>", solution_tuple[1])
print("Distance =>", solution_tuple[2])
