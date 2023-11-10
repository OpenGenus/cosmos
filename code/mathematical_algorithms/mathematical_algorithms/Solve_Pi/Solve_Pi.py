import numpy as np
# given n in 1000 points. The large number n then Pi (estimate) is more accurate value
n = int(input("Enter number random points (000):"))*1000
# random uniform
x=np.random.uniform(0,1,n)
y=np.random.uniform(0,1,n)
# get (x,y) points
xy = zip(x,y)
# number in the circle
inside_cirles =sum([1 if (p[0]**2+p[1]**2)<=1 else 0 for p in xy])
# result
print(f"Pi (estimate) = {4*inside_cirles/n}")