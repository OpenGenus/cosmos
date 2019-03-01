import java.math.BigInteger
import java.util.*

/**
 * Created by Phuwarin on 10/4/2018
 * Part of Cosmos by OpenGenus
 */

object Factorial {

    @JvmStatic
    fun main(args: Array<String>) {
        print("Enter a number: ")
        val enterNum = Scanner(System.`in`)
        val n = enterNum.nextLong()
        println("Factorial is: " + factorial(n))
    }

    private fun factorial(n: Long): BigInteger {
        var result = BigInteger.ONE
        for (i in 1..n) {
            result = result.multiply(BigInteger.valueOf(i))
        }
        return result
    }
}
