/* Part of Cosmos by OpenGenus Foundation */

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
