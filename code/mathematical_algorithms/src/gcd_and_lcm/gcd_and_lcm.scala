object gcdandlcm extends App{
	def gcd(a:Int, b:Int):Int = {
		while(b > 0){
			val r:Int = a % b
			a = b
			b = r
		}
		a
	}

	def lcm(a:Int, b:Int):Int = {
		var num1:Int = 0
		var num2:Int = 0
		var lcm:Int = 0
		if(a > b){
			num1 = a
			num2 = b
		} else {
			num1 = b
			num2 = a
		}
		for(x <- 1 to num2){
			if((num1 * i) % num2 == 0){
				return num1 * i
			}
		}
		return 0
	}
}