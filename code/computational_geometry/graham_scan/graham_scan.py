# Part of Cosmos by OpenGenus Foundation 


#!/usr/bin/env python3

import functools

@functools.total_ordering
class Point:
    """A point class for use in the Graham Scan."""

    def __init__(self, key, x, y):
        self.key = key
        self.x = x
        self.y = y

    def get_key(self):
        """Returns the key"""
        return self.key

    def get_x(self):
        """Returns the X Coordinate"""
        return self.x

    def get_y(self):
        """Returns the Y Coordinate"""
        return self.y

    def __str__(self):
        """Returns a string containing instance information."""
        f = lambda n: int(n) if n.is_integer() else n
        return str(self.key) + ',\t' + str(f(self.x)) + ',\t' + str(f(self.y))

    __lt__ = lambda self, other: self.y < other.y if (self.x == other.x) else self.x < other.x
    __eq__ = lambda self, other: self.x == other.x and self.y == other.y


def read_input_file(file):
    """Returns an array of points from the input file.
    Assumes that points will be floats.
    """
    points_array = []
    with open(file, 'r') as f:
        for line in f:
            key, x, y = ''.join(line.split()).split(',')
            points_array.append(Point(key, float(x), float(y)))

    return points_array


def print_out_file(point_array, outfile):
    """Prints the output file containing the keys of the points in the convex hull."""
    with open(outfile, 'wb') as f:
        out = ",".join((x.get_key() for x in point_array))
        f.write(bytes(out, "utf-8"))


def sort_points(point_array):
    """Return point_array sorted by leftmost first, then by slope, ascending."""

    def slope(y):
        """returns the slope of the 2 points."""
        x = point_array[0]
        return (x.get_y() - y.get_y()) / \
               (x.get_x() - y.get_x())

    point_array.sort()  # put leftmost first
    point_array = point_array[:1] + sorted(point_array[1:], key=slope)
    return point_array


def graham_scan(point_array):
    """Takes an array of points to be scanned.
    Returns an array of points that make up the convex hull surrounding the points passed in in point_array.
    """

    def cross_product_orientation(a, b, c):
        """Returns the orientation of the set of points.
        >0 if x,y,z are clockwise, <0 if counterclockwise, 0 if co-linear.
        """

        return (b.get_y() - a.get_y()) * \
                (c.get_x() - a.get_x()) - \
                (b.get_x() - a.get_x()) * \
                (c.get_y() - a.get_y())

    # convex_hull is a stack of points beginning with the leftmost point.
    convex_hull = []
    sorted_points = sort_points(point_array)
    for p in sorted_points:
        # if we turn clockwise to reach this point, pop the last point from the stack, else, append this point to it.
        while len(convex_hull) > 1 and cross_product_orientation(convex_hull[-2], convex_hull[-1], p) >= 0:
            convex_hull.pop()
        convex_hull.append(p)
    # the stack is now a representation of the convex hull, return it.
    return convex_hull

if __name__ == '__main__':
    points = read_input_file('input.txt')
    hull = graham_scan(points)
    print_out_file(hull, 'output.txt')
