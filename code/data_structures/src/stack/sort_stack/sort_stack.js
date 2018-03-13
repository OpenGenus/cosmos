var Stack = function (initStack = [])
{
    this.stack = initStack;
    this.top = initStack.length;
    
    this.push = function (value) {
        this.stack[this.top++] = value;
    }

    this.size = function() {
        return this.top;
    }

    this.peek = function() {
        return this.stack[this.top - 1];
    }

    this.pop = function () { 
        if (this.top === 0) {
            return "Stack is Empty";
        }
        this.top--;
        let result = this.stack[this.top];
        delete this.stack[this.top];
        return result;
    }

    this.sort = function() {  
        this.stack.sort();
    }

    this.print = function () {  
        console.log(this.stack.join(" "))
    }
}

var myStack = new Stack()
myStack.push(1);
myStack.push(5);
myStack.push(76);
myStack.push(69);
myStack.push(32);
myStack.push(54);
console.log(myStack.size());
console.log(myStack.peek());
console.log(myStack.pop());
myStack.sort();
console.log(myStack.peek());
console.log(myStack.pop());
console.log(myStack.peek());
myStack.push(55);
console.log(myStack.peek());
myStack.print();
myStack.sort();
myStack.print();
