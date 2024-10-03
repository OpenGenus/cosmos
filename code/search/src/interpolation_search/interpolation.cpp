
#include<bits/stdc++.h> 
using namespace std; 

int interSearch(vector<int>vec, int n, int x) 
{  
    int l = 0, h = (n - 1); 
  
    while (l <= h && x >= vec[l] && x <= vec[h]) 
    { 
        if (l == h) 
        { 
            if (vec[l] == x) return l; 
            return -1; 
        } 
        int pos = l + (((double)(h - l) / 
            (vec[h] - vec[l])) * (x - vec[l])); 
  
        if (vec[pos] == x) 
            return pos; 
  
        if (vec[pos] < x) 
            l = pos + 1; 
 
        else
            h = pos - 1; 
    } 
    return -1; 
} 

int main() 
{  
    vector<int>vec = {10, 12, 13, 16, 18, 19, 20, 21, 
                 22, 23, 24, 33, 35, 42, 47}; 
    int n = vec.size(); 
  
    int x = 12;
    int pos =interSearch(vec, n, x); 
  
    if (pos != -1) 
        cout << "Element is at " << pos; 
    else
        cout << "Element not found"; 
    return 0; 
} 
