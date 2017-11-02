#include<iostream>
 
#define SIZE 10
 
using namespace std;
 
void bucketSort(int a[], int n) {
    int i, j, k, buckets[SIZE];
    
    for(i = 0; i < SIZE; ++i)
        buckets[i] = 0;
    
    for(i = 0; i < n; ++i)
        ++buckets[a[i]];
        
    for(i = 0, j = 0; j < SIZE; ++j)
        for(k = buckets[j]; k > 0; --k)
            a[i++] = j;
}
 
int main() {
    int i, a[] = {3, 6, 5, 1, 8, 4, 3, 1}, n = 8;
    
    cout << "Before sorting:\n";
    for(i = 0; i < n; ++i)
        cout << a[i] << " ";
    
    bucketSort(a, n);
    
    cout<< "\n\nAfter sorting:\n";
    for(i = 0; i < n; ++i)
        cout<< a[i] << " ";
    
    return 0;
}
