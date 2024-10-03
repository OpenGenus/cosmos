class Node[T](val key: T, var next: Node[T] = null, var prev: Node[T] = null)
{
  override def toString = "["+System.identityHashCode(prev)+"|"+key+"|"+System.identityHashCode(next)+"]"
}

class DoublyLinkedList[T]
{

  private var first: Node[T] = null

  def search(elem: T): Option[Node[T]] =
  {
    var currentNode = first
    while (currentNode.key != elem)
    {
      if (currentNode.next == null)
      {
        return None
      }
      currentNode = currentNode.next
    }
    Some(currentNode)
  }

  def +=(newData: T) =
  {
    if (first == null)
    {
      first = new Node[T](newData)
    }
    else
    {
      var newNode = new Node[T](newData)
      newNode.next = first
      first.prev = newNode
      first = newNode
    }
  }

  def -=(elem: T) =
  {
    var nodeOption = search(elem)

    nodeOption match
    {
      case Some(currentNode) =>
        //Check if this node is the tail
        if (currentNode.next == null)
        {
          var newTail = currentNode.prev
          currentNode.prev = null
          newTail.next = null
        }
        else
        {
          var nextNode = currentNode.next
          var prevNode = currentNode.prev
          nextNode.prev = prevNode
          prevNode.next = nextNode
          currentNode.prev = null
          currentNode.next = null
        }

      case None =>
    }
  }

  override def toString = {
    var str = ""
    var currentNode = first
    while (currentNode.next != null)
    {
      str += currentNode + " <-> "
      currentNode = currentNode.next
    }
    str += currentNode
    str
  }
}

object doublyLinkedList
{
  def main(args: Array[String])
  {
    var dll = new DoublyLinkedList[Int]()
    println("ADDING 1")
    dll += 1
    println(dll)
    println("ADDING 2")
    dll += 2
    println(dll)
    println("SEARCHING FOR 1")
    println(dll.search(1))
    println("ADDING 3,4,5")
    dll += 3
    dll += 4
    dll += 5
    println(dll)
    println("DELETING 4")
    dll -= 4
    println(dll)
  }
}
