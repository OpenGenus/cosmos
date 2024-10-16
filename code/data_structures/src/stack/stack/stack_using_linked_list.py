class node:
    def __init__(self,value):
        self.data=value
        self.next=None
class stack:
    def __init__(self,value):
        self.ptr=None
    def display(self):
        temp=self.ptr
        while temp:
            print (temp.data,end='->')
            temp=temp.next
        print('NULL')
    def insertnode(self,data):
        if self.ptr==None:
            self.ptr=node(data)
        else:
            newnode=node(data)
            newnode.next=self.ptr
            self.ptr=newnode
    def deletenode(self):
        if self.ptr==None:
            print("Stack is empty")
            return
        else:
            print("Item deleted is %s"%self.ptr.data)
            self.ptr=self.ptr.next
    def isEmpty(self):
        return self.ptr==None

top=stack()
while True:
    choice=int(input("1.Push\n2.Pop\n3.Isempty\n4.Exit\n"))
    if choice==1:
        element=int(input("Enter the element to be inserted: "))
        top.insertnode(element)
        top.display()
    if choice==2:
        top.deletenode()
        top.display()
    if choice==3:
        print(top.isEmpty())
    if choice==4:
        break
        
