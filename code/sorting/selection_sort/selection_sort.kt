// Part of Cosmos by OpenGenus Foundation

import java.util.*

fun <T : Comparable<T>> sort(array: Array<T>) {
    for (i in array.indices) {
        var min = i
        for (j in i + 1 until array.size) {
            /* find local min */
            if (array[j] < array[min]) {
                min = j
            }
        }
        val temp = array[i]
        array[i] = array[min]
        array[min] = temp
    }
}

fun main(args: Array<String>) {
    val arr = arrayOf(1, 5, 2, 5, 2, 9, 7)
    sort(arr)
    print(Arrays.toString(arr))
}