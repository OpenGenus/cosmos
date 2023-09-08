#include<bits/stdc++.h>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
string alphabets = "abcdefghijklmnopqrstuvwxyz";
 
void panLipogramChecker(string s)
{   
   
    for(int i=0; i<s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    int counter = 0 ;
    for(int i=0 ; i<26 ; i++)
    {   
        int pos = s.find(alphabets[i]);
   
        if(pos<0 || pos>s.length())
            counter += 1;
    }
   
    if(counter == 0)
        cout<<"Pangram"<<endl;
    else if(counter >= 2)
        cout<<"Not a pangram but might a lipogram"<<endl;
    else
        cout<<"Pangrammatic Lipogram"<<endl;
}
 

int main()
{
    string str = "The quick brown fox jumped over the lazy dog";
    panLipogramChecker(str);
     
    str = "The quick brown fox jumps over the lazy dog";
    panLipogramChecker(str);
     
    str = "The quick brown fox jum over the lazy dog";
    panLipogramChecker(str);
}
 
