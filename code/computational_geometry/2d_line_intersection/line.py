def intersection_by_points(x1, y1, x2, y2, x3, y3, x4, y4):
    x12 = x1 - x2
    x34 = x3 - x4
    y12 = y1 - y2
    y34 = y3 - y4

    c = x12 * y34 - y12 * x34

    a = x1 * y2 - y1 * x2
    b = x3 * y4 - y3 * x4

    x = (a * x34 - b * x12) / c
    y = (a * y34 - b * y12) / c

    return (x, y)

""" Line segments defined by 2 points a-b and c-d """
def intersection_by_vectors(vec1, vec2, vec3, vec4):
    return intersection_by_points(vec1['x'], vec1['y'], vec2['x'], vec2['y'], vec3['x'], vec3['y'], vec4['x'], vec4['y'])

""" Accepts line in Ax+By = C format  """
def intersection_by_line_euqation(line1, line2):
    A1 = line1['A']
    B1 = line1['B']
    C1 = line1['C']
    A2 = line2['A']
    B2 = line2['B']
    C2 = line2['C']

    delta = A1*B2 - A2*B1;
    if delta == 0:
        print("Lines are parallel")

    x = (B2*C1 - B1*C2)/delta
    y = (A1*C2 - A2*C1)/delta

    return (x, y)

# Driver Program
def main():
    # 3x + 4y = 1
    line1 = {'A':3, 'B':4, 'C':1}
    # 2x + 5y = 3
    line2 = {'A':2, 'B':5, 'C':3}

    intersection_point = intersection_by_line_euqation(line1, line2)

    print("Test using line equation")
    print("Lines intersect at x:{}, y:{}".format(intersection_point[0], intersection_point[1]) )
    print("Test using points")

    intersection_point = intersection_by_vectors({'x':2,'y':5}, {'x':5,'y':3}, {'x':7,'y':4}, {'x':1,'y':6})
    print("Lines intersect at x:{}, y:{}".format(intersection_point[0], intersection_point[1]) )


main()
