public class DoublyLinkedList<T> {
 
 public class Node<T> {
    var value: T
    var next: Node?
    weak var previous: Node? // weak is used to avoid ownership cycles
    
    public init(value: T) {
      self.value = value
    }
  }
  
  fileprivate var head: Node<T>?
  private var tail: Node<T>?
  
  public var isEmpty: Bool {
    return head == nil
  }
  
  public var first: Node<T>? {
    return head
  }
  
  public var last: Node<T>? {
    return tail
  }
  
  public func append(value: T) {
    let newNode = Node(value: value)
    
    if let tailNode = tail {
      newNode.previous = tailNode
      tailNode.next = newNode
    } else {
      head = newNode
    }
    tail = newNode
  }
  
  public func nodeAt(_ index: Int) -> Node<T>? {
    if index >= 0 {
      var node = head
      var i = index
      while node != nil {
        if i == 0 { return node }
        i -= 1
        node = node!.next
      }
    }
    return nil
  }
  
  // e.g. list[0]
  public subscript(index: Int) -> T {
    let node = nodeAt(index)
    assert(node != nil)
    return node!.value
  }
  
  public func insert(value: T, atIndex index: Int) {
    let (prev, next) = nodesBeforeAndAfter(index: index)     // 1
    
    let newNode = Node(value: value)    // 2
    newNode.previous = prev
    newNode.next = next
    prev?.next = newNode
    next?.previous = newNode
    
    if prev == nil {                    // 3
      head = newNode
    }
  }
  
  public var count: Int {
    if var node = head {
      var c = 1
      while let next = node.next {
        node = next
        c += 1
      }
      return c
    } else {
      return 0
    }
  }
  
  public func remove(node: Node<T>) -> String {
    let prev = node.previous
    let next = node.next
    
    if let prev = prev {
      prev.next = next
    } else {
      head = next
    }
    next?.previous = prev
    
    if next == nil {
      tail = prev
    }
    
    node.previous = nil
    node.next = nil
    
    return node.value as! String
  }
  public func removeAll() {
    head = nil
    tail = nil
  }
  
  // Helper functions
  private func nodesBeforeAndAfter(index: Int) -> (Node<T>?, Node<T>?) {
    assert(index >= 0)
    
    var i = index
    var next = head
    var prev: Node<T>?
    
    while next != nil && i > 0 {
      i -= 1
      prev = next
      next = next!.next
    }
    assert(i == 0)
    
    return (prev, next)
  }
}

extension DoublyLinkedList {
  public func reverse() {
    var node = head
    tail = node
    while let currentNode = node {
      node = currentNode.next
      swap(&currentNode.next, &currentNode.previous)
      head = currentNode
    }
  }
}

extension DoublyLinkedList {
  public func map<U>(transform: (T) -> U) -> DoublyLinkedList<U> {
    let result = DoublyLinkedList<U>()
    var node = head
    while node != nil {
      result.append(value: transform(node!.value))
      node = node!.next
    }
    return result
  }
  
  public func filter(predicate: (T) -> Bool) -> DoublyLinkedList<T> {
    let result = DoublyLinkedList<T>()
    var node = head
    while node != nil {
      if predicate(node!.value) {
        result.append(value: node!.value)
      }
      node = node!.next
    }
    return result
  }
}

extension DoublyLinkedList: CustomStringConvertible {
  public var description: String {
    var text = "["
    var node = head
    while node != nil {
      text += "\(node!.value)"
      node = node!.next
      if node != nil { text += ", " }
    }
    return text + "]"
  }
}

extension DoublyLinkedList {
  convenience init(array: Array<T>) {
    self.init()
    
    for element in array {
      self.append(element)
    }
  }
}
