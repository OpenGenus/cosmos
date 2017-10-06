// Part of Cosmos by OpenGenus Foundation
public class LinkedList {
	private class Node {
		int data;
		Node next;

		public Node() {

		}

	}

	private Node head;
	private Node tail;
	private int size;

	public int size() {
		return this.size;

	}

	public boolean isEmpty() {
		return this.size == 0;
	}

	public void display() {
		Node temp;
		temp = head;
		System.out.println("------------------------------------------");
		while (temp != null) {
			System.out.print(temp.data + "\t");
			temp = temp.next;

		}
		System.out.println(".");
		System.out.println("--------------------------------------------");
	}

	public int getfirst() throws Exception {
		if (this.size == 0) {
			throw new Exception("LinkedList is empty");

		}
		return this.head.data;

	}

	public int getLast() throws Exception {
		if (this.size == 0) {
			throw new Exception("LinkedList is empty");
		}

		return this.tail.data;
	}

	public int getAt(int idx) throws Exception {
		if (this.size == 0) {
			throw new Exception("LinkedList is empty");
		}
		if (idx < 0 || idx >= this.size) {
			throw new Exception("index out of bound");
		}
		Node temp = head;
		for (int i = 0; i < idx; i++) {
			temp = temp.next;
		}
		return temp.data;
	}

	public void addLast(int data) {
		Node nn = new Node();
		nn.data = data;
		nn.next = null;

		if (this.size == 0) {
			this.head = nn;
			this.tail = nn;

		} else {

			this.tail.next = nn;
			this.tail = nn;
		}

		this.size++;
	}

	public void addfirst(int data) {
		Node nn = new Node();
		nn.data = data;

		if (this.size == 0) {
			this.head = nn;
			this.tail = nn;
		} else {
			nn.next = this.head;
			this.head = nn;
		}
		this.size++;

	}

	private Node getnodeAt(int idx) throws Exception {
		if (this.size == 0) {
			throw new Exception("LinkedList is empty");
		}
		if (idx < 0 || idx >= this.size) {
			throw new Exception("index out of bound");
		}
		Node temp = head;
		for (int i = 0; i < idx; i++) {
			temp = temp.next;
		}
		return temp;
	}

	public void addAt(int data, int idx) throws Exception {
		Node nn = new Node();
		nn.data = data;

		if (idx < 0 || idx > this.size) {
			throw new Exception("index out of bound");
		}
		if (idx == 0) {
			this.addfirst(data);
		} else if (idx == this.size) {
			this.addLast(data);
		}

		else {

			Node nm = this.getnodeAt(idx - 1);
			Node np1 = nm.next;

			nn.next = np1;
			nm.next = nn;

		}
		this.size++;
	}

	public int removeFirst() throws Exception {
		if (this.size == 0) {
			throw new Exception("LinkedList is empty");
		}

		int rv = this.head.data;

		if (this.size == 1) {
			this.head = null;
			this.tail = null;
		} else {
			this.head = this.head.next;
		}
		this.size--;
		return rv;
	}

	public int removelast() throws Exception {
		if (this.size == 0) {
			throw new Exception("LinkedList is empty");
		}

		int rv = this.tail.data;

		if (this.size == 1) {
			this.head = null;
			this.tail = null;

		} else {
			Node nm = this.getnodeAt(this.size - 2);
			nm.next = null;
			this.tail = nm;

		}
		this.size--;

		return rv;
	}

	public int removeAt(int idx) throws Exception {
		{
			if (this.size == 0) {
				throw new Exception("LinkedList is empty");
			}

			if (idx < 0 || idx > this.size) {
				throw new Exception("index out of bound");
			}
			int rv = 0;

			if (this.size == 1) {
				this.head = null;
				this.tail = null;
			}
			if (idx == 0) {
				this.removeFirst();

			} else if (idx == this.size) {
				this.removelast();
			} else {
				Node nm = this.getnodeAt(idx - 1);
				Node n = nm.next;
				rv = n.data;
				Node nm1 = this.getnodeAt(idx + 1);

				nm.next = nm1;

			}
			this.size--;
			return rv;

		}

	}

	public void displayreverse() throws Exception {
		int i = this.size - 1;

		while (i >= 0) {
			System.out.print(this.getAt(i) + "\t");
			i--;
		}

	}

	// o(n^2)
	public void reverselistDI() throws Exception {
		int left = 0;
		int right = this.size - 1;
		while (left < right) {
			Node leftnode = this.getnodeAt(left);
			Node rightnode = this.getnodeAt(right);

			int temp = leftnode.data;
			leftnode.data = rightnode.data;
			rightnode.data = temp;
			left++;
			right--;

		}

	}

	// o(n)
	public void reverselistPI() {
		Node prev = this.head;
		Node curr = prev.next;

		while (curr != null) {
			Node tc = curr;
			Node tp = prev;

			prev = curr;
			curr = curr.next;
			tc.next = tp;

		}
		Node temp = this.head;
		this.head = this.tail;
		this.tail = temp;

	}

	// o(n)
	public void reverselistPR() {

		reverselistPR_RH(this.head, this.head.next);
		Node temp = this.head;
		this.head = this.tail;
		this.tail = temp;

		this.tail.next = null;

	}

	private void reverselistPR_RH(Node prev, Node curr) {
		if (curr == null) {

			return;
		}
		reverselistPR_RH(curr, curr.next);
		curr.next = prev;

	}

	// o(n)
	public void reverselistDR() {
		// this.reverselistDR(this.head,this.head,0);
		HeapMover left = new HeapMover();
		left.node = this.head;
		reverselistDR1(left, head, 0);

	}

	private Node reverselistDR(Node left, Node right, int floor) {
		if (right == null) {

			return left;

		}

		left = reverselistDR(left, right.next, floor + 1);

		if (floor > this.size / 2) {
			int temp = right.data;
			right.data = left.data;
			left.data = temp;

		}
		return left.next;

	}

	private void reverselistDR1(HeapMover left, Node right, int floor) {
		if (right == null) {

			return;

		}

		reverselistDR1(left, right.next, floor + 1);

		if (floor > this.size / 2) {
			int temp = right.data;
			right.data = left.node.data;
			left.node.data = temp;

		}
		left.node = left.node.next;

	}

	private class HeapMover {
		Node node;
	}

	public void fold() {
		HeapMover left = new HeapMover();
		left.node = this.head;
		fold(left, this.head, 0);
		if (this.size % 2 == 1) {

			this.tail = left.node;

		} else {

			this.tail = left.node.next;

		}
		this.tail.next = null;
	}

	private void fold(HeapMover left, Node right, int floor) {
		if (right == null) {

			return;

		}

		fold(left, right.next, floor + 1);
		Node temp1 = null;
		// if()
		if (floor > this.size / 2) {
			temp1 = left.node.next;
			left.node.next = right;
			right.next = temp1;

			left.node = temp1;

		}

	}

	public int mid() {
		return this.midNode().data;
	}

	private Node midNode() {
		Node slow = this.head;
		Node fast = this.head;
		while (fast.next != null && fast.next.next != null) {
			slow = slow.next;
			fast = fast.next.next;
		}
		return slow;

	}

	public int kth(int k) {
		return this.kthNode(k).data;
	}

	private Node kthNode(int k) {
		Node slow = this.head;
		Node fast = this.head;
		for (int i = 0; i < k; i++) {
			slow = slow.next;
			fast = fast.next.next;

		}

		while (fast != null) {
			slow = slow.next;
			fast = fast.next;
		}
		return slow;

	}

	public void removeduplicate() {
		Node t1 = this.head;
		Node t2 = this.head;
		int count = 0;
		while (t2.next != null) {
			while (t2.data == t1.data && t1.next != null)

			{
				t1 = t1.next;
				if (t2.data == t1.data) {
					this.size--;
				}

			}
			if (t1.next == null) {
				t2.next = null;
			} else {
				t2.next = t1;
				t2 = t1;
			}

		}

	}

//	public void kreverse(int k) {
//		Node left = this.head;
//		Node right = this.head;
//		Node temp = this.head;
//		for (int i = 1; i <= this.size; i += k) {
//			left = right;
//			temp = left.next.next;
//			right = left.next;
//			for (int j = 1; j <=  k; j++) {
//				Node tc = curr;
//				Node tp = prev;
//
//				prev = curr;
//				curr = curr.next;
//				tc.next = tp;
//
//			}
//
//		}
//
//	}

	public LinkedList mergetwosortedLinkedList(LinkedList other) {
		Node ttemp = this.head;
		Node otemp = other.head;
		LinkedList rv = new LinkedList();
		while (ttemp != null && otemp != null) {
			if (ttemp.data < otemp.data) {
				rv.addLast(ttemp.data);
				ttemp = ttemp.next;
			} else {
				rv.addLast(otemp.data);
				otemp = otemp.next;
			}

		}
		while (ttemp != null) {
			rv.addLast(ttemp.data);
			ttemp = ttemp.next;
		}

		while (otemp != null) {
			rv.addLast(otemp.data);
			otemp = otemp.next;
		}
		return rv;

	}

	public void mergesort() {
		if (this.size == 1)
			return;
		LinkedList gh = new LinkedList();
		LinkedList lh = new LinkedList();

		Node mid = this.midNode();
		Node temp = mid.next;

		gh.head = this.head;
		gh.tail = mid;
		gh.tail.next = null;
		gh.size = (this.size + 1) / 2;

		lh.head = temp;
		lh.tail = this.tail;
		lh.tail.next = null;
		lh.size = this.size / 2;

		LinkedList merged = new LinkedList();
		gh.mergesort();
		lh.mergesort();

		merged = gh.mergetwosortedLinkedList(lh);

		this.head = merged.head;
		this.tail = merged.tail;
		this.size = merged.size;

	}
	public LinkedList KREVERSE(int k) throws Exception{
		LinkedList pre=new LinkedList();
		LinkedList cur;


		while(this.size()!=0){
			cur=new LinkedList();
			for(int i=0;i<k;i++){
				int rv=this.removeFirst();
				cur.addfirst(rv);
			}
			if(pre.isEmpty())
			pre=cur;
			else{
				pre.tail.next=cur.head;
				pre.tail=cur.tail;
				pre.size+=cur.size();
			}


		}
		return pre;
	}
	public void removeduplicat() throws Exception{

		LinkedList n=new LinkedList();

		while(this.size()!=0){
			int data=this.removeFirst();
			if(n.isEmpty()){

				n.addLast(data);
			}
			if(n.getLast()!=data){
				n.addLast(data);
			}

		}
		this.head=n.head;
		this.tail=n.tail;
		this.size=n.size;


	}

}
