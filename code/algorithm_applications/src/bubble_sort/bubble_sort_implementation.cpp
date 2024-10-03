#include<iostream>

using namespace std;

int main() {    
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bubble sort algorithm code 
    int counter = 1;
    while(counter < n) {
        for(int i = 0; i < n-counter; i++){
            if(arr[i] > arr[i+1]) {
                // if arr[i] > arr[i+1] then we swap those two element
                // because they are not in sorting form
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        counter++;
    }

    cout << '\n';

    return 0;
}
