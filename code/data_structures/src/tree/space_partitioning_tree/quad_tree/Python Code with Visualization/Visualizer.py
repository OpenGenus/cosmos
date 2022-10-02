# Part of Cosmos by OpenGenus Foundation
from QuadTree import *

if __name__ == '__main__':
    boundary = Rectangle(200, 200, 150, 150)
    QT = QuadTree(boundary, 1)
    pointsList = [Point(240, 240), Point(150, 150), Point(300, 215), Point(200, 266), Point(333, 190)]
    for point in pointsList:
        QT.insert(point)
    QT.visualize(pointsList)
