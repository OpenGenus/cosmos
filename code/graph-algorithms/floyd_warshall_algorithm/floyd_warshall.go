// Floyd–Warshall in Golang
package main
  
import (
    "fmt"
    "math"
)
  
type graph struct {
    to int
    wt float64
}
  
func floydWarshall(g [][]graph) [][]float64 {
    dist := make([][]float64, len(g))
    for i := range dist {
        di := make([]float64, len(g))
        for j := range di {
            di[j] = math.Inf(1)
        }
        di[i] = 0
        dist[i] = di
    }
    for u, graphs := range g {
        for _, v := range graphs {
            dist[u][v.to] = v.wt
        }
    }
    for k, dk := range dist {
        for _, di := range dist {
            for j, dij := range di {
                if d := di[k] + dk[j]; dij > d {
                    di[j] = d
                }
            }
        }
    }
    return dist
}
  
func main() {
    gra := [][]graph{        
        1: {{2, 3}, {3, 8},{5, -4}},
        2: {{4, 1}, {5, 7}},
        3: {{2, 4}},
        4: {{1, 2}, {3, -5}},
        5: {{4, 6}},
    }
         
    dist := floydWarshall(gra)
    //dist[][] will be the output matrix that will finally
    //have the shortest distances between every pair of vertices
    for _, d := range dist {
        fmt.Printf("%4g\n", d)
    }
}

// Source : http://www.golangprograms.com/golang-program-for-implementation-of-floyd-warshall-algorithm.html