// Part of Cosmos by OpenGenus Foundation 
object FindingSquare extends App{
	def findingSquare(num:Int):Boolean = {
		for(x <- 1 to num if x * x <= num){
			if(x * x == num) return true
		}
		false
	}

	def printResult(num:Int){
		findingSquare(num) match{
			case true => println(s"$num is perfect square")
			case false => println(s"$num is not perfect square")
		}
	}

	printResult(3)
	printResult(4)
}
