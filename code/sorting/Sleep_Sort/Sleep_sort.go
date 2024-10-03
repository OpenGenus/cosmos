import Foundation
import (
	"fmt"
	"log"
	"os"
	"strconv"
	"time"
)
 
func main() {
	out := make(chan uint64)
	for _, a := range os.Args[1:] {
		i, err := strconv.ParseUint(a, 10, 64)
		if err != nil {
			log.Fatal(err)
		}
		go func(n uint64) {
			time.Sleep(time.Duration(n) * time.Millisecond)
			out <- n
		}(i)
	}
	for _ = range os.Args[1:] {
		fmt.Println(<-out)
	}
}
