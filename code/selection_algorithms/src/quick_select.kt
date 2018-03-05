const val MAX = Int.MAX_VALUE
val rand = java.util.Random()
 
fun partition(list:IntArray, left: Int, right:Int, pivotIndex: Int): Int {
 
    val pivotValue = list[pivotIndex]
    list[pivotIndex] = list[right]
    list[right] = pivotValue
    var storeIndex = left
 
    for (i in left until right) {
        if (list[i] < pivotValue) {
            val tmp = list[storeIndex]
            list[storeIndex] = list[i]
            list[i] = tmp
            storeIndex++
        }
    }
 
    val temp = list[right]
    list[right] = list[storeIndex]
    list[storeIndex] = temp
    return storeIndex
 
}
 
tailrec fun quickSelect(list: IntArray, left: Int, right: Int, k: Int): Int {
 
    if (left == right) return list[left]
    var pivotIndex = left + Math.floor((rand.nextInt(MAX) % (right - left + 1)).toDouble()).toInt()
    pivotIndex = partition(list, left, right, pivotIndex)
    if (k == pivotIndex)
        return list[k]
    else if (k < pivotIndex)
        return quickSelect(list, left, pivotIndex - 1, k)
    else
        return quickSelect(list, pivotIndex + 1, right, k)
 
}
 
fun main(args: Array<String>) {
 
    val list = intArrayOf(9, 8, 7, 6, 5, 0, 1, 2, 3, 4)
    val right = list.size - 1
 
    for (k in 0..9) {
        print(quickSelect(list, 0, right, k))
        if (k < 9) print(", ")
    }
    println()
 
}
