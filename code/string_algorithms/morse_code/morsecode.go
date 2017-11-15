// Part of Cosmos by OpenGenus Foundation

package main

import (
	"fmt"
	"strings"
)

var (
	morseAlphabet = map[rune]string{
		'A': ".-", 'B': "-...", 'C': "-.-.", 'D': "-..", 'E': ".", 'F': "..-.",
		'G': "--.", 'H': "....", 'I': "..", 'J': ".---", 'K': "-.-", 'L': ".-..",
		'M': "--", 'N': "-.", 'O': "---", 'P': ".--.", 'Q': "--.-", 'R': ".-.",
		'S': "...", 'T': "-", 'U': "..-", 'V': "...-", 'W': ".--", 'X': "-..-",
		'Y': "-.--", 'Z': "--..", '1': ".----", '2': "..---", '3': "...--",
		'4': "....-", '5': ".....", '6': "-....", '7': "--...", '8': "---..",
		'9': "----.", '0': "-----",
	}

	inverseAlphabet = make(map[string]rune, len(morseAlphabet))
)

func init() {
	for c, m := range morseAlphabet {
		inverseAlphabet[m] = c
	}
}

// Encode returns the morse coded representation of the message.
func Encode(text string) string {
	result := make([]string, 0, len(text))
	text = strings.ToUpper(text)
	for _, c := range text {
		if m, ok := morseAlphabet[c]; ok {
			result = append(result, m)
		}
	}
	return strings.Join(result, " ")
}

// Decode returns the text content of a morse coded message.
func Decode(text string) string {
	result := make([]rune, 0, len(text)/3)
	parts := strings.Split(text, " ")
	for _, m := range parts {
		if c, ok := inverseAlphabet[m]; ok {
			result = append(result, c)
		}
	}
	return string(result)
}

func main() {
	if Decode(Encode("TEST")) != "TEST" {
		panic("encode/decode failed")
	}

	fmt.Println(Decode(Encode("HELLO")), Decode(".-- --- .-. .-.. -.."))
}
