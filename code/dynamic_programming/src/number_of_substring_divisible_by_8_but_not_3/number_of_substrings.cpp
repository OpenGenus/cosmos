#include <bits/stdc++.h> 
using namespace std; 

int no_of_substr(string str, int len, int k) 
{ 
    int count = 0; 
    // iterate over the string 
    for (int i = 0; i < len; i++) { 
        int n = 0; 
        // consider every substring starting from index 'i'
        for (int j = i; j < len; j++) { 
            n = n * 10 + (str[j] - '0'); 
            // if substring is divisible by k, increase the counter
            if (n % k == 0) 
                count++; 
        } 
    } 
    return count; 
} 
  
int main() 
{ 
    string str;
    int len;
    cout << "Enter the string: ";
    cin >> str;
    len = str.length(); 
    cout << "Desired Count: " << no_of_substr(str, len, 8) - no_of_substr(str, len, 24); 
  
    return 0; 
} 
