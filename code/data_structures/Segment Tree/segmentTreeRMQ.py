import math

def update(tree,l,r,node,index,diff):
    if(l==r):
        tree[node] = diff
        return tree[l]
    mid = l + (r-l)//2
    
    if(index <= mid):
        update(tree,l,mid,(2*node)+1,index,diff)
        tree[node] = min(tree[node*2+2] , tree[node*2+1] )
        return diff
    else:
        update(tree,mid+1,r,(2*node)+2,index,diff)
        tree[node] =min(tree[node*2+2] , tree[node*2+1] )
        
 
def query(tree,l,r,x,y,node):
    if(l==x and r==y):
        return tree[node]
    mid = l+ (r-l)//2
    
    if(x<=mid and y<=mid):
        return query(tree,l,mid,x,y,(2*node)+1)
    elif(x>mid and y>mid):
        return query(tree,mid+1,r,x,y,(2*node)+2)
    elif(x<=mid and y>mid):
        left = query(tree,l,mid,x,mid,(2*node)+1)
        right = query(tree,mid+1,r,mid+1,y,(2*node)+2)
        return min(left,right)
    
def buildtree(tree,l,r,arr,node):
    if(l==r):
        tree[node] = arr[l]
        return arr[l]
        
    mid = l + ( r-l )//2 
    left = buildtree(tree,l,mid,arr,(2*node)+1)
    right = buildtree(tree,mid+1,r,arr,(2*node)+2)
    tree[node] = min(left,right)
    return tree[node]

n,que = map(int,input("Input total no. elements in array and No. of query :").split(" "))

print("Input elements of the array : ")
arr = list(map(int,input().split(" ")))
x = math.ceil(math.log(n,2))
totnodes = (2*(2**(x+1)))-1
tree = [None for i in range(totnodes)]
buildtree(tree,0,n-1,arr,0)
for i in range(que):
    print("If you want to find query press 'q' with left and right index.")
    print("If you want to update the array, press 'u' with index and value for the update.")
    q,x,y = input().split(" ")
    x = int(x)-1
    y = int(y)-1
    if(q=="q"):
        print("Minimum in the given range is " + str(query(tree,0,n-1,x,y,0)));
    
    elif(q=='u'):
        y+=1
        diff = arr[x]
        arr[x] = y;
        update(tree,0,n-1,0,x,y)