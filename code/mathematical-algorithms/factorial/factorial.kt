// Part of Cosmos by OpenGenus Foundation

fun factorial(n: Int): Int {
    return if (n == 0) {
        1
    } else {
        n * factorial(n-1)
    }
}

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val result = factorial(n)
    println(result)
