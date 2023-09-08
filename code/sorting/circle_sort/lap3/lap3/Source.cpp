#include "Arrgueue.cpp"
#include <iostream>
using namespace std;
int main(){
	
	Arrgueue<int> x(5);
	x.enqueue(1);
	x.enqueue(2);

	x.dequeue();
	cout << x.Front();
	system("PAUSE");
	

}