/// Part of Cosmos by OpenGenus Foundation
/// Find of average of numbers in an array
/// Contributed by: Guilherme Lucas (guilhermeslucas)

package main
import "fmt"

func average(array []float32) float32 {
    var sum float32;
    sum = 0.0
    for i := 0; i < len(array); i++ {
        sum = sum + array[i]
    }
    return sum / float32(len(array))
}

func main() {
    var n int
    var input float32
    array := make([]float32, n)

    fmt.Println("How many elements do you want to input?")
    fmt.Scanf("%d", &n)

    for i := 0; i < n; i++ {
        fmt.Scanf("%f", &input)
        array = append(array, input)
    }

    fmt.Println("The median is: ", average(array))
}
