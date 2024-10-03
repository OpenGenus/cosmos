# Part of Cosmos by OpenGenus Foundation

import math
import random
import time

dic = {}
n = int(input())

x_list = random.sample(range(10000),n)
y_list = random.sample(range(1000),n)
for i in range(0,n):
    dic.update({x_list[i]:y_list[i]})
print(list(dic.items()))

X = list(dic.keys())
Y = [dic[x] for x in X]

start_time = time.time()

def dis(x1,y1,x2,y2):
    distance = math.sqrt( ((x1-x2)**2)+((y1-y2)**2) )
    return distance

def brute(x,y):
    bx1 = bx2 = by1 = by2 = None
    min_dist = 99999999999
    for i in range(len(x)-1):
        for j in range(i+1,len(x)):
            dist = dis(x[i],y[i],x[j],y[j])
            if dist < min_dist:
                min_dist = dist
                bx1 = x[i]
                bx2 = x[j]
                by1 = y[i]
                by2 = y[j]
    return bx1,by1,bx2,by2,min_dist



def closest_pair(X,Y,n):
    if n <=3 :
        return brute(X,Y)
    else:
        X.sort()
        lx = X[:int(n/2)]
        rx = X[int(n/2):]

        ly = [dic[x] for x in lx]
       
        ry = [dic[x] for x in rx]
        
        n = int(n/2)

        px1,py1,qx1,qy1,d1 = closest_pair(lx,ly,n)
        px2,py2,qx2,qy2,d2 = closest_pair(rx,ry,n)
        de = min(d1, d2)
        px3,py3,qx3,qy3,d3 = closest_split(X,Y,de)
        d_min = min(d1,d2,d3)
        if d1 == d_min:
            return px1,py1,qx1,qy1,d1
        elif d2 == d_min:
            return px2,py2,qx2,qy2,d2
        else:
            return px3,py3,qx3,qy3,d3

def closest_split(X,Y,de):
    best = de
    Sy = []
    Y.sort()
   
    for el in Y:
        for x,y in dic.items():
            if y==el and x not in Sy:
                Sy.append(x)

    bx1=bx2= by1 = by2 = None

    for i in range(0,len(Sy)-1):
        for j in range(i+1,min(len(Sy)-1,i+7)):
          
            x1 = Sy[i]
            x2 = Sy[j]
            y1 = Y[i]
            y2 = Y[j]
            dist = dis(x1,y1,x2,y2)
            if dist<best:
                best = dist
                bx1 = x1
                by1 = y1
                bx2 = x2
                by2 = y2
                
    return  bx1,by1,bx2,by2,best


a,b,c,d,e = closest_pair(X,Y,n)
print("({},{}) and ({},{}) are closest among all, with distance of {} units.".format(a,b,c,d,e))

print("--- %s seconds ---" % (time.time() - start_time))