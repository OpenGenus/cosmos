class infix_to_prefix:
    precedence={'^':5,'*':4,'/':4,'+':3,'-':3,'(':2,')':1}
    def __init__(self):
        self.items=[]
        self.size=-1
    def push(self,value):
        self.items.append(value)
        self.size+=1
    def pop(self):
        if self.isempty():
            return 0
        else:
            self.size-=1
            return self.items.pop()
    def isempty(self):
        if(self.size==-1):
            return True
        else:
            return False
    def seek(self):
        if self.isempty():
            return False
        else:
            return self.items[self.size]
    def is0perand(self,i):
        if i.isalpha() or i in '1234567890':
            return True
        else:
            return False
    def reverse(self,expr):
        rev=""
        for i in expr:
            if i is '(':
                i=')'
            elif i is ')':
                i='('
            rev=i+rev
        return rev
    def infixtoprefix (self,expr):
        prefix=""
        print('prefix expression after every iteration is:')
        for i in expr:
            if(len(expr)%2==0):
                print("Incorrect infix expr")
                return False
            elif(self.is0perand(i)):
                prefix +=i
            elif(i in '+-*/^'):
                while(len(self.items)and self.precedence[i] < self.precedence[self.seek()]):
                    prefix+=self.pop()
                self.push(i)
            elif i is '(':
                self.push(i)
            elif i is ')':
                o=self.pop()
                while o!='(':
                    prefix +=o
                    o=self.pop()
            print(prefix)
                #end of for
        while len(self.items):
            if(self.seek()=='('):
                self.pop()
            else:
                prefix+=self.pop()
                print(prefix)
        return prefix
s=infix_to_prefix()
expr=input('enter the expression ')
rev=""
rev=s.reverse(expr)
#print(rev)
result=s.infixtoprefix(rev)
if (result!=False):
    
    prefix=s.reverse(result)
    print("the prefix expr of :",expr,"is",prefix)
