// Part of Cosmos by OpenGenus Foundation

fun <T : Comparable<T>> binarySearch(a: Array<T>, key: T): Int? {
    var lowerBound = 0
    var upperBound = a.size
    while (lowerBound < upperBound) {
        val middleIndex = lowerBound + (upperBound - lowerBound) / 2
        when {
            a[middleIndex] == key -> return middleIndex
            a[middleIndex] < key -> lowerBound = middleIndex + 1
            else -> upperBound = middleIndex
        }
    }
    return null
}

fun main(args: Array<String>) {
    val sample: Array<Int> = arrayOf(13, 17, 19, 23, 29, 31, 37, 41, 43)
    val key = 23

    val result = binarySearch(sample, key)

    println(when (result) {
        null -> "$key is not in $sample"
        else -> "Position of $key is $result"
    })
}
