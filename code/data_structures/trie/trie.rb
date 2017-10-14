class Trie
  def insert(word)
    return if word.size == 0

    first, rest = word.split("".freeze, 2)
    children[first].insert(rest)
  end

  def search(word)
    return true if word.size == 0

    first, rest = word.split("".freeze, 2)
    children.has_key?(first) && children[first].search(rest)
  end

  private

  def children
    @children ||= Hash.new do |hash, character|
      hash[character] = Trie.new
    end
  end
end

root = Trie.new

root.insert "abc"
root.insert "pqrs"

puts root.search("abc") # => true
puts root.search("xyz") # => false
