package main

import (
  "fmt"
  "regexp"
  "strings"
)

var re, _ = regexp.Compile("[^a-z]")

func removeDups(s string) string {
  // Clean string
  s = strings.ToLower(s)
  s = re.ReplaceAllString(s, "")

  res := ""
  for i := 0; i < len(s) - 1; i++ {
    if s[i] != s[i + 1] {
      res += string(s[i])
    }
  }
  res += string(s[len(s) - 1])

  return res
}

func main() {
  // Test
  fmt.Println(removeDups("tteestt"))
}
