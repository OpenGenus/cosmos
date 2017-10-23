package main

import (
    "fmt";
    "math/rand";
    "time"
)

func main() {
    rand.Seed(time.Now().UnixNano())
    const geneSet = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!."
    target := "Not all those who wander are lost."
    calc := func (candidate string) int {
        return getFitness(target, candidate)
    }

    start := time.Now()

    disp := func (candidate string) {
        fmt.Print(candidate)
        fmt.Print("\t")
        fmt.Print(calc(candidate))
        fmt.Print("\t")
        fmt.Println(time.Since(start))
    }

    var best = getBest(calc, disp, geneSet, len(target))
    println(best)

    fmt.Print("Total time: ")
    fmt.Println(time.Since(start))
}

func getBest(getFitness func(string) int, display func(string), geneSet string, length int) string {
    var bestParent = generateParent(geneSet, length)
    value := getFitness(bestParent)
    var bestFitness = value

    for bestFitness < length {
        child := mutateParent(bestParent, geneSet)
        fitness := getFitness(child)
        if fitness > bestFitness {
            display(child)
            bestFitness = fitness
            bestParent = child
        }
    }

    return bestParent
}

func mutateParent(parent, geneSet string) string {
    geneIndex := rand.Intn(len(geneSet))
    parentIndex := rand.Intn(len(parent))
    candidate := ""
    if parentIndex > 0 {
        candidate += parent[:parentIndex]
    }
    candidate += geneSet[geneIndex:1+geneIndex]
    if parentIndex+1 < len(parent) {
        candidate += parent[parentIndex+1:]
    }
    return candidate
}

func generateParent(geneSet string, length int) string {
    s := ""
    for i := 0; i < length; i++ {
        index := rand.Intn(len(geneSet))
        s += geneSet[index:1+index]
    }
    return s
}

func getFitness(target, candidate string) int {
    differenceCount := 0
    for i := 0; i < len(target); i++ {
        if target[i] != candidate[i] {
            differenceCount++
        }
    }
    return len(target) - differenceCount
}
