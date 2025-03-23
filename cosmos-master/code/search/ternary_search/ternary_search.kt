// Part of Cosmos by OpenGenus Foundation

fun <T : Comparable<T>> ternarySearch(a: Array<T>, target: T, start: Int = 0, end: Int = a.size): Int {
    if (start < end) {
        val midpoint1 : Int = start + (end - start) / 3
        val midpoint2 : Int = start + 2 * (end - start) / 3

        return when (target) {
            a[midpoint1] -> midpoint1
            a[midpoint2] -> midpoint2
            a[midpoint1] < a[midpoint2] -> ternarySearch(a, target, midpoint1, end)
            else -> ternarySearch(a, target, start, midpoint2)
        }
    }
    return -1
}

fun main(args: Array<String>) {
    val sample: Array<Int> = arrayOf(13, 17, 19, 23, 29, 31, 37, 41, 43)
    val key = 23

    val result = ternarySearch(sample, key)

    println(when (result) {
        -1 -> "$key is not in $sample"
        else -> "Position of $key is $result"
    })
}