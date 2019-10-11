import java.util.*

/**
 * Created by Phuwarin on 10/1/2018
 * Part of Cosmos by OpenGenus
 */

object AffineKotlin {

    private val SCANNER = Scanner(System.`in`)
    private const val ALPHABET_SIZE = 26

    private val command: Int
        get() = SCANNER.nextInt()

    @JvmStatic
    fun main(args: Array<String>) {
        do {
            print("Type 1 for encryption and 2 for decryption then Enter >> ")
            val command = command
            when (command) {
                1 -> encryption()
                2 -> decryption()
                else -> {
                    println("Command error, pls try again.")
                }
            }
        } while (command != 1 && command != 2)
    }

    private fun decryption() {
        var a: Int
        var aInverse = 0
        var isAOk = false

        print("Enter cipherText which want to decryption >> ")
        val cipherText = SCANNER.next()

        while (!isAOk) {
            print("Enter key 'a' >> ")
            a = SCANNER.nextInt()
            if (gcd(a, ALPHABET_SIZE) == 1) {
                isAOk = true
                aInverse = findInverse(a.toDouble(), ALPHABET_SIZE.toDouble())
            } else {
                println("'a' is not ok, pls try again.")
            }
        }

        print("Enter key 'b' >> ")
        val b: Int = SCANNER.nextInt()
        decrypt(aInverse, b, cipherText)
    }

    private fun decrypt(aInverse: Int, b: Int, cipherText: String?) {
        if (cipherText == null || cipherText.isEmpty()) {
            println("Plaintext has a problem. Bye bye :)")
            return
        }

        val cipherText = cipherText.toLowerCase()
        val plaintext = StringBuilder()
        var z: Int
        var j: Int

        for (i in 0 until cipherText.length) {
            val agent = cipherText[i]
            z = aInverse * (agent.toInt() - 97 - b)
            j = if (z < 0) minusMod(z, ALPHABET_SIZE) else z % ALPHABET_SIZE
            plaintext.append(('A'.toInt() + j).toChar())
        }
        println("Plaintext: $plaintext")
    }

    private fun minusMod(minus: Int, mod: Int): Int {
        val a = Math.abs(minus)
        return mod * (a / mod + 1) - a
    }

    private fun findInverse(firstNumber: Double, anotherNumber: Double): Int {
        var a1: Int
        var b1: Int
        var a2: Int
        var b2: Int
        var r: Int
        var q: Int
        var a2Temp: Int
        var b2Temp: Int
        var n1: Int
        var n2: Int
        val max: Int

        if (firstNumber > anotherNumber) {
            max = firstNumber.toInt()
            n1 = firstNumber.toInt()
            n2 = anotherNumber.toInt()
        } else {
            max = anotherNumber.toInt()
            n1 = anotherNumber.toInt()
            n2 = firstNumber.toInt()
        }

        b2 = 1
        a1 = b2
        a2 = 0
        b1 = a2
        a2Temp = a2
        b2Temp = b2

        r = n1 % n2
        q = n1 / n2

        while (r != 0) {
            n1 = n2
            n2 = r
            a2 = a1 - q * a2
            b2 = b1 - q * b2
            a1 = a2Temp
            b1 = b2Temp
            a2Temp = a2
            b2Temp = b2
            r = n1 % n2
            q = n1 / n2
        }

        val result: Int
        result = if (firstNumber == max.toDouble()) {
            if (a2 < 0) {
                (a2 - anotherNumber * Math.floor(a2 / anotherNumber)).toInt()
            } else {
                a2
            }
        } else {
            if (b2 < 0) {
                (b2 - anotherNumber * Math.floor(b2 / anotherNumber)).toInt()
            } else
                b2
        }
        return result
    }

    private fun encryption() {
        var isAOk = false
        var isBOk = false
        var a = 0
        var b = 0

        print("Enter plaintext which want to encryption >> ")
        val plaintext = SCANNER.next()

        while (!isAOk) {
            print("Choose 'a' but gcd (a,26) must equal 1\n" + "'a' might be {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25} >> ")
            a = SCANNER.nextInt()
            if (gcd(a, ALPHABET_SIZE) == 1) {
                isAOk = true
            } else {
                println("'a' is not ok, pls try again.")
            }
        }

        while (!isBOk) {
            print("Choose 'b' which number you want but not equal 1 >> ")
            b = SCANNER.nextInt()
            if (b != 1) {
                isBOk = true
            } else {
                println("'b' is not ok, pls try again.")
            }
        }
        encrypt(a, b, plaintext)
    }

    private fun gcd(a: Int, b: Int): Int {
        return if (b == 0) a else gcd(b, a % b)
    }

    private fun encrypt(a: Int, b: Int, plaintext: String?) {
        if (plaintext == null || plaintext.isEmpty()) {
            println("Plaintext has a problem. Bye bye :)")
            return
        }

        val plaintext = plaintext.toLowerCase()
        val cipherText = StringBuilder()

        for (i in 0 until plaintext.length) {
            val agent = plaintext[i]
            val value = (a * (agent.toInt() - 97) + b) % ALPHABET_SIZE
            cipherText.append((value + 97).toChar())
        }
        println("cipherText: $cipherText")
    }
}
