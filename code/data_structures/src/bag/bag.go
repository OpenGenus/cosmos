// Golang implementation of the bag data structure

type Bag struct {
	Items []string
	Size int
}

// Bag constructor
func newBag() *Bag {
	return &Bag{
		Items: make([]string, 0),
		Size:  0,
	}
}

// Adds a new string to the bag
func (b *Bag) Add(s string) {
	b.Items = append(b.Items, s)
	// Increment the size
	b.Size++
}

// Checks if the bag is empty
func (b *Bag) IsEmpty() bool {
	return b.Size == 0
}

// Checks if the bag contains the given item
func (b *Bag) Contains(s string) bool {
	for _,e := range b.Items {
		if e == s {
			return true
		}
	}
	return false
}

// Removes all the items from the bag
func (b *Bag) RemoveAll() {
	b.Items = make([]string, 0)
	// Reset the size
	b.Size = 0
}
