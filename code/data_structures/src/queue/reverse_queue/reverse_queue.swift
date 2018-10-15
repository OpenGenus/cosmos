/* Part of Cosmos by OpenGenus Foundation */

// Queue implementation
public struct Queue<T> {
    
    private var elements: Array<T>;
    
    init() {
        self.elements = [];
    }
    
    init(arrayLiteral elements: T...) {
        self.elements = elements
    }
    
    public var front: T? {
        return elements.first
    }
    
    public var back: T? {
        return elements.last
    }
    
    public var size: Int {
        return elements.count
    }
    
    public var isEmpty: Bool {
        return elements.isEmpty
    }
    
    mutating public func enqueue(_ element: T) {
        elements.append(element)
    }
    
    mutating public func dequeue() -> T? {
        return self.isEmpty ? nil : elements.removeFirst()
    }
}

// Reverse method implementation
extension Queue {
    
    public func printElements() {
        
        for x in elements {
            print(x, terminator: " ")
        }
        print()
    }
    
    mutating public func reverse() {
        
        var items = Array<T>()
        
        while !self.isEmpty {
            items.append(self.dequeue()!)
        }
        
        while !items.isEmpty {
            self.enqueue(items.removeLast())
        }
        
    }

}

func test() {
    
    var queue = Queue<Int>(arrayLiteral: 1, 3, 2, 5)
    
    print("Original queue:")
    queue.printElements()
    
    queue.reverse()
    
    print("Reversed queue:")
    queue.printElements()
}

test()

