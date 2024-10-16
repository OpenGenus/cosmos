# Import graphics library
from graphics import GraphWin

import time

def bresenham_line(xa, ya, xb, yb):
    dx = abs(xb - xa)
    dy = abs(yb - ya)

    slope = dy / float(dx)

    x, y = xa, ya

    # creating the window
    win = GraphWin('Bresenham Line', 600, 480)

    # checking the slope if slope > 1
    # then interchange the role of x and y
    if slope > 1:
        dx, dy = dy, dx
        x, y = y, x
        xa, ya = ya, xa
        xb, yb = yb, xb
    # initialization of the inital disision parameter
    p = 2 * dy - dx

    Put_Pixel(win, x, y)  # Plot Pixels To Draw Line

    for k in range(2, dx):
        if p > 0:
            y += 1 if y < yb else y - 1
            p += 2 * (dy - dx)
        else:
            p += 2 * dy
        x += 1 if x < xb else x - 1

        time.sleep(0.01)  # delay for 0.01 secs
        Put_Pixel(win, x, y)  # Plot Pixels To Draw Line

def Put_Pixel(win, x, y):
    """Plot a pixel In the window at point (x, y)"""
    pt = Point(x, y)
    pt.draw(win)

def main():
    # Taking coordinates from User
    xa = int(input("Enter Start X: "))
    ya = int(input("Enter Start Y: "))
    xb = int(input("Enter End X: "))
    yb = int(input("Enter End Y: "))

    # Calling Out The function
    Bresenham_Line(xa, ya, xb, yb)

# Driver Function
if __name__ == "__main__":
    main()

# Input -     Enter Start X : 100
#             Enter Start Y : 100
#             Enter End X   : 300
#             Enter End Y   : 300

# Sample output - https://ibb.co/4fzGM6W