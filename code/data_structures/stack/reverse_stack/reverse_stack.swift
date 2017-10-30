/* Part of Cosmos by OpenGenus Foundation */

// Basic stack implementation
public struct Stack<T> {
    
    private var elements: Array<T>
    
    init() {
        self.elements = []
    }
    
    init(arrayLiteral elements: T...) {
        self.elements = elements
    }
    
    public var top: T? {
        return elements.last
    }
    
    public var size: Int {
        return elements.count
    }
    
    public var isEmpty: Bool {
        return elements.isEmpty
    }
    
    mutating public func push(_ element: T) {
        elements.append(element)
    }
    
    mutating public func pop() -> T? {
        return self.isEmpty ? nil : elements.removeLast()
    }
    
}

// Reverse method implementation
extension Stack {
    
    public func printElements() {
        
        for x in self.elements.reversed() {
            print(x, terminator: " ")
        }
        print()
    }
    
    mutating private func insertAtEnd(_ element: T) {
        
        guard let top = self.pop() else {
            self.push(element)
            return
        }
        
        self.insertAtEnd(element)
        self.push(top)
    }
    
    mutating public func reverse() {
        
        guard let top = self.pop() else { return }
        
        self.reverse()
        self.insertAtEnd(top)
    }
    
}

func test() {
    
    var stack = Stack<Int>(arrayLiteral: 1, 3, 2, 5)
    
    print("Original stack:")
    stack.printElements()
    
    stack.reverse()
    
    print("Reversed stack:")
    stack.printElements()
}

test()
