package opengenus.cosmos.sorting

import scala.annotation.tailrec

object BinarySearch {
    
  trait SearchResult
  case class Found(i: Int) extends SearchResult
  case object NotFound extends SearchResult
  
  
  def apply[T](element: T)(collection: List[T])(implicit ord: Ordering[T]): SearchResult = {
    
    @tailrec
    def binarySearchStep(start: Int, end: Int): SearchResult = {
      val mid = start + (end - start) / 2
      
      val midValue = collection(mid)
      
      if(midValue == element) Found(mid)
      else if(start > end) NotFound
      else if(ord.gt(element, midValue)) binarySearchStep(mid+1, end)
      else binarySearchStep(start, mid-1)
    }
    
    binarySearchStep(0, collection.size-1)
  }
}
