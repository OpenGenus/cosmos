
case class CircularLinkedList[T](data: T, private var next: CircularLinkedList[T], private var prev: CircularLinkedList[T]) {
    def getNext(): CircularLinkedList[T] = next
    def getPrev(): CircularLinkedList[T] = prev

    def apply(newData: T): CircularLinkedList[T] = {
        val newNode = CircularLinkedList(newData, null, null)
        newNode.prev = newNode
        newNode.next = newNode
        newNode
    }

    def append(newData: T): CircularLinkedList[T] = {
        // this -> newNode -> this.next()
        val newNode = CircularLinkedList(newData, this.next, this)
        this.next.prev = newNode
        this.next = newNode
        newNode
    }
}
