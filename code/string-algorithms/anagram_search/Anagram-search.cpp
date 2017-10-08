// Part of Cosmos by OpenGenus Foundation


#include <iostream>
#include<string>

using namespace std;

void checkAnagram(char word1[], char word2[]){
    char alpha1[26], alpha2[26];
    int pos;
    //Checking the length of the two words
    if (strlen(word1)!=strlen(word2))
            {
                cout<<"\n Not anagrams";
                return;
            }
    //Putting the letters of the words into an array of alphabets so that frequency of letters in both the words can be matched.
            for (int i=0;i<strlen(word1);i++){
                pos=tolower(word1[i])-97;
                alpha1[pos]++;
            }
            for (int i=0;i<strlen(word2);i++){
                pos=tolower(word2[i])-97;
                alpha2[pos]++;
            }
            int check=1;
            for (int i=0;i<26;i++){
                if (alpha1[i]!=alpha2[i]){
                    check=0;
                }
            }
            if (check)
                cout<<"\n Anagrams";
            else cout<<"\n Not anagrams";

    
}

int main(){
    //Example
    char str1[50]="listen";
    char str2[50]="silent";
    checkAnagram(str1, str2);
    return 0;
}
