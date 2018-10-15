//Part of Cosmos by OpenGenus Foundation

object PrintReverse {

  case class Node[T](value: T, next: Option[Node[T]]) {
    // append new node at the end
    def :~>(tail: Node[T]): Node[T] = next match {
      case None => new Node(value, Some(tail))
      case Some(x) => new Node(value, Some(x :~> tail))
    }
  }

  object Node {
    def apply[T](value: T): Node[T] = new Node(value, None)
  }

  def printReverse[T](node: Node[T]): Unit = {
    node.next.foreach(printReverse)
    println(node.value)
  }

  def main(args: Array[String]): Unit = {
    val integerLinkedList = Node(1) :~> Node(2) :~> Node(3)
    val stringLinkedList = Node("hello") :~> Node("world") :~> Node("good") :~> Node("bye")
    printReverse(integerLinkedList)
    printReverse(stringLinkedList)
  }
}
