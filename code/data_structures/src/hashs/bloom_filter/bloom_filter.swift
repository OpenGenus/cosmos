public class BloomFilter<T> {
  private var array: [Bool]
  private var hashFunctions: [(T) -> Int]

  public init(size: Int = 1024, hashFunctions: [(T) -> Int]) {
    self.array = [Bool](repeating: false, count: size)
    self.hashFunctions = hashFunctions
  }

  private func computeHashes(_ value: T) -> [Int] {
    return hashFunctions.map { hashFunc in abs(hashFunc(value) % array.count) }
  }

  public func insert(_ element: T) {
    for hashValue in computeHashes(element) {
      array[hashValue] = true
    }
  }

  public func insert(_ values: [T]) {
    for value in values {
      insert(value)
    }
  }

  public func query(_ value: T) -> Bool {
    let hashValues = computeHashes(value)
    let results = hashValues.map { hashValue in array[hashValue] }
    let exists = results.reduce(true, { $0 && $1 })
    return exists
  }

  public func isEmpty() -> Bool {
    return array.reduce(true) { prev, next in prev && !next }
  }
}
