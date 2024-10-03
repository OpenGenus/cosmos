/* Part of Cosmos by OpenGenus Foundation */

import scala.collection._

object LZW {

  def encode(str : String) : List[Int] = {
    var startDict = (1 to 255).map(i => (i.toChar.toString,i)).to(mutable.Map)
    val output : mutable.ListBuffer[Int] = mutable.ListBuffer()

    var p = ""
    for(c <- str){
      if(startDict.contains(p+c)) {
        p = p + c
      } else {
        output.append(startDict.apply(p))
        startDict+=((p+c) -> (startDict.size+1))
        p = c.toString
      }
    }

    if(!p.equals("")) output.append(startDict.apply(p))
    output.toList
  }

  def decode(list : List[Int]) : String = {
    var startDict = (1 to 255).map(i => (i,i.toChar.toString)).to(mutable.Map)
    var w : String = startDict.apply(list.head)
    val output : StringBuilder = new StringBuilder(w)

    for(n <- list.tail){
      val entry = startDict.get(n) match {
        case Some(str) => str
        case None if n == startDict.size => w + w.head
        case _ => throw new IllegalArgumentException("Bad compressed input: " + n)
      }
      output.append(entry)
      startDict+=((startDict.size+1) -> (w + entry.head))
      w = entry
    }

    output.toString
  }

}

object Test extends App {
  val input = "TOBEORNOTTOBEORTOBEORNOT"
  println(input)
  val output = LZW.encode(input)
  println(output)
  val again = LZW.decode(output)
  println(again)
}