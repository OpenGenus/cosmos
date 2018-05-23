//Part of Cosmos Project by OpenGenus Foundation
//Implementation of the factional knapsack on golang
//written by Guilherme Lucas (guilhermeslucas)
package main

import (
    "fmt"
    "sort"
)

type Item struct {
    value float32
    weight float32
}

func fractional_knapsack(items []Item, maxWeight float32) float32 {
    var totalPrice float32
    sort.Sort(ByPrice(items))
    for i := 0; i < len(items); i++ {
        if maxWeight == 0 {
            break
        }
        if (items[i].weight <= maxWeight) {
            totalPrice = totalPrice + items[i].value
            maxWeight = maxWeight - items[i].weight
        } else {
            totalPrice = totalPrice + items[i].price()*maxWeight
            maxWeight = 0
        }
    }
    return totalPrice
}

func (i Item) price() float32 {
    return i.value/i.weight
}

type ByPrice []Item

func (c ByPrice) Len() int           { return len(c) }
func (c ByPrice) Swap(i, j int)      { c[i], c[j] = c[j], c[i] }
func (c ByPrice) Less(i, j int) bool { return c[i].price() > c[j].price() }

func main() {
    items := []Item{}

    i1 := Item{
        value: 32,
        weight: 2,
    }
    i2 := Item{
        value: 16,
        weight: 4,
    }
    i3 := Item{
        value: 8,
        weight: 8,
    }
    items = append(items,i1)
    items = append(items,i2)
    items = append(items,i3)
    fmt.Println("The maximum price is: ",fractional_knapsack(items, 10))
}
