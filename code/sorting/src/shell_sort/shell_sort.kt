import java.util.*
 
fun MutableList<Int>.swap(index1: Int, index2: Int) {
    val tmp = this[index1]
    this[index1] = this[index2]
    this[index2] = tmp
}
fun MutableList<Int>.shellSort(): MutableList<Int> {
 var sublistCount = count() / 2
 while (sublistCount > 0) {
  var index = 0
  outer@while (index >= 0 && index < count()) {
   if (index + sublistCount >= count()) break
   if (this[index] > this[index + sublistCount]) {
    swap(index, index + sublistCount)
   }
   if (sublistCount == 1 && index > 0) {
    while (this[index - 1] > this[index] && index - 1 > 0) {
     swap(index - 1, index)
     index -= 1
    }
    ++index
   } 
   else {
    ++index
    continue@outer
   }
  }
  sublistCount /= 2
 }
 return this
}

fun main(args: Array<String>) {
 var mutableListOfInt = mutableListOf(10, 4, 5, 2, 1, 3, 6, 9, 8, 7)
 print(mutableListOfInt.shellSort().toString())
}
