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

func (p *Polynomail) Length() int {
	return len(p.Data)
}

func (p *Polynomail) GetNode(index int) PolyNode {
	return p.Data[index]
}

func AddPolynomail(p1, p2 Polynomail) Polynomail {
	ans := Polynomail{}
	i, j := 0, 0
	for i, j = 0, 0; i < p1.Length() && j < p2.Length(); {
		p1N := p1.GetNode(i)
		p2N := p2.GetNode(j)

		coeff := 0
		pow := 0
		if p1N.Pow == p2N.Pow {
			pow = p1N.Pow
			coeff = p1N.Coeff + p2N.Coeff
			i++
			j++
		} else if p1N.Pow > p2N.Pow {
			pow = p1N.Pow
			coeff = p1N.Coeff
			i++
		} else {
			pow = p2N.Pow
			coeff = p2N.Coeff
			j++
		}
		ans.AddNode(coeff, pow)
	}

	for ; i < p1.Length(); i++ {
		pN := p1.GetNode(i)
		ans.AddNode(pN.Coeff, pN.Pow)
	}

	for ; j < p2.Length(); j++ {
		pN := p2.GetNode(j)
		ans.AddNode(pN.Coeff, pN.Pow)
	}

	return ans
}

func main() {
	p1 := Polynomail{}
	p2 := Polynomail{}

	p1.AddNode(2, 11)
	p1.AddNode(2, 5)
	p1.AddNode(12, 4)
	p1.AddNode(3, 1)
	p1.AddNode(8, 2)
	fmt.Printf("Polynomail one is ")
	p1.Show()

	p2.AddNode(1, 7)
	p2.AddNode(-4, 6)
	p2.AddNode(3, 4)
	p2.AddNode(4, 2)
	p2.AddNode(8, 0)
	fmt.Printf("Polynomail two is ")
	p2.Show()

	ans := AddPolynomail(p1, p2)
	fmt.Printf("The sum of above two Polynomail is ")
	ans.Show()
}
