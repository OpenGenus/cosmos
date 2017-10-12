#include <iostream>
using namespace std;
int main() {
	int size;
	cin >> size;
	int A[size];
	for(int i = 0; i < size; i++) {
		cin >> A[i];	
	}
	int x;
	cin >> x;
	int flag = 0;
	for(int i = 0; i < size; i++) {
		if(A[i] == x) {
			cout << i << endl;
			flag == 1;	
			break;
		}
	}
	return 0;
}
