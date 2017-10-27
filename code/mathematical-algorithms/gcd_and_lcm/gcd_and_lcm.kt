fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)

fun lcm(a: Int, b: Int): Int = if (b == 0) 0 else a * b / gcd(a, b)

fun main(args: Array<String>) {
    val (a, b) = readLine()!!.split(' ').map(String::toInt)

    println("Enter two numbers separated by a space")
    println("GCD(" + a + ", " + b + "): " + gcd(a, b))
    println("LCM(" + a + ", " + b + "): " + lcm(a, b))
}
