package net.wrap_trap.utils.rbtree

object RedBlackTree {

    object Color extends Enumeration {
        val Red, Black = Value
    }
	
    class Hash[K, V] {}

    case class Leaf[K, V] extends Hash[K, V] {}

    case class Node[K, V](val color: Color.Value, val left: Hash[K, V], val data: (K, V), val right: Hash[K, V]) extends Hash[K, V] {}

    def turnB[K, V](t: Node[K, V]) : Node[K, V] = {
        Node[K, V](Color.Black, t.left, t.data, t.right)
    }
    
    def insert[K, V](data: (K, V), r: Hash[K, V])(implicit comp: Ordering[K]): Hash[K, V] = {
        turnB(insert1(data._1, data._2, r))
    }
    
    def insert1[K, V](kx: K, vx: V, r: Hash[K, V])(implicit comp: Ordering[K]): Node[K, V] = r match {
        case Leaf() => new Node[K, V](Color.Red, Leaf(), (kx, vx), Leaf())
        case Node(color, left, (k, v), right) => compareKeys(kx, k) match {
          case -1 => balance(Node(color, insert1(kx, vx, left), (k, v), right))
          case 1 => balance(Node(color, left, (k, v), insert1(kx, vx, right)))
          case 0 => balance(Node(color, left, (k, v), right))
        }
    }
    
    def compareKeys[K: Ordering](k1: K, k2: K): Int = {
        val order = Ordering[K].compare(k1, k2)
        if (order > 0) {
            return 1
        }
        if (order < 0) {
            return -1
        }
        return 0
    }
    
    def balance[K, V](n: Node[K, V]) : Node[K, V] = n match {
        case Node(Color.Black, Node(Color.Red, Node(Color.Red, a, x, b), y, c), z, d) 
            => Node(Color.Red, Node(Color.Black, a, x, b), y, Node(Color.Black, c, z, d))
        case Node(Color.Black, Node(Color.Red, a, x, Node(Color.Red, b, y, c)), z, d) 
            => Node(Color.Red, Node(Color.Black, a, x, b), y, Node(Color.Black, c, z, d))
        case Node(Color.Black, a, x, Node(Color.Red, b, y, Node(Color.Red, c, z, d))) 
            => Node(Color.Red, Node(Color.Black, a, x, b), y, Node(Color.Black, c, z, d))
        case Node(Color.Black, a, x, Node(Color.Red, Node(Color.Red, b, y, c), z, d)) 
            => Node(Color.Red, Node(Color.Black, a, x, b), y, Node(Color.Black, c, z, d))
        case Node(c, a, x, b) => Node(c, a, x, b)
    }
    
    def fromList[K, V](l: List[(K, V)], t: Hash[K, V])(implicit comp: Ordering[K]): Hash[K, V] = {
        if(l.isEmpty) t
        else fromList(l.tail, insert(l.head, t))
    }

    def search[K, V](kx: K, t: Hash[K, V])(implicit comp: Ordering[K]): Option[V] = t match {
        case Leaf() => None
        case Node(c, l, (k, v), r) => compareKeys(kx, k) match {
            case -1 => search(kx, l)
            case 0 => Some(v)
            case 1 => search(kx, r)
        }
    }
    
    def showTree[K, V](t: Hash[K, V]): String = {
        showTree1("", "root", t)
    }
    
    def showTree1[K, V](indent: String, lr: String, t: Hash[K, V]): String = t match {
    	case Leaf() => "\n"
    	case Node(c, l, (k, v), r)
        	=> "(" + lr + ") " + c + ": " + k + " -> " + v + "\n" + indent + "+ " + showTree1("  " + indent, "left", l) + indent + "+ " + showTree1("  " + indent, "right", r)
    }
    
    def printTree[K, V](t: Hash[K, V]): Unit = {
        System.out.println(showTree(t));
    }
    
    def main(args : Array[String]) : Unit = {
        val l = List(("foo", "bar"), ("hoge", "hogehoge"), ("abc", "def"), ("123", "456"), ("スカラ", "テスト"))
        printTree(fromList(l, Leaf()))
    }
}
