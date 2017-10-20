class HashElement<T: Hashable, U> {
  var key: T
  var value: U?
  
  init(key: T, value: U?) {
    self.key = key
    self.value = value
  }
}

struct HashTable<Key: Hashable, Value: CustomStringConvertible> {
  private typealias Element = HashElement<Key, Value>
  private typealias Bucket = [Element]
  private var buckets: [Bucket]
  
  /// Number of key-value pairs in the hash table.
  private(set) public var count = 0
  
  /// A Boolean value that indicates whether the hash table is empty.
  public var isEmpty: Bool { return count == 0 }
  
  /// A string that represents the contents of the hash table.
  public var description: String {
    let pairs = buckets.flatMap { b in b.map { e in "\(e.key) = \(e.value)" } }
    return pairs.joined(separator: ", ")
  }
  
  /// A string that represents the contents of the hash table, suitable for debugging.
  public var debugDescription: String {
    var str = ""
    for (i, bucket) in buckets.enumerated() {
      let pairs = bucket.map { e in "\(e.key) = \(e.value)" }
      str += "bucket \(i): " + pairs.joined(separator: ", ") + "\n"
    }
    return str
  }
  
  /// Initialise hash table with the given capacity.
  ///
  /// - Parameter capacity: hash table capacity.
  init(capacity: Int) {
    assert(capacity > 0)
    buckets = Array<Bucket>(repeatElement([], count: capacity))
  }
  
  
  /// Returns an array index for a given key
  private func index(forKey key: Key) -> Int {
    return abs(key.hashValue) % buckets.count
  }
  
  /// Returns the value for the given key
  func value(for key: Key) -> Value? {
    let index = self.index(forKey: key)
    for element in buckets[index] {
      if element.key == key {
        return element.value
      }
    }
    return nil // key not in the hash table
  }
  
  /// Accesses element's value (get,set) in hash table for a given key.
  subscript(key: Key) -> Value? {
    get {
      return value(for: key)
    }
    set {
      if let value = newValue {
        updateValue(value, forKey: key)
      } else {
        removeValue(for: key)
      }
    }
  }
  
  /// Updates element's value in the hash table for the given key, or adds a new element if the key doesn't exists.
  @discardableResult
  mutating func updateValue(_ value: Value, forKey key: Key) -> Value? {
    let itemIndex = self.index(forKey: key)
    for (i, element) in buckets[itemIndex].enumerated() {
      if element.key == key {
        let oldValue = element.value
        buckets[itemIndex][i].value = value
        return oldValue
      }
    }
    buckets[itemIndex].append(HashElement(key: key, value: value)) // Adding element to the chain.
    count += 1
    return nil
  }
  
  /// Removes element from the hash table for a given key.
  @discardableResult
  mutating func removeValue(for key: Key) -> Value? {
    let index = self.index(forKey: key)
    // Search and destroy
    for (i, element) in buckets[index].enumerated() {
      if element.key == key {
        buckets[index].remove(at: i)
        count -= 1
        return element.value
      }
    }
    return nil // key not in the hash table
  }
  
  
  /// Removes all elements from the hash table.
  public mutating func removeAll() {
    buckets = Array<Bucket>(repeatElement(nil, count: buckets.count))
    count = 0
  }
}

