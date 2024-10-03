package main

import "fmt"
import "regexp"

func scorePassword(pass string) int {
	score := 0
	if len(pass) == 0 {
		return score
	}

	characterMap := make(map[string]int)
	for _, char := range pass {
		characterMap[string(char)]++
		score += 5 / characterMap[string(char)]
	}

	variation := 0
	if regexp.MustCompile(`\d`).MatchString(pass) {
		variation++
	}
	if regexp.MustCompile(`[a-z]`).MatchString(pass) {
		variation++
	}
	if regexp.MustCompile(`[A-Z]`).MatchString(pass) {
		variation++
	}
	if regexp.MustCompile(`\W`).MatchString(pass) {
		variation++
	}
	score += (variation - 1) * 10

	return score
}

func checkPassStrength(pass string) string {
	score := scorePassword(pass)
	if score > 80 {
		return "Strong"
	}
	if score > 60 {
		return "Good"
	}
	return "Weak"
}

func main() {
	passwords := []string{"123", "aaaaabcdefg124", "Lg5z.st7h1Hsg"}
	for _, password := range passwords {
		fmt.Printf("%s: %s\n", password, checkPassStrength(password))
	}
}
