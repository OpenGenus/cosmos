import Foundation

public struct Stack<T> {
  fileprivate var array: [T] = []

  public var isEmpty: Bool {
    return array.isEmpty
  }

  public var count: Int {
    return array.count
  }

  public mutating func push(_ element: T) {
    array.append(element)
  }

  public mutating func pop() -> T? {
    return array.popLast()
  }

  public func peek() -> T? {
    return array.last
  }
}

extension Stack: Sequence {
  public func makeIterator() -> AnyIterator<T> {
    var curr = self
    return AnyIterator { curr.pop() }
  }
}

private func coinFlip() -> Bool {
  return arc4random_uniform(2) == 1
}

public class DataNode<Key: Comparable, Payload> {
  public typealias Node = DataNode<Key, Payload>

  var data: Payload?
  fileprivate var key: Key?
  var next: Node?
  var down: Node?

  public init(key: Key, data: Payload) {
    self.key  = key
    self.data = data
  }

  public init(asHead head: Bool) {}

}

open class SkipList<Key: Comparable, Payload> {
  public typealias Node = DataNode<Key, Payload>

  fileprivate(set) var head: Node?

  public init() {}

}

extension SkipList {

  func findNode(key: Key) -> Node? {
    var currentNode: Node? = head
    var isFound: Bool = false

    while !isFound {
      if let node = currentNode {

        switch node.next {
        case .none:

          currentNode = node.down
        case .some(let value) where value.key != nil:

          if value.key == key {
            isFound = true
            break
          } else {
            if key < value.key! {
              currentNode = node.down
            } else {
              currentNode = node.next
            }
          }

        default:
          continue
        }

      } else {
        break
      }
    }

    if isFound {
      return currentNode
    } else {
      return nil
    }

  }

  func search(key: Key) -> Payload? {
    guard let node = findNode(key: key) else {
      return nil
    }

    return node.next!.data
  }

}

extension SkipList {
  private func bootstrapBaseLayer(key: Key, data: Payload) {
    head       = Node(asHead: true)
    var node   = Node(key: key, data: data)

    head!.next = node

    var currentTopNode = node

    while coinFlip() {
      let newHead    = Node(asHead: true)
      node           = Node(key: key, data: data)
      node.down      = currentTopNode
      newHead.next   = node
      newHead.down   = head
      head           = newHead
      currentTopNode = node
    }

  }

  private func insertItem(key: Key, data: Payload) {
    var stack              = Stack<Node>()
    var currentNode: Node? = head

    while currentNode != nil {

      if let nextNode = currentNode!.next {
        if nextNode.key! > key {
          stack.push(currentNode!)
          currentNode = currentNode!.down
        } else {
          currentNode = nextNode
        }

      } else {
        stack.push(currentNode!)
        currentNode = currentNode!.down
      }

    }

    let itemAtLayer    = stack.pop()
    var node           = Node(key: key, data: data)
    node.next          = itemAtLayer!.next
    itemAtLayer!.next  = node
    var currentTopNode = node

    while coinFlip() {
      if stack.isEmpty {
        let newHead    = Node(asHead: true)

        node           = Node(key: key, data: data)
        node.down      = currentTopNode
        newHead.next   = node
        newHead.down   = head
        head           = newHead
        currentTopNode = node

      } else {
        let nextNode  = stack.pop()

        node           = Node(key: key, data: data)
        node.down      = currentTopNode
        node.next      = nextNode!.next
        nextNode!.next = node
        currentTopNode = node
      }
    }
  }

  func insert(key: Key, data: Payload) {
    if head != nil {
      if let node = findNode(key: key) {
        var currentNode = node.next
        while currentNode != nil && currentNode!.key == key {
          currentNode!.data = data
          currentNode       = currentNode!.down
        }
      } else {
        insertItem(key: key, data: data)
      }

    } else {
      bootstrapBaseLayer(key: key, data: data)
    }
  }

}

extension SkipList {
  public func remove(key: Key) {
    guard let item = findNode(key: key) else {
      return
    }

    var currentNode = Optional(item)

    while currentNode != nil {
      let node   = currentNode!.next

      if node!.key != key {
        currentNode = node
        continue
      }

      let nextNode      = node!.next

      currentNode!.next = nextNode
      currentNode       = currentNode!.down

    }

  }
}

extension SkipList {

  public func get(key: Key) -> Payload? {
    return search(key: key)
  }
}
