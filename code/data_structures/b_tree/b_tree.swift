// Part of Cosmos by OpenGenus Foundation
class BTreeNode<Key: Comparable, Value> {
  unowned var owner: BTree<Key, Value>

  fileprivate var keys = [Key]()
  fileprivate var values = [Value]()
  var children: [BTreeNode]?

  var isLeaf: Bool {
    return children == nil
  }

  var numberOfKeys: Int {
    return keys.count
  }

  init(owner: BTree<Key, Value>) {
    self.owner = owner
  }

  convenience init(owner: BTree<Key, Value>, keys: [Key],
                   values: [Value], children: [BTreeNode]? = nil) {
    self.init(owner: owner)
    self.keys += keys
    self.values += values
    self.children = children
  }
}

extension BTreeNode {
    func value(for key: Key) -> Value? {
    var index = keys.startIndex

    while (index + 1) < keys.endIndex && keys[index] < key {
      index = (index + 1)
    }

    if key == keys[index] {
      return values[index]
    } else if key < keys[index] {
      return children?[index].value(for: key)
    } else {
      return children?[(index + 1)].value(for: key)
    }
  }
}

extension BTreeNode {
  func traverseKeysInOrder(_ process: (Key) -> Void) {
    for i in 0..<numberOfKeys {
      children?[i].traverseKeysInOrder(process)
      process(keys[i])
    }

    children?.last?.traverseKeysInOrder(process)
  }
}

extension BTreeNode {
  func insert(_ value: Value, for key: Key) {
    var index = keys.startIndex

    while index < keys.endIndex && keys[index] < key {
      index = (index + 1)
    }

    if index < keys.endIndex && keys[index] == key {
      values[index] = value
      return
    }

    if isLeaf {
      keys.insert(key, at: index)
      values.insert(value, at: index)
      owner.numberOfKeys += 1
    } else {
      children![index].insert(value, for: key)
      if children![index].numberOfKeys > owner.order * 2 {
        split(child: children![index], atIndex: index)
      }
    }
  }

  private func split(child: BTreeNode, atIndex index: Int) {
    let middleIndex = child.numberOfKeys / 2
    keys.insert(child.keys[middleIndex], at: index)
    values.insert(child.values[middleIndex], at: index)
    child.keys.remove(at: middleIndex)
    child.values.remove(at: middleIndex)

    let rightSibling = BTreeNode(
      owner: owner,
      keys: Array(child.keys[child.keys.indices.suffix(from: middleIndex)]),
      values: Array(child.values[child.values.indices.suffix(from: middleIndex)])
    )
    child.keys.removeSubrange(child.keys.indices.suffix(from: middleIndex))
    child.values.removeSubrange(child.values.indices.suffix(from: middleIndex))

    children!.insert(rightSibling, at: (index + 1))

    if child.children != nil {
      rightSibling.children = Array(
        child.children![child.children!.indices.suffix(from: (middleIndex + 1))]
      )
      child.children!.removeSubrange(child.children!.indices.suffix(from: (middleIndex + 1)))
    }
  }
}

private enum BTreeNodePosition {
  case left
  case right
}

extension BTreeNode {
  private var inorderPredecessor: BTreeNode {
    if isLeaf {
      return self
    } else {
      return children!.last!.inorderPredecessor
    }
  }

  func remove(_ key: Key) {
    var index = keys.startIndex

    while (index + 1) < keys.endIndex && keys[index] < key {
      index = (index + 1)
    }

    if keys[index] == key {
      if isLeaf {
        keys.remove(at: index)
        values.remove(at: index)
        owner.numberOfKeys -= 1
      } else {
        let predecessor = children![index].inorderPredecessor
        keys[index] = predecessor.keys.last!
        values[index] = predecessor.values.last!
        children![index].remove(keys[index])
        if children![index].numberOfKeys < owner.order {
          fix(childWithTooFewKeys: children![index], atIndex: index)
        }
      }
    } else if key < keys[index] {

      if let leftChild = children?[index] {
        leftChild.remove(key)
        if leftChild.numberOfKeys < owner.order {
          fix(childWithTooFewKeys: leftChild, atIndex: index)
        }
      } else {
        print("The key:\(key) is not in the tree.")
      }
    } else {

      if let rightChild = children?[(index + 1)] {
        rightChild.remove(key)
        if rightChild.numberOfKeys < owner.order {
          fix(childWithTooFewKeys: rightChild, atIndex: (index + 1))
        }
      } else {
        print("The key:\(key) is not in the tree")
      }
    }
  }

  private func fix(childWithTooFewKeys child: BTreeNode, atIndex index: Int) {

    if (index - 1) >= 0 && children![(index - 1)].numberOfKeys > owner.order {
      move(keyAtIndex: (index - 1), to: child, from: children![(index - 1)], at: .left)
    } else if (index + 1) < children!.count && children![(index + 1)].numberOfKeys > owner.order {
      move(keyAtIndex: index, to: child, from: children![(index + 1)], at: .right)
    } else if (index - 1) >= 0 {
      merge(child: child, atIndex: index, to: .left)
    } else {
      merge(child: child, atIndex: index, to: .right)
    }
  }

   private func move(keyAtIndex index: Int, to targetNode: BTreeNode,
                                  from node: BTreeNode, at position: BTreeNodePosition) {
    switch position {
    case .left:
      targetNode.keys.insert(keys[index], at: targetNode.keys.startIndex)
      targetNode.values.insert(values[index], at: targetNode.values.startIndex)
      keys[index] = node.keys.last!
      values[index] = node.values.last!
      node.keys.removeLast()
      node.values.removeLast()
      if !targetNode.isLeaf {
        targetNode.children!.insert(node.children!.last!,
                                    at: targetNode.children!.startIndex)
        node.children!.removeLast()
      }

    case .right:
      targetNode.keys.insert(keys[index], at: targetNode.keys.endIndex)
      targetNode.values.insert(values[index], at: targetNode.values.endIndex)
      keys[index] = node.keys.first!
      values[index] = node.values.first!
      node.keys.removeFirst()
      node.values.removeFirst()
      if !targetNode.isLeaf {
        targetNode.children!.insert(node.children!.first!,
                                    at: targetNode.children!.endIndex)
        node.children!.removeFirst()
      }
    }
  }

  private func merge(child: BTreeNode, atIndex index: Int, to position: BTreeNodePosition) {
    switch position {
    case .left:
      children![(index - 1)].keys = children![(index - 1)].keys +
        [keys[(index - 1)]] + child.keys

      children![(index - 1)].values = children![(index - 1)].values +
        [values[(index - 1)]] + child.values

      keys.remove(at: (index - 1))
      values.remove(at: (index - 1))

      if !child.isLeaf {
        children![(index - 1)].children =
          children![(index - 1)].children! + child.children!
      }

    case .right:
      children![(index + 1)].keys = child.keys + [keys[index]] +
        children![(index + 1)].keys

      children![(index + 1)].values = child.values + [values[index]] +
        children![(index + 1)].values

      keys.remove(at: index)
      values.remove(at: index)

      if !child.isLeaf {
        children![(index + 1)].children =
          child.children! + children![(index + 1)].children!
      }
    }
    children!.remove(at: index)
  }
}

extension BTreeNode {
  var inorderArrayFromKeys: [Key] {
    var array = [Key] ()

    for i in 0..<numberOfKeys {
      if let returnedArray = children?[i].inorderArrayFromKeys {
        array += returnedArray
      }
      array += [keys[i]]
    }

    if let returnedArray = children?.last?.inorderArrayFromKeys {
      array += returnedArray
    }

    return array
  }
}

public class BTree<Key: Comparable, Value> {
  
  public let order: Int


  var rootNode: BTreeNode<Key, Value>!

  fileprivate(set) public var numberOfKeys = 0

  public init?(order: Int) {
    guard order > 0 else {
      print("Order has to be greater than 0.")
      return nil
    }
    self.order = order
    rootNode = BTreeNode<Key, Value>(owner: self)
  }
}

extension BTree {
  public func traverseKeysInOrder(_ process: (Key) -> Void) {
    rootNode.traverseKeysInOrder(process)
  }
}

  private func splitRoot() {
    let middleIndexOfOldRoot = rootNode.numberOfKeys / 2

    let newRoot = BTreeNode<Key, Value>(
      owner: self,
      keys: [rootNode.keys[middleIndexOfOldRoot]],
      values: [rootNode.values[middleIndexOfOldRoot]],
      children: [rootNode]
    )
    rootNode.keys.remove(at: middleIndexOfOldRoot)
    rootNode.values.remove(at: middleIndexOfOldRoot)

    let newRightChild = BTreeNode<Key, Value>(
      owner: self,
      keys: Array(rootNode.keys[rootNode.keys.indices.suffix(from: middleIndexOfOldRoot)]),
      values: Array(rootNode.values[rootNode.values.indices.suffix(from: middleIndexOfOldRoot)])
    )
    rootNode.keys.removeSubrange(rootNode.keys.indices.suffix(from: middleIndexOfOldRoot))
    rootNode.values.removeSubrange(rootNode.values.indices.suffix(from: middleIndexOfOldRoot))

    if rootNode.children != nil {
      newRightChild.children = Array(
        rootNode.children![rootNode.children!.indices.suffix(from: (middleIndexOfOldRoot + 1))]
      )
      rootNode.children!.removeSubrange(
        rootNode.children!.indices.suffix(from: (middleIndexOfOldRoot + 1))
      )
    }

    newRoot.children!.append(newRightChild)
    rootNode = newRoot
  }
}

// MARK: BTree extension: Removal

extension BTree {
  /**
   *  Removes `key` and the value associated with it from the tree.
   *  
   *  - Parameters:
   *    - key: the key to remove
   */
  public func remove(_ key: Key) {
    guard rootNode.numberOfKeys > 0 else {
      return
    }

    rootNode.remove(key)

    if rootNode.numberOfKeys == 0 && !rootNode.isLeaf {
      rootNode = rootNode.children!.first!
    }
  }
}

extension BTree {
  
  public var inorderArrayFromKeys: [Key] {
    return rootNode.inorderArrayFromKeys
  }
}

extension BTree: CustomStringConvertible {
  
  public var description: String {
    return rootNode.description
  }
}
