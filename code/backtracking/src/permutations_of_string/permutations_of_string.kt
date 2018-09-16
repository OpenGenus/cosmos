// Part of Cosmos by OpenGenus Foundation

fun permute(s: String, l: Int = 0, r: Int = s.length - 1) {
    val builder = StringBuilder(s)
    var i: Int
    if (l == r) {
        println(s)
    } else {
        i = l
        while (i <= r) {
            var tmp = builder[l]
            builder[l] = builder[i]
            builder[i] = tmp

            permute(builder.toString(), l + 1, r)

            tmp = builder[l]
            builder[l] = builder[i]
            builder[i] = tmp

            i++
        }
    }
}

fun main(args: Array<String>) {
    permute("ABC")
    /*
    Output:
    ABC
    ACB
    BAC
    BCA
    CBA
    CAB
     */
}