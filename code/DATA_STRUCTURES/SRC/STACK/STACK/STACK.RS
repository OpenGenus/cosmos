pub struct Stack<T> {
    elements: Vec<T>
}

impl<T> Stack<T> {
    pub fn new() -> Stack<T> {
        Stack {
            elements: Vec::new()
        }
    }

    pub fn push(&mut self, elem: T) {
        self.elements.push(elem);
    }

    pub fn pop(&mut self) -> T {
        let last = self.elements.len() - 1;
        self.elements.remove(last)
    }

    pub fn peek(&mut self) -> &T {
        let last = self.elements.len() - 1;
        &self.elements[last]
    }

    pub fn peek_mut(&mut self) -> &mut T {
        let last = self.elements.len() - 1;
        &mut self.elements[last]
    }

    pub fn len(&self) -> usize {
        self.elements.len()
    }

    pub fn is_empty(&self) -> bool {
        self.elements.is_empty()
    }
}

fn main() {
    let mut stack = Stack::<i32>::new();
    stack.push(1);
    stack.push(2);
    println!("{}", stack.pop());
    stack.push(-5);
    println!("{}", stack.peek());
}
