import matplotlib.pyplot as plt
import numpy as np
import math 

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def equal(self, pt):
        if self.x == pt.x and self.y == pt.y:
            return True
        return False

    def __str__(self):
        return "(" + str(self.x) + ","+str(self.y) + ")"


def leftMostPoint(pts):
    if not isinstance(pts, list):
        return False
    
    curr = pts[0]
    for pt in pts[1:]:
        if pt.x == curr.x and pt.y < curr.y:
            curr = pt
        elif pt.x < curr.x and pt.x != curr.x:
            curr = pt
            
    return curr

def cross_product(a, b, c):
    x1 = a.x - b.x
    x2 = a.x - c.x
    y1 = a.y - b.y
    y2 = a.y - c.y
    return y2 * x1 - y1 * x2

def distance(p, p1, p2):
    dist1 = math.hypot(p.x - p1.x, p.y - p1.y)
    dist2 = math.hypot(p.x - p2.x, p.y - p2.y)
    return dist1 - dist2


def iter(pts):
    colinear = list()
    curr_pt = leftMostPoint(pts)
    convex_list = [curr_pt]
    
    for pt1 in pts:
        if curr_pt == pt1:
            continue

        target = pt1
        for pt2 in pts:
            if pt2 == target or pt2 == curr_pt:
                continue
            res = cross_product(curr_pt, target, pt2)  
            if res > 0:
                colinear = list()
                target = pt2
            if res == 0:
                if distance(curr_pt, target, pt2) > 0:
                    colinear.append(pt2)
                else:
                    colinear.append(target)
                    target = pt2

        if target not in convex_list:
            convex_list.append(target)

        if colinear not in convex_list:
            convex_list += colinear

        curr_pt = target

    return convex_list

def main():
    pts = [Point(x, y) for x, y in np.random.rand(1000,2)]
    convex_lst = iter(pts)
    len_convex_pts = len(convex_lst)

    print(*convex_lst)
    
    plt.plot([p.x for p in convex_lst] + [convex_lst[0].x], [p.y for p in convex_lst]+[convex_lst[0].y], '-')
    plt.scatter([p.x for p in pts], [p.y for p in pts], color="red")
    plt.title("Jarvis March Algorithm (Total "+ str(len_convex_pts)+"/"+str(len(pts))+" points)")
    plt.grid()
    plt.show()

if __name__ == "__main__":
    main()