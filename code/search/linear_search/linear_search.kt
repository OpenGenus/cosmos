// Part of Cosmos by OpenGenus Foundation

fun <T> linearSearch(array: Array<T>, key: T): Int? {
    for (i in 0 until array.size) {
        if (array[i] == key) {
            return i
        }
    }
    return null
}

fun main(args: Array<String>) {
    val sample: Array<Int> = arrayOf(13, 17, 19, 23, 29, 31, 37, 41, 43)
    val key = 23

    val result = linearSearch(sample, key)

    println(when (result) {
        null -> "$key is not in sample"
        else -> "Position of $key is $result"
    })
}