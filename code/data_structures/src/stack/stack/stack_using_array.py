stack=[]
def push(item):
    stack.append(item)
def pop():
    if isEmpty(stack):
        return("STACK UNDERFLOW")
    else:
        itempopped=stack[-1]
        stack.pop
        display()
        return int(itempopped)
def isEmpty(stack):
    return stack==[]
def display():
    print(stack)
while True:
    choice=int(input("1.Push\n2.Pop\n3.Isempty\n4.Exit\n"))
    if choice==1:
        element=int(input("Enter the element to be inserted: "))
        push(element)
    if choice==2:
        print("Item deleted is %s"%pop())
    if choice==3:
        print(isEmpty(stack))
    if choice==4:
        break
