import java.util.*

/**
 * Created by gazollajunior on 03/04/16.
 */

fun <T:Comparable<T>> insertionsort(items:MutableList<T>):List<T>{
    if (items.isEmpty()){
        return items
    }
    for (count in 1..items.count() - 1){
        val item = items[count]
        var i = count
        while (i>0 && item < items[i - 1]){
            items[i] = items[i - 1]
            i -= 1
        }
        items[i] = item
    }
    return items
}


fun main(args: Array<String>) {
    val names = mutableListOf("one", "Two", "Zack", "Daniel", "Adam")
    println(names)
    var ordered = insertionsort(names)
    println(ordered)

}
