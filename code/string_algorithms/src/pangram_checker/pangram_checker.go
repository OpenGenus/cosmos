package main
 
import "fmt"
 
func main() {
    for _, s := range []string{
        "The quick brown fox jumps over the lazy dog.",
        `Watch "Jeopardy!", Alex Trebek's fun TV quiz game.`,
        "Not a pangram.",
    } {
        if pangram(s) {
            fmt.Println("Yes:", s)
        } else {
            fmt.Println("No: ", s)
        }
    }
}
 
func pangram(s string) bool {
	var missing uint32 = (1 << 26) - 1
	for _, c := range s {
		var index uint32
		if 'a' <= c && c <= 'z' {
			index = uint32(c - 'a')
		} else if 'A' <= c && c <= 'Z' {
			index = uint32(c - 'A')
		} else {
			continue
		}
 
		missing &^= 1 << index
		if missing == 0 {
			return true
		}
	}
	return false
}
