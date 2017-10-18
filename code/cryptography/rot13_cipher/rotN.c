#include <stdio.h>
#include <string.h>
#include <ctype.h>


// Run rotation cipher on a string
// The string will be modified
void rotN(char * string, int n) {
  char *p;
  char sub;

  // Loop through input text
  for(p = string ; *p != 0 ; p++) {
    // Check if character is a letter
    if (isalpha(*p)) {
      // Subtract 'A' if uppercase, 'a' if lowercase
      sub = (*p >= 65 && *p <= 90) ? 'A' : 'a';
      // Convert character to alphabet index starting from zero (0 - 25)
      *p -= sub;
      // Shift
      *p += n;
      // Wrap around
      *p %= 26;
      // Convert back into ASCII
      *p += sub;
    }
  }
}

int main() {
  // Example
  char str[] = "Hello, world!";
  rotN(str, 13);
  puts(str); // Outputs "Uryyb, jbeyq!"

  return 0;
}

