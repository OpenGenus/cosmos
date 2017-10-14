#Part of Cosmos by OpenGenus Foundation

edges = [(1,2),(1,4),(2,3),(2,5),(4,4),(4,5),(5,5),(1,4)]
edges = [(x[0]-1,x[1]-1) for x in edges]

Matrix = [[0 for x in range(5)] for y in range(5)]
for y in edges :
    Matrix[y[0]][y[1]] += 1
    Matrix[y[1]][y[0]] += 1


print(Matrix)

#function to calculate degree of any vertex

def degree():
    print("Enter vertex\n")
    v = int(input()) - 1
    print("Degree of {} is {}".format((v + 1),sum(Matrix[v])))

degree()

#function to check adjacent vertices

def  Adj_ver():
    print("Enter vertices")
    v1, v2 = (input().split())
    v1 = int(v1)-1
    v2 = int(v2)-1
    if Matrix[v1 +1][v2+1] >0:
        print("Adjacent")
    else:
        print("Not adjacent")

Adj_ver()

# Function to check adjacent edgess

def Adj_edges():
    print("Enter pair of Vertices")
    v1,v2,v3,v4 = [int(x)-1 for x in input().split()]
    if v1 == v3 or v1 == v4 or v2 == v3 or v2 == v4 :
        print("Adjacent")
    else:
        print("Not Adjacent")

Adj_edges()

# Function to check Regular graph
def reg_gra():
    deg = [sum(x) for x in Matrix]
    if len(set(deg)) >1:
        print("Not Regular")
    else:
        print("Regular")

reg_gra()

# Function to check complete graph

def com_gra():
    deg = [sum(x) for x in Matrix]
    if len(set(deg))==1 and deg[0]==4:
        print("Complete")
    else:
        print("Not Complete")

com_gra()

#Function to check euler graph

def euler():
    deg = [sum(x) for x in Matrix if sum(x)%2 ==0]
    if len(set(deg))==5:
        print("Euler graph")
    else:
        print("Not Euler")

euler()