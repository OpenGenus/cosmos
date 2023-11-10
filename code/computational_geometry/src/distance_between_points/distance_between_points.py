def calc_distance(x1, y1, x2, y2):
    return (((x1 - x2) ** 2) + ((y1 - y2) ** 2)) ** 0.5


x1 = float(input("Enter X coordinate of point 1: "))
y1 = float(input("Enter Y coordinate of point 1: "))
x2 = float(input("Enter X coordinate of point 2: "))
y2 = float(input("Enter Y coordinate of point 2: "))

print("Distance between (x1, y1) and (x2, y2) : " + str(calc_distance(x1, y1, x2, y2)))
