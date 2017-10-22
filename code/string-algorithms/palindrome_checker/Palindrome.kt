class Palindrome {
fun main(args : Array<String>) {
val kayakString = "kayak"
val levelString = "level"
val sosString = "sos"
val reviverString = "reviver"
val listOfPalindromes = listOf<String>(kayakString, levelString, sosString, reviverString)

    fun checkIfPalindrome(list : List<String>) : Boolean {
        return (list[0] == list[0].reversed()
                && list[1] == list[1].reversed()
                && list[2] == list[2].reversed()
                && list[3] == list[3].reversed())
    }

    checkIfPalindrome(listOfPalindromes)
  }
}
