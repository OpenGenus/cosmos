package main

import (
	"fmt"
	"strings"
)

func Encrypt(str string, key int) string {
	if err := checkKey(key); err != nil {
		fmt.Println("Error: ", err.Error())
		return ""
	}
	shift := rune(key)
	dec := strings.Map(func(r rune) rune {
		if r >= 'a' && r <= 'z'-shift || r >= 'A' && r <= 'Z'-shift {
			return r + shift
		} else if r > 'z'-shift && r <= 'z' || r > 'Z'-shift && r <= 'Z' {
			return r + shift - 26
		}
		return r
	}, str)
	return dec
}

func Decrypt(str string, key int) string {
	if err := checkKey(key); err != nil {
		fmt.Println("Error: ", err.Error())
		return ""
	}
	shift := rune(key)
	dec := strings.Map(func(r rune) rune {
		if r >= 'a'+shift && r <= 'z' || r >= 'A'+shift && r <= 'Z' {
			return r - shift
		} else if r >= 'a' && r < 'a'+shift || r >= 'A' && r < 'A'+shift {
			return r - shift + 26
		}
		return r
	}, str)
	return dec
}

func checkKey(k int) error {
	if k <= 26 {
		return nil
	}
	return fmt.Errorf("Invalid key\n 0 <= Key <= 26")
}

func main() {
	var msg string
	var key int
	var mode rune
	fmt.Println("Enter text to encrypt\\decrypt")
	fmt.Scanf("%s\n", &msg)
	fmt.Println("Enter key")
	fmt.Scanf("%d\n", &key)
	fmt.Println("Enter 'e' to encrypt or 'd' to decrypt")
	fmt.Scanf("%c", &mode)
	if mode == rune('e') {
		fmt.Println("Encrypted Message: ", Encrypt(msg, key))
	} else if mode == rune('d') {
		fmt.Println("Deccrypted Message: ", Decrypt(msg, key))
	} else {
		fmt.Println("Unknown mode")
	}
}
