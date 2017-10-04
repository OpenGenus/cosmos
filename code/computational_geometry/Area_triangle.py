import math

#Area of triangle when base and height is given
def area_triangle(base, height):
    return (base*height)/2


#Area of triangle when length of three sides aare given
#using Heron's formula Area=sqrt(s*(s-a)*(s-b)*(s-c))
# where 's' is semiperimeter of triangle and 'a','b','c' are sides
def area_triangle_herons(a,b,c):
    s=(a+b+c)/2
    return math.sqrt(s*(s-a)*(s-b)*(s-c))
    
if __name__ == '__main__':


#area of triangle with base=10 and height=4
print(area_triangle(10,4))

#area of triangle with side lengths = 10, 4, 12
print(area_triangle_herons(10,4,12))
