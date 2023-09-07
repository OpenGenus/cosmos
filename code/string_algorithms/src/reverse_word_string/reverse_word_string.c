/* Program to reverse words in a string in C */
#include <stdio.h>
#include <string.h>

// this function will reverse the string, when given starting and ending pointers to the string
void reverse(char *start, char *end)
{
  char temp;
  while (start < end)
  {
    temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

// Function to reverse words
void reverseWords(char *s)
{
    char *word_begin = NULL;
    char *temp = s; /* temp is for word boundry */

 	   // Reversing each word
    // Traversing the string
    for(int i=0;i<strlen(s);i++ )
    {
        // string should have a proper start ie,word_begin, which is not space ie,temp[i] != ' '
        if (( word_begin == NULL ) && (temp[i] != ' ') )
        {
            word_begin=(temp+i);
        }
        // Each word, reverse the word
        // In below if condition words are considerd by seeing space
        if(word_begin && (temp[i+1] == ' ') || (temp[i+1] == '\0'))
        {
            reverse(word_begin, (temp+i));
            word_begin = NULL;
        }

    }

    // Reversing the entire string
    reverse(s, (temp+strlen(s)-1));
}



// Main function
int main()
{
  char s[] = " I love programming";
  reverseWords(s);
  printf("String with words in reverse order : %s\n",s);
  return 0;
}
