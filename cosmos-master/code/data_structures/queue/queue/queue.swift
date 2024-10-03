/* Part of Cosmos by OpenGenus Foundation */

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
