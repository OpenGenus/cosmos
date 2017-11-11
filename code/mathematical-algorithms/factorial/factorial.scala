object Factorial extends App {
	def factorial(n : Int) : Long = {
		n match {
			case 0 => 1
			case _ => n * factorial(n-1)
		}
	}

	println(factorial(5))
}