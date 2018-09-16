
sealed trait TwoThree[T] {
	def insert(newEl: T): TwoThree[T]
	def height(): Int
	def printSideways(indent: Int): Unit
}

case class OneLeaf[T](data: T)(implicit ord: Ordering[T]) extends TwoThree[T] {
	def insert(newEl: T): TwoThree[T] = {
		if (newEl == data)            this
		else if (ord.lt(newEl, data)) TwoLeaf(newEl, data)
		else 						  TwoLeaf(data, newEl)
	}	
	def height(): Int = 1
	def printSideways(indent: Int): Unit = {
		println("\t" * indent + data)
	}
}

case class TwoLeaf[T](dataLeft: T, dataRight: T)(implicit ord: Ordering[T]) extends TwoThree[T] {
	def insert(newEl: T): TwoThree[T] = {
		if (newEl == dataLeft || newEl == dataRight) this
		else if (ord.lt(newEl, dataLeft))  			 TwoNode(dataLeft, OneLeaf(newEl), OneLeaf(dataRight))
		else if (ord.lt(newEl, dataRight)) 			 TwoNode(newEl, OneLeaf(dataLeft), OneLeaf(dataRight))
		else 							   			 TwoNode(dataRight, OneLeaf(dataLeft), OneLeaf(newEl))
	}	
	def height(): Int = 1
	def printSideways(indent: Int): Unit = {
		println("\t" * indent + dataRight)
		println("\t" * indent + dataLeft)
	}
}

case class TwoNode[T](data: T, left: TwoThree[T], right: TwoThree[T])(implicit ord: Ordering[T]) extends TwoThree[T] {
	def insert(newEl: T): TwoThree[T] = {
		if (newEl == data) {
			this
		}
		else if (ord.lt(newEl, data)) {
			left match {
				case _: OneLeaf[T] => copy(left = left.insert(newEl))
				case TwoLeaf(leftData, rightData) =>
					if (ord.lt(newEl, leftData)) {
						ThreeNode(leftData, data, OneLeaf(newEl), OneLeaf(rightData), right)
					}
					else if (ord.lt(newEl, rightData)) {
						ThreeNode(newEl, data, OneLeaf(leftData), OneLeaf(rightData), right)
					}
					else {
						ThreeNode(rightData, data, OneLeaf(leftData), OneLeaf(newEl), right)
					}
				case leftTwo: TwoNode[T] => leftTwo.insert(newEl) match {
						case twoNodeChild: TwoNode[T] => 
							ThreeNode(twoNodeChild.data, data, twoNodeChild.left, twoNodeChild.right, right)
						case otherChild: TwoThree[T] => this.copy(left = otherChild)
					}
				case t: ThreeNode[T] => this.copy(left = t)
			}
		}
		else {
			right match {
				case _: OneLeaf[T] => copy(right = right.insert(newEl))
				case TwoLeaf(leftData, rightData) =>
					if (ord.gt(newEl, rightData)) {
						ThreeNode(data, rightData, left, OneLeaf(leftData), OneLeaf(newEl))
					}
					else if (ord.gt(newEl, leftData)) {
						ThreeNode(data, newEl, left, OneLeaf(leftData), OneLeaf(rightData))
					}
					else {
						ThreeNode(data, leftData, left, OneLeaf(newEl), OneLeaf(rightData))
					}
				case rightTwo: TwoNode[T] => rightTwo.insert(newEl) match {
						case twoNodeChild: TwoNode[T] => 
							ThreeNode(data, twoNodeChild.data, left, twoNodeChild.left, twoNodeChild.right)
						case otherChild: TwoThree[T] => this.copy(right = otherChild)
					}
				case t: ThreeNode[T] => this.copy(right = t)
			}
		}
	}
	def height(): Int = 1 + left.height()
	def printSideways(indent: Int): Unit = {
		right.printSideways(indent + 1)
		println("\t" * indent + data)
		left.printSideways(indent + 1)
	}
}

case class ThreeNode[T](dataLeft: T, dataRight: T, left: TwoThree[T], mid: TwoThree[T], right: TwoThree[T])(implicit ord: Ordering[T]) extends TwoThree[T] {
	def insert(newEl: T): TwoThree[T] = {
		if (newEl == dataLeft || newEl == dataRight) {
			this
		}
		else if (ord.lt(newEl, dataLeft)) {
			left.insert(newEl) match {
				case t: TwoNode[T] =>
					TwoNode(dataLeft,
						t,
						TwoNode(dataRight, mid, right))
				case t: TwoThree[T] => this.copy(left = t)
			}
		}
		else if (ord.lt(newEl, dataRight)) {
			mid.insert(newEl) match {
				case TwoNode(d, l, r) =>
					TwoNode(d,
						TwoNode(dataLeft, left, l),
						TwoNode(dataRight, r, right))
				case t: TwoThree[T] => this.copy(mid = t)
			}
		}
		else {
			right.insert(newEl) match {
				case t: TwoNode[T] =>
					TwoNode(dataRight,
						TwoNode(dataLeft, left, mid),
						t)
				case t: TwoThree[T] => this.copy(right = t)
			}
		}
	}
	def height(): Int = 1 + left.height()
	def printSideways(indent: Int): Unit = {
		right.printSideways(indent + 1)
		println("\t" * indent + dataRight)
		mid.printSideways(indent + 1)
		println("\t" * indent + dataLeft)
		left.printSideways(indent + 1)
	}
}

object Main {
	def main(args: Array[String]): Unit = {
		TwoLeaf(-3, 5).printSideways(0)
		OneLeaf(5).printSideways(0)
		OneLeaf(5).insert(-3).printSideways(0)
		println(OneLeaf(5).insert(-3).insert(5).insert(6))
		println(OneLeaf(5).insert(-3).insert(4))
		println(OneLeaf(5).insert(-3).insert(4).insert(6))
		println(OneLeaf(5).insert(-3).insert(4).insert(6).insert(3))
		OneLeaf(5).insert(-3).insert(4).insert(6).insert(3).insert(7).printSideways(0)
	}
}
