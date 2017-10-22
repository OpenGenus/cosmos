def derivative(f, x, h):
      return (f(x+h) - f(x-h)) / (2.0*h)  # might want to return a small non-zero if ==0

def quadratic(x):
    return 2*x*x-5*x+1     # just a function to show it works

def solve(f, x0, h):
    lastX = x0
    nextX = lastX + 10* h  # "different than lastX so loop starts OK
    while (abs(lastX - nextX) > h):  # this is how you terminate the loop - note use of abs()
        newY = f(nextX)                     # just for debug... see what happens
        print "f(", nextX, ") = ", newY     # print out progress... again just debug
        lastX = nextX
        nextX = lastX - newY / derivative(f, lastX, h)  # update estimate using N-R
    return nextX

xFound = solve(quadratic, 5, 0.01)    # call the solver
print "solution: x = ", xFound        # print the result