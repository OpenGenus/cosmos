package opengenus.cosmos.sorting

object MergeSort {
  
  def apply[T](collection: List[T])(implicit ord: Ordering[T]): List[T] = {
    
    def merge(left: List[T], right: List[T]): List[T] = {
      
      (left, right) match {
        case (Nil, right) => right
        case (left, Nil) => left
        case (leftHead::leftTail, rightHead::rightTail) => {
          if(ord.lt(leftHead, rightHead)) leftHead::merge(leftTail, right) else rightHead::merge(left, rightTail)
        }
      }
      
    }
    
    collection match {
      case head::Nil => collection
      case _ => {
        val (left, right) = collection.splitAt(collection.size/2)
        merge(MergeSort(left), MergeSort(right))
      }
    }
  }
}
