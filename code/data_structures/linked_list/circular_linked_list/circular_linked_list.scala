class Node[T](val key: T, var next: Node[T] = null)
{
  override def toString = "["+key+"|"+System.identityHashCode(next)+"]"
}

class CircularLinkedList[T]
{
  var first: Node[T] = null

  def search(elem: T): Node[T] =
  {
    var currentNode = first
    while (currentNode.key != elem)
    {
      if (currentNode.next == first)
      {
        throw new IllegalStateException("Could not find element " + elem)
      }
      currentNode = currentNode.next
    }
    currentNode
  }

  def +=(newData: T) =
  {
    var newNode = new Node[T](newData)
    if (first == null)
    {
      first = newNode
      first.next = first
    }
    else
    {
      newNode.next = first
      var lastNode = first
      while (lastNode.next != first)
      {
        lastNode = lastNode.next
      }
      lastNode.next = newNode
      first = newNode
    }
  }

  def -=(elem: T) =
  {
    var currentNode = search(elem)
    var previousNode = first
    while (previousNode.next != currentNode)
    {
      previousNode = previousNode.next
    }

    previousNode.next = currentNode.next
    currentNode.next = null
  }

  override def toString = {
    var str = ""
    var currentNode = first
    while (currentNode.next != first)
    {
      str += currentNode + " -> "
      currentNode = currentNode.next
    }
    str += currentNode
    str
  }
}

object circular_linked_list
{
  def main(args: Array[String])
  {
    var cll = new CircularLinkedList[Int]()
    println("ADDING 1")
    cll += 1
    println(cll)
    println("ADDING 2")
    cll += 2
    println(cll)
    println("SEARCHING FOR 1")
    println(cll.search(1))
    println("ADDING 3,4,5")
    cll += 3
    cll += 4
    cll += 5
    println(cll)
    println("DELETING 4")
    cll -= 4
    println(cll)
  }
}
