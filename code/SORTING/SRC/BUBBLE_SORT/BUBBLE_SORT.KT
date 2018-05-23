// Part of Cosmos by OpenGenus Foundation
fun <T : Comparable<T>> bubbleSort(array: Array<T>) {
    var flag : Boolean
    for (i in array.indices) {
        flag = true
        for (j in 0 until (array.size - i - 1)) {
            if (array[j] > array[j + 1]) {
                array[j] = array[j + 1].also { array[j+1] = array[j] }
                flag = false
            }
        }
        if (flag) break
    }
}

fun main(args: Array<String>) {
    val sample: Array<Int> = arrayOf(0, 10, 2, 6, 1, 3, 5, 4, 9, 7, 8)
    bubbleSort(sample)

    println("Sorted: "+sample.joinToString())
}
