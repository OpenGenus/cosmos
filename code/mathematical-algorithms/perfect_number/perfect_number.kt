fun is_perfect(num: Int): Boolean {
    var sum = 0
    for (i in 1..num) {
        if (num % i == 0) {
            sum += i
        }
    }
    println("$sum <> $num")
    return sum == num
}

fun main(args: Array<String>) {
    for (i in 1..100) {
        println("is_perfect($i): ${is_perfect(i)}")
    }
       
    println("is_perfect(496) = ${is_perfect(496)}")
}