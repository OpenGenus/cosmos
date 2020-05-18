#include<iostream>
using namespace std;

void naivePatternSearch(string mainString, string pattern, int array[], int *index) {
   int patLen = pattern.size();
   int strLen = mainString.size();

   for(int i = 0; i<=(strLen - patLen); i++) {
      int j;
      for(j = 0; j<patLen; j++) {      //check for each character of pattern if it is matched
         if(mainString[i+j] != pattern[j])
            break;
      }

      if(j == patLen) {     //the pattern is found
         (*index)++;
         array[(*index)] = i;
      }
   }
}

int main() {
   string mainString = "ABAAABCDBBABCDDEBCABC";
   string pattern = "ABC";
   int locArray[mainString.size()];
   int index = -1;
   naivePatternSearch(mainString, pattern, locArray, &index);

   for(int i = 0; i <= index; i++) {
      cout << "Pattern found at position: " << locArray[i]<<endl;
   }
}

/*
Output

Pattern found at position: 4
Pattern found at position: 10
Pattern found at position: 18

*/
