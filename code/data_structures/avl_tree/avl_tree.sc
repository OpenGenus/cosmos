sealed abstract class AVLTree[+A]

case object AVLNil extends AVLTree[Nothing]

case class AVLNode[+A] private (val label: A,
                       val left: AVLTree[A],
                       val right: AVLTree[A]) extends AVLTree[A] {
    def this(label: A) = this(label, AVLNil, AVLNil)
}

object AVLNode {
    def apply[A](label: A): AVLNode[A] = new AVLNode(label)
	
    private def avlInvariant[A: Ordering](t: AVLTree[A]): Boolean = 
    t match {
        case AVLNil => true
        case AVLNode(_, AVLNil, AVLNil) => true
        case AVLNode(v, l, r) => {
            val ord = implicitly[Ordering[A]]
            val b = balance(t)
            val balanced = (b <= 1) && (-1 <= b)
            val leftOkay = l match {
                case AVLNil => true
                case AVLNode(_, _, _) => avlInvariant(l) &&
                                         ord.lt(max(l), v)
            }
            val rightOkay = r match {
                case AVLNil => true
                case AVLNode(_, _, _) => avlInvariant(r) &&
                                         ord.gt(min(r), v)
            }
            
            balanced && leftOkay && rightOkay
        }
    }

    
    def depth[A](t: AVLTree[A]): Int = t match {
        case AVLNil => 0
        case AVLNode(_,l,r) => 1 + math.max(depth(l), depth(r))
    }

   
    def balance[A](t: AVLTree[A]): Int = t match {
        case AVLNil => 0
        case AVLNode(_,l,r) => depth(l) - depth(r)
    }

   
    def search[A: Ordering](a: A)(t: AVLTree[A]): Boolean = {
        require(avlInvariant(t), "Tree is not AVL!")
        t match {
            case AVLNil => false
            case AVLNode(b, l, r) => {
                val ord = implicitly[Ordering[A]]
                if (ord.equiv(b, a)) true
                else if (ord.gt(b, a)) search(a)(l)
                else search(a)(r)
            }
        }
    } 
    
   
    def min[A: Ordering](t: AVLTree[A]): A = {
        require(t != AVLNil, "can't get min of empty tree")
        t match{
            case AVLNode(v, AVLNil, _) => v
            case AVLNode(_, l, _) => min[A](l)
        }
    }

  
    def max[A: Ordering](t: AVLTree[A]): A = {
        require(t != AVLNil, "can't get max of empty tree")
        t match {
            case AVLNode(v, _, AVLNil) => v
            case AVLNode(_, _, r) => max[A](r)
        }
    }

   
    def insert[A: Ordering](a: A)(t: AVLTree[A]): AVLTree[A] = {
        require(avlInvariant(t), "Tree is not AVL")
        val tree = t match {
            case AVLNil => AVLNode(a)
            case AVLNode(b, l, r) => {
                val ord = implicitly[Ordering[A]]
                if (ord.equiv(b, a)) t
                else if (ord.gt(b, a)) AVLNode(b, insert(a)(l), r)
                else AVLNode(b, l, insert(a)(r))
            }
        }
        repair(tree)
    } ensuring(r => avlInvariant(r) && search(a)(r))
    
    
    private def repair[A](t: AVLTree[A]): AVLTree[A] = {
        val tree@AVLNode(v, l, r) = t
        val bal = balance(tree)
        if (bal == 2) {
          
            val lbal = balance(l)
            if (lbal > 0) {
              
                rightRotate(tree)
            } else if (lbal < 0) {
                
                val newl = leftRotate(l)
                rightRotate(AVLNode(v, newl, r))
            } else tree
        } else if (bal == -2) {
           
            val rbal = balance(r)
            if (rbal < 0) {
             
                leftRotate(tree)
            } else if (rbal > 0) {
              
                val newr = rightRotate(r)
                leftRotate(AVLNode(v, l, newr))
            } else tree
        }
        else tree
    }

    def remove[A: Ordering](a: A)(t: AVLTree[A]): AVLTree[A] = {
        require(avlInvariant(t), "Tree is not AVL")
        val ord = implicitly[Ordering[A]]
        val tree = t match {
            case AVLNil => AVLNil
            
            case c@AVLNode(b, AVLNil, AVLNil) => {
                if (ord.equiv(b, a)) AVLNil
                else c
            }
           
            case c@AVLNode(b, l, AVLNil) => {
                if (ord.equiv(b, a)) l
                else if(ord.lt(b, a)) c
                else AVLNode(b, remove(a)(l), AVLNil)
            }
            case c@AVLNode(b, AVLNil, r) => {
                if (ord.equiv(b, a)) r
                else if(ord.gt(b, a)) c
                else AVLNode(b, AVLNil, remove(a)(r))
            }
          
            case AVLNode(b, l, r) if ord.equiv(b,a) => {
              
                val m = min(r)
                val newr = remove(m)(r)
                AVLNode(m, l, newr)
            }
            case AVLNode(b, l, r) => {
                if (ord.gt(b, a)) AVLNode(b, remove(a)(l), r)
                else AVLNode(b, l, remove(a)(r))
            }
        }
        if (tree == AVLNil) tree
        else repairDelete(tree)
    } ensuring(r => avlInvariant(r) && !search(a)(r))

    private def repairDelete[A: Ordering](t: AVLTree[A]) = {
        val tree@AVLNode(v, l, r) = t
        val bal = balance(tree)
        if (bal == 2) {
            // deletion in right subtree
            val toRot = if (balance(l) < 0) {
                // left right
                val newL = leftRotate(l)
                AVLNode(v, newL, r)
            } else tree // left left
            rightRotate(toRot)
        } else if (bal == -2) {
            // deletion in left subtree
            val toRot = if (balance(r) < 0) {
                // right left
                val newR = rightRotate(r)
                AVLNode(v, l, newR)
            } else tree // right right
            leftRotate(toRot) 
        } else tree
    } ensuring(r => avlInvariant(r))
	
    private def leftRotate[A](t: AVLTree[A]): AVLTree[A] = t match {
        case AVLNode(x, l, AVLNode(z, m, r)) => {
            AVLNode(z, AVLNode(x, l, m), r)
        }
        case _ => sys.error("tree not suitable for left rotate!")
    }
	
    private def rightRotate[A](t: AVLTree[A]): AVLTree[A] = t match {
        case AVLNode(x, AVLNode(z, l, m), r) => {
            AVLNode(z, l, AVLNode(x, m, r))
        }
        case _ => sys.error("tree not suitable for right rotate!")
    } 
}
class AvlTests extends FunSuite {
    import AVLNode._
    test("avl trees basics") {
        val avl = AVLNode(4)
        assert(depth(avl) === 1)
        assert(avl.left === AVLNil)
        assert(balance(avl) === 0)
    }

    test("avl trees search") {
        val avl = insert(4)(insert(1)(AVLNode(2)))
        assert(search(1)(avl))
        assert(search(2)(avl))
        assert(search(4)(avl))
        assert(!search(5)(avl))
    }

    test("avl trees complex interaction") {
        val avl = AVLNil
        val avl2 = insert(2)(avl)
        val avl3 = insert(5)(avl2)
        val avl4 = insert(1)(avl3)
        val avl5 = insert(4)(avl4)
        val avl6 = insert(2)(avl5)
        assert(avl6 === avl5)
        val avl7 = insert(16)(avl6)
        val avl8 = insert(-2)(avl7)
        assert(search(2)(avl8))
        assert(search(5)(avl8))
        assert(search(1)(avl8))
        assert(search(4)(avl8))
        assert(search(16)(avl8))
        assert(search(-2)(avl8))
        val avl9  = remove(2)(avl8)
        val avl10 = remove(5)(avl9)
        val avl11 = remove(1)(avl10)
        val avl12 = remove(4)(avl11)
        val avl13 = remove(2)(avl12)
        assert(avl13 === avl12)
        val avl14 = remove(16)(avl13)
        val avl15 = remove(-2)(avl14)
        assert(avl15 === AVLNil)
    }
}
