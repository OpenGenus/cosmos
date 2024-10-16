/* C++ Program to find lexicographically largest palindrome subsequence 
In this Program only input line contains a non-empty string S consisting of lowercase English letters only. Its length does not exceed 10.
Here, Characters in the strings are compared according to their ASCII codes and the one with largest ASCII code is lexicographically largest. 
And output contain frequency and all the reoccurrence of that character in string S in a single line.
*/     

#include<iostream>
#include<string>
using namespace std;

int main() {
    string S, k, a, m;
    int i, j, c, max;
    //getting user input as string        
    cin >> S; 
    //initialising m with character "a"                                
    m = "a";                         
    max = 0;                     
    for(j = 0; j < S.size(); j++) {
        //initialising c with 0         
        c = 0;                             
        for(i = 0; i < S.size(); i++) {
            //assigning value of element with index 'i' to a           
            a = S[i];
            //this is for getting the lexicographically largest element (the one with largest ascii value)                  
            if(a >= m)                       
            	m = a;                     
        }
    }   
    for(i = 0; i < S.size(); i++) {
        a = S[i];                           
        if(a == m) {
            //increament c when we find our lexicographically largest character in string more than one time                  
            c++;
            //for finding maximum frequency of character                              
            if(c > max) 
                max = c;                    
        } 
    }
    cout << max << " ";
    for(i = 0; i < max; i++) {  
        //printing subsequence of lexicographically largest character as output                        
        cout << m; 
    }
    return 0;
}

/* SAMPLE
Testcase 1
INPUT   startling
OUTPUT  2 tt
Testcase 2
INPUT   mississippi
OUTPUT  4 ssss
Testcase 3
INPUT   sausage
OUTPUT  1 u   
Time Complexity is O(n^2)   where n is length of string
Space Complexity is O(1)   */

