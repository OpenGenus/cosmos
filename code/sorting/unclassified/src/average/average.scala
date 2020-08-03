object Average extends App{
	def average(num:Array[Double]):Double = {
		val sum:Double = num.foldLeft(0.0){(a, b) => a + b}
		sum / num.size
	}

	val arr:Array[Double] = Array(1, 2, 3, 4, 5)
	println(average(arr))
}