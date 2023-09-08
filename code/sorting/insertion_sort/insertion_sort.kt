fun insertionSort(array: IntArray) {
    for ((i, value) in array.withIndex()) {
        var j = i

        while (j > 0 ) {
            if (array[j] < array[j - 1]) {
                val temp = array[j]
                array[j] = array[j - 1]
                array[j - 1] = temp

            }
            j--
        }

    }

}

fun main(args: Array<String>) {
    val input  = intArrayOf(4, 3, 5, 6, 2, 1)
    input.forEach { i -> println(i) }
    insertionSort(input)
    input.forEach { i -> println(i) }
}