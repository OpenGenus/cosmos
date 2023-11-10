/* 
 * Part of Cosmos by OpenGenus Foundation
*/

import kotlin.math.*

fun checkSquare(number: Int) : Boolean {
    return sqrt(number.toDouble()) == floor(sqrt(number.toDouble()));
}

fun main() {
    println(checkSquare(0)); // true
    println(checkSquare(1)); // true
    println(checkSquare(2)); // false
    println(checkSquare(4)); // true
    println(checkSquare(8)); // false
    println(checkSquare(16)); // true
    println(checkSquare(32)); // false
    println(checkSquare(64)); // true
}
