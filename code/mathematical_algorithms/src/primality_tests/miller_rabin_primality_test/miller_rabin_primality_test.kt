 

val bigTwo = BigInteger.valueOf(2L)
 
fun isProbablyPrime(n: BigInteger, k: Int): Boolean {
    require (n > bigTwo && n % bigTwo == BigInteger.ONE) { "Must be odd and greater than 2" }
    var x = 0
    val n1 = n - BigInteger.ONE
    var d: BigInteger
    do {
        x++
        d = n1.shiftRight(s)
    }
    while (d % bigTwo == BigInteger.ZERO)
 
    val rand = Random()
    loop@ for (i in 1..k) {
        var a: BigInteger
        do {
            a = BigInteger(n.bitLength(), rand)
        }
        while(a < bigTwo || a > nn) // make sure it's in the interval [2, n - 1]
 
        var s = a.modPow(d, n)
        if (s == BigInteger.ONE || s == nn) continue
        for (r in 1 until s) {
            s =  (s * s) % n
            if (s == BigInteger.ONE) return false
            if (s == n1) break@loop
        }
        return false
    }
    return true
}
 
fun main(args: Array<String>) {
    val bia = arrayOf(
        BigInteger("45473172376"),
        BigInteger("4547337172376")
    )
    for (bi in bia)
        println("$bi is ${if (isProbablyPrime(bi, k)) "probably prime" else "composite"}")
}
