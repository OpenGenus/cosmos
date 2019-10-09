#input bt
#print bt
#no. of nodes
#sum of nodes
#preorder bt
#postorder bt
#largest node
#nodes greater than x
#height of bt
#no of leaf nodes
#print nodes at depth k
#replace node with depth 
#is node present
#nodes without sibling
#remove leaf nodes
# mirror bt
# check for balanced bt
# improved balance bt
# diameter of bt
class binarytree:
	def __init__(self,data):
		self.data=data
		self.left=None
		self.right=None

def inputbt():
	rootdata=int(input())
	if rootdata==-1:
		return None
	root=binarytree(rootdata)
	root.left=inputbt()
	root.right=inputbt()
	return root

def printbt(root):
	if root==None:
		return
	print()
	print(root.data,end=" ")
	
	if root.left!=None:
		print('L:',root.left.data,end=" ")
	if root.right!=None:
		print('R:',root.right.data,end=" ")
	printbt(root.left)
	printbt(root.right)
	return root

def noofnodes(root):
	if root==None:
		return 0
	l=noofnodes(root.left)
	r=noofnodes(root.right)
	return 1+max(l,r)
def sumofnodes(root):
	if root==None:
		return 0

	l=sumofnodes(root.left)
	r=sumofnodes(root.right)
	return l+r+root.data

def nodegreater(root,x):
	if root==None:
		return 
	if root.data>x:
		print(root.data)
	nodegreater(root.left,x)
	nodegreater(root.right,x)

# def replacedepthdata(root,level=0):
# 	if root==None:
# 		return
# 	i=0
# 	for i in range(level+1):
# 		if i==level:
# 			print('*')
# 		print(root.data,end=" ")
# 	print()	
# 	level+=1
# 	replacedepthdata(root.left,level)
# 	replacedepthdata(root.right,level)
	
	
# def preorderbt(root):
# 	if root==None:
# 		return
# 	print()
# 	print(root.data,end=" ")
# 	if root.left!=None:
# 		print('L:',root.left.data,end=" ")
# 	if root.right!=None:
# 		print('R:',root.right.data,end=" ")
# 	preorderbt(root.left)
# 	preorderbt(root.right)
# 	return root

# def postorderbt(root):
# 	if root==None:
# 		return
# 	print()
# 	postorderbt(root.left)
# 	preorderbt(root.right)
# 	print(root.data,end=" ")
# 	if root.left!=None:
# 		print('L:',root.left.data,end=" ")
# 	if root.right!=None:
# 		print('R:',root.right.data,end=" ")
	
	
# 	return root
def noofleaf(root):
	if root==None:
		return 0
	if root.right==None and root.left==None:
		return 1
	l=noofleaf(root.left)
	r=noofleaf(root.right)
	return l+r

def greatestnode(root):
	if root ==None:
		return 0
	l=greatestnode(root.left)
	r=greatestnode(root.right)
	return max(root.data,l,r) 
x=inputbt()
printbt(x)
print(noofnodes(x))
print(sumofnodes(x))

def height(root):
	if root==None:
		return 0
	l=height(root.left)
	r=height(root.right)
	return 1+max(l,r)

def nodesatdepth(root,k):
	if root==None:
		return
	if k==0:
		print(root.data)
	nodesatdepth(root.left,k-1)
	nodesatdepth(root.right,k-1)

def isnodepresent(root,x):
	if root==None:
		return False
	if root.data==x:
		return True
	if isnodepresent(root.left,x):
		return True
	if isnodepresent(root.right,x):
		return True
	return False

def nodewithoutsiblings(root):
	if root==None:
		return
	if (root.left!=None and root.right==None):
		print(root.left.data)
	if (root.left==None and root.right!=None) :
		print(root.right.data)
	nodewithoutsiblings(root.left)
	nodewithoutsiblings(root.right)
	return root

def removeleaf(root):
	if root==None:
		return
	if root.left==None and root.right==None:
		return None
	root.left=removeleaf(root.left)
	root.right=removeleaf(root.right)
	return root

def mirror(root):
	if root==None:
		return
	l=mirror(root.left)
	r=mirror(root.right)
	root.left,root.right=r,l
	return root

def isbalancedt(root):
	if root==None:
		return True
	l=height(root.left)
	r=height(root.right)
	if l-r>1 or r-l>1:
		return False
	leftt=isbalancedt(root.left)
	rightt=isbalancedt(root.right)
	if leftt and rightt:
		return True
	else:
		return False

def isbalancedimp(root):
	if root==None:
		return 0,True

	lh,lt=isbalancedimp(root.left)
	rh,rt=isbalancedimp(root.right)
	h=1+max(lh,rh)
	if lh-rh>1 or rh-lh>1:
		return h,False
	if lh and rh:
		return h,True
	else:
		return h,False
# preorderbt(x)
# postorderbt(x)
print(greatestnode(x))
nodegreater(x,2)
print('height',height(x))
print(noofleaf(x))
nodesatdepth(x,2)
print(isnodepresent(x,30))
nodewithoutsiblings(x)
# removeleaf(x)
mirror(x)
printbt(x)
print(isbalancedt(x))
print(isbalancedimp(x))