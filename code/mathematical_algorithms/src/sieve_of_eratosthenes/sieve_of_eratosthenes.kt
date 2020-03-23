import java.util.Scanner

fun main() {
    // Let we want to find the Prime Numbers below a certain number.
    val scanner = Scanner(System.`in`)
    print("Enter an Integer : ")
    var num = scanner.nextInt()
    var prime = Array(num){ true }
    var sqre = square_root(num.toFloat())
    for (i in 2 until sqre.toInt()) {
        if (prime[i]) {
            for (j in (2 * i)..(num) step i) {
                prime[j] = false
            }
        }
    }
    // Printing Prime Numbers In the range of (1 to given Number)
    for (primes in 2 until num) {
        if (prime[primes]) {
            print("$primes ")
        }
    }
}

// Input:- Enter an Integer : 89
// Output:- 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83
