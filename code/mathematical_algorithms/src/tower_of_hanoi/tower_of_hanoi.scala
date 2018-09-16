import scala.collection.mutable.ArrayStack

object TowerOfHanoi extends App{
	var size:Int = 5
	var a = new ArrayStack[Int]
	for(i <- (1 to size).reverse){
		a += i
	}
	var b = new ArrayStack[Int]
	var c = new ArrayStack[Int]
	var count:Int = 0

	def move(n:Int, source:ArrayStack[Int], target:ArrayStack[Int], auxiliary:ArrayStack[Int]){
		if(n > 0){
			move(n-1, source, auxiliary, target)
			target += source.pop
			println(s"$a, $b, $c")
			move(n-1, auxiliary, target, source)
			count += 1
		}
	}
	move(size, a, c, b)
	println(count)
}