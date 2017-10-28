/* Part of Cosmos by OpenGenus Foundation */
package main

import "fmt"

type PolyNode struct {
	Coeff int
	Pow   int
}

type Polynomail struct {
	Data []PolyNode
}

func (p *Polynomail) AddNode(coeff, pow int) {
	//Find a sutible location.
	index := -1
	for i, data := range p.Data {
		if pow > data.Pow {
			index = i
			break
		}
	}

	if index == -1 {
		p.Data = append(p.Data, PolyNode{Coeff: coeff, Pow: pow})
	} else {
		res := append([]PolyNode{}, p.Data[index:]...)
		p.Data = append(p.Data[:index], PolyNode{Coeff: coeff, Pow: pow})
		p.Data = append(p.Data, res...)
	}

}

func (p *Polynomail) Show() {
	for i, data := range p.Data {
		if i != 0 {
			fmt.Printf(" + ")
		}
		fmt.Printf("%d^%d", data.Coeff, data.Pow)
	}
	fmt.Printf("\n")
}

func main() {
	p1 := Polynomail{}
	p2 := Polynomail{}

	p1.AddNode(2, 5)
	p1.AddNode(12, 4)
	p1.AddNode(3, 1)
	p1.AddNode(8, 2)
	fmt.Printf("Polynomail one is ")
	p1.Show()

	p2.AddNode(1, 7)
	p2.AddNode(3, 4)
	p2.AddNode(4, 2)
	p2.AddNode(8, 0)
	fmt.Printf("Polynomail two is ")
	p2.Show()

}
