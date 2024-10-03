from functools import cmp_to_key


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def orientation(p1, p2, p3):
    # Slope of line segment (p1, p2): σ = (y2 - y1)/(x2 - x1)
    # Slope of line segment (p2, p3): τ = (y3 - y2)/(x3 - x2)
    #
    # If  σ > τ, the orientation is clockwise (right turn)
    #
    # Using above values of σ and τ, we can conclude that,
    # the orientation depends on sign of  below expression:
    #
    # (y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)
    #
    # Above expression is negative when σ < τ, i.e.,  counterclockwise
    val = (float(p2.y - p1.y) * (p3.x - p2.x)) - (float(p2.x - p1.x) * (p3.y - p2.y))
    if val > 0:
        # Clockwise orientation
        return 1

    elif val < 0:
        # Counterclockwise orientation
        return 2

    else:
        # Collinear orientation
        return 0


def distSquare(p1, p2):
    return ((p1.x - p2.x) ** 2 +
            (p1.y - p2.y) ** 2)


def compare(p1, p2):
    # Find orientation
    o = orientation(p0, p1, p2)
    if o == 0:
        if distSquare(p0, p2) >= distSquare(p0, p1):
            return -1
        else:
            return 1
    else:
        if o == 2:
            return -1
        else:
            return 1


def ConvexHull(points, n):
    # Find the bottommost point
    ymin = points[0].y
    minimum = 0
    for i in range(1, n):
        y = points[i].y

        # Pick the bottom-most or choose the left
        # most point in case of tie
        if ((y < ymin) or
                (ymin == y and points[i].x < points[minimum].x)):
            ymin = points[i].y
            minimum = i

    # Place the bottom-most point at first position
    points[0], points[minimum] = points[minimum], points[0]

    # Sort n-1 points with respect to the first point.
    # A point p1 comes before p2 in sorted output if p2
    # has larger polar angle (in counterclockwise
    # direction) than p1
    p0 = points[0]
    sorted_points = sorted(points, key=cmp_to_key(compare))

    # If two or more points make same angle with p0,
    # Remove all but the one that is farthest from p0
    # Remember that, in above sorting, our criteria was
    # to keep the farthest point at the end when more than
    # one points have same angle.
    m = 1  # Initialize size of modified array
    for i in range(1, n):
        # Keep removing i while angle of i and i+1 is same
        # with respect to p0
        while ((i < n - 1) and
               (orientation(p0, sorted_points[i], sorted_points[i + 1]) == 0)):
            i += 1

        sorted_points[m] = sorted_points[i]
        m += 1  # Update size of modified array

    # If modified array of points has less than 3 points,
    # convex hull is not possible
    if m < 3:
        return

    S = [sorted_points[0], sorted_points[1], sorted_points[2]]

    # Process remaining n-3 points
    for i in range(3, m):
        # Keep removing top while the angle formed by
        # points next-to-top, top, and points[i] makes
        # a non-left turn
        while ((len(S) > 1) and
               (orientation(S[-2], S[-1], sorted_points[i]) != 2)):
            S.pop()
        S.append(sorted_points[i])

    S2 = S.copy()
    # Now stack has the output points,
    # print contents of stack
    while S:
        p = S[-1]
        print("(" + str(p.x) + ", " + str(p.y) + ")")
        S.pop()

    return S2


def visualize(points, convex_hull_points):
    from matplotlib import pyplot as plt
    import numpy as np
    x_co = []
    y_co = []
    for point in points:
        x_co.append(point.x)
        y_co.append(point.y)
    plt.scatter(np.array(x_co), np.array(y_co))

    convex_x_co = []
    convex_y_co = []
    for point in convex_hull_points:
        convex_x_co.append(point.x)
        convex_y_co.append(point.y)
    plt.plot(np.array(convex_x_co), np.array(convex_y_co))

    plt.show()


if __name__ == "__main__":
    n = int(input("Enter number of points followed by points: "))

    points = []  # List of Points

    p0 = Point(0, 0)

    for i in range(n):
        x, y = list(map(int, input().split()))
        points.append(Point(x, y))

    convex_hull_points = ConvexHull(points, n)

    # Optional, please comment this line if you don't want to visualize
    visualize(points, convex_hull_points)
