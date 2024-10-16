/* 
 * Part of Cosmos by OpenGenus Foundation
*/

fun fibonacci(number: Int): Int {
    if (number <= 1) {
        return number;
    }

    return fibonacci(number - 2) + fibonacci(number -1);
}

fun main() {
    println(fibonacci(1)); // 1
    println(fibonacci(2)); // 1
    println(fibonacci(4)); // 3
    println(fibonacci(8)); // 21
    println(fibonacci(16)); // 987
}
