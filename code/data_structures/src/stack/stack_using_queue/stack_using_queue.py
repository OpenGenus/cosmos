## Part of Cosmos by OpenGenus Foundation

class Stack:

    def __init__(self):
        self.main_q = []
        self.auxiliary_q = []
        self.current_size = 0

    def top(self):
        return self.main_q[0]

    def push(self, val) -> None:
        self.auxiliary_q.append(val)
        
        while len(self.main_q) > 0:
            self.auxiliary_q.append(self.main_q.pop(0))

        self.main_q, self.auxiliary_q = self.auxiliary_q, self.main_q

        self.current_size+=1
    
    def pop(self):
        if len(self.main_q) == 0:
            return 
        self.main_q.pop(0)
        self.current_size-=1
    
    def size(self) -> int:
        return self.current_size

if __name__=='__main__':
    s = Stack()
    s.push(1) # insert an element into the stack
    s.push(2) # insert an element into the stack
    s.push(3) # insert an element into the stack
  
    assert(s.size()==3) # size should be 3
    
    assert(s.top()==3) # topmost element in the stack should be 3
    
    s.pop() # remove the topmost element from the stack
    assert(s.top()==2) # topmost element in the stack should now be 2
    
    s.pop() # remove the topmost element from the stack
    assert(s.top()==1)
    
    s.push(5) # insert an element into the stack
    assert(s.top()==5) # topmost element in the stack should now be 5
    
    s.pop() # remove the topmost element from the stack
    assert(s.top()==1) # topmost element in the stack should now be 1
    
    assert(s.size()==1) # size should be 1