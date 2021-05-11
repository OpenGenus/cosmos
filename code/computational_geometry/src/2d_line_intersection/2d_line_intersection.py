# computational geometry | 2D line intersecton | Python
def parallel_int(verticeX, verticeY):
    k = (verticeY[2] - verticeY[0]) * (verticeX[1] - verticeX[0]) - (
        verticeX[2] - verticeX[0]
    ) * (verticeY[1] - verticeY[0])
    if k == 0:
        return "infinite"
    else:
        return "no"


def line_int(verticeX, verticeY):
    x12 = verticeX[0] - verticeX[1]
    x34 = verticeX[2] - verticeX[3]
    y12 = verticeY[0] - verticeY[1]
    y34 = verticeY[2] - verticeY[3]

    c = x12 * y34 - y12 * x34

    if c == 0:
        return ("NoInt", None)

    a = verticeX[0] * verticeY[1] - verticeY[0] * verticeX[1]
    b = verticeX[2] * verticeY[3] - verticeY[2] * verticeX[3]

    x = (a * x34 - b * x12) / c
    y = (a * y34 - b * y12) / c

    return (x, y)


X = []
Y = []
try:
    input = raw_input
except NameError:
    pass

print("Enter 2-point form of each line")

X.append(float(input("X of point 1, line 1: ")))
Y.append(float(input("Y of point 1, line 1: ")))

X.append(float(input("X of point 2, line 1: ")))
Y.append(float(input("Y of point 2, line 1: ")))

X.append(float(input("X of point 1, line 2: ")))
Y.append(float(input("Y of point 1, line 2: ")))

X.append(float(input("X of point 2, line 2: ")))
Y.append(float(input("Y of point 2, line 2: ")))

intersectn = line_int(X, Y)
if intersectn[0] == "NoInt":
    print("Parallel lines found with " + parallel_int(X, Y) + " intersections")
else:
    print(
        "Point of intersection : ("
        + str(intersectn[0])
        + ", "
        + str(intersectn[1])
        + ")"
    )
