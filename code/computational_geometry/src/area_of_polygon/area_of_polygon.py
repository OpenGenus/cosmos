def area_of_polygon(verticeX, verticeY):
    length = len(verticeX)
    area = 0.0
    for a in range(0, length):
        b = (a + 1) % length
        area += verticeX[a] * verticeY[b] - verticeX[b] * verticeY[a]
    area = abs(area) / 2.0
    return area


X = []
Y = []
try:
    input = raw_input
except NameError:
    pass

n = int(input("Enter number of vertices of the polygon:"))

for i in range(0, n):
    X.append(float(input("X of vertex " + str(i + 1) + ": ")))
    Y.append(float(input("Y of vertex " + str(i + 1) + ": ")))

print("Area of polygon : " + str(area_of_polygon(X, Y)))
