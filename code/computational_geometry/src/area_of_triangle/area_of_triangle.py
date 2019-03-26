#! /usr/local/bin/python3

# Part of Cosmos by OpenGenus Foundation
# Programmer: Amariah Del Mar
# Date Written: October 6th, 2017
# Function to find area of a triangle using three different vertices.


class MyPoint:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y


def area_of_triangle(a, b, c):
    area = 0.5 * abs(
        (a.x * b.y)
        + (b.x * c.y)
        + (c.x * a.y)
        - (a.x * c.y)
        - (c.x * b.y)
        - (b.x * a.y)
    )
    return area


def test(a, b, c):
    a.x, a.y = 3, 50
    b.x, b.y = -6, 8
    c.x, c.y = 8, 0
    return a, b, c


if __name__ == "__main__":
    pt1 = MyPoint()
    pt2 = MyPoint()
    pt3 = MyPoint()
    pt1, pt2, pt3 = test(pt1, pt2, pt3)
    tri_area = area_of_triangle(pt1, pt2, pt3)
    print(
        "The area of a triangle with vertices ({},{}), ({},{}) and ({},{}) is {}.".format(
            pt1.x, pt1.y, pt2.x, pt2.y, pt3.x, pt3.y, tri_area
        )
    )
