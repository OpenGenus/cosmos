def calc_del(x1, x2, y1, y2):
    """
        Calculate the delta values for x and y co-ordinates
    """
    return x2 - x1, y2 - y1


def bresenham(x1, y1, x2, y2):
    """
        Calculate the co-ordinates for Bresehnam lines
        bresenham(x1, y1, x2, y2)
        returns a list of tuple of points
    """
    swap = False

    # Calculate delta for x and y
    delX, delY = calc_del(x1, x2, y1, y2)

    # Swap x and y if y > x
    if abs(delY) > abs(delX):
        x1, y1 = y1, x1
        x2, y2 = y2, x2

    # Swap x and y co-ordinates if x1 > x2
    if x1 > x2:
        swap = True
        x1, x2 = x2, x1
        y1, y2 = y2, y1

    # Recalculate delta for x and y
    delX, delY = calc_del(x1, x2, y1, y2)

    # calculate step and error
    step = 1 if y1 < y2 else -1
    error = int(delX / 2.0)

    y = y1
    co_ords = []

    # Calculate co-ordinates for the bresenham line
    for x in range(x1, x2 + 1):
        point = (x, y) if abs(delX) > abs(delY) else (y, x)
        error -= abs(delY)
        if error < 0:
            y += step
            error += delX
        co_ords.append(point)

    return co_ords if abs(delX) > abs(delY) else co_ords[::-1]


def main():
    x1, y1, x2, y2 = int(input())
    print(bresenham(x1, y1, x2, y2))
