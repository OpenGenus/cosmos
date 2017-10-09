package splaytree

type binaryNode struct {
	left, right *binaryNode
	item        Item
}

type splayTree struct {
	root   *binaryNode
	length int
}

func NewSplayTree() Tree {
	return &splayTree{}
}

func (st *splayTree) splay(item Item) {
	header := &binaryNode{}
	l, r := header, header
	var y *binaryNode
	t := st.root

	splaying := true
	for splaying {
		switch {
		case item.Less(t.item): // item might be on the left path
			if t.left == nil {
				splaying = false
				break
			}
			if item.Less(t.left.item) { // zig-zig -> rotate right
				y = t.left
				t.left = y.right
				y.right = t
				t = y
				if t.left == nil {
					splaying = false
					break
				}
			}
			r.left = t // link right
			r = t
			t = t.left
		case t.item.Less(item): // item might be on the right path
			if t.right == nil {
				splaying = false
				break
			}
			if t.right.item.Less(item) { // zig-zag -> rotage left
				y = t.right
				t.right = y.left
				y.left = t
				t = y
				if t.right == nil {
					splaying = false
					break
				}
			}
			l.right = t
			l = t
			t = t.right
		default: // found the item
			splaying = false
		}
	}
	l.right = t.left
	r.left = t.right
	t.left = header.right
	t.right = header.left
	st.root = t
}

func (st *splayTree) Get(key Item) Item {
	if st.root == nil {
		return nil
	}
	st.splay(key)
	if st.root.item.Less(key) || key.Less(st.root.item) {
		return nil
	}
	return st.root.item
}

func (st *splayTree) Has(key Item) bool {
	return st.Get(key) != nil
}

func (st *splayTree) ReplaceOrInsert(item Item) Item {
	panic("not implemented")
}

func (st *splayTree) insert(item Item) {
	n := &binaryNode{item: item}
	if st.root == nil {
		st.root = n
		return
	}
	st.splay(item)
	switch {
	case item.Less(st.root.item):
		n.left = st.root.left
		n.right = st.root
		st.root.left = nil
	case st.root.item.Less(item):
		n.right = st.root.right
		n.left = st.root
		st.root.right = nil
	default:
		return
	}
	st.root = n
	st.length++
}

func (st *splayTree) Delete(item Item) Item {
	if st.length == 0 {
		return nil
	}

	st.splay(item)
	if st.root.item.Less(item) || item.Less(st.root.item) {
		return nil
	}

	// delete the root
	if st.root.left == nil {
		st.root = st.root.right
	} else {
		x := st.root.right
		st.root = st.root.left
		st.splay(item)
		st.root.right = x
	}
	return item
}

func (st *splayTree) DeleteMin() Item {
	if st.root == nil {
		return nil
	}
	x := st.root
	for x != nil {
		x = x.left
	}
	st.splay(x.item)
	st.Delete(x.item)
	return x.item
}

func (st *splayTree) DeleteMax() Item {
	if st.root == nil {
		return nil
	}
	x := st.root
	for x != nil {
		x = x.right
	}
	st.splay(x.item)
	st.Delete(x.item)
	return x.item
}

func (st *splayTree) Len() int {
	return st.length
}

func (st *splayTree) AscendRange(greaterOrEqual, lessThan Item, iterator ItemIterator) {
	panic("not implemented")
}

func (st *splayTree) AscendLessThan(pivot Item, iterator ItemIterator) {
	panic("not implemented")
}

func (st *splayTree) AscendGreaterOrEqual(pivot Item, iterator ItemIterator) {
	panic("not implemented")
}
