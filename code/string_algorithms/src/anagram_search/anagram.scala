object Anagram {
  def isAnagram(a: String, b: String): Boolean = {
    val a1 = a.replaceAll("\\s", "")
    val b1 = b.replaceAll("\\s", "")
    if (a1.length != b1.length)
      false
    else
      frequencyMap(a1.toLowerCase()) == frequencyMap(b1.toLowerCase())
  }

  def frequencyMap(str: String) = str.groupBy(identity).mapValues(_.length)

  def main(args: Array[String]): Unit = {
    print(isAnagram("hello", "olleh"))
    print(isAnagram("hello world", "woorll lehd"))
    println(isAnagram("1", "2"))
  }
}
