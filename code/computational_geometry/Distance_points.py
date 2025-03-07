import math
#Distance between two points p1(x1,y1) and p2(x2,y2)
def distance(x1,y1,x2,y2):
    return math.sqrt((x2-x1)**2+(y2-y1)**2)

if __name__ == '__main__':
    
    #distance between (2,2)and (5,5)
    print(distance(2,2,5,5))
    
