// CPP code to illustrate Queue operations in STL
// Divyansh Mishra --> divyanshmishra101010
#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void print_queue(queue<int> q)
{
	queue<int> temp = q;
	while (!temp.empty()) {
		cout << temp.front()<<" ";
		temp.pop();
	}
	cout << '\n';
}

// Driver Code
int main()
{
	queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);

	cout << "The first queue is : ";
	print_queue(q1);
	
	queue<int> q2;
	q2.push(4);
	q2.push(5);
	q2.push(6);

	cout << "The second queue is : ";
	print_queue(q2);
	
	
	q1.swap(q2);
		
	cout << "After swapping, the first queue is : ";
	print_queue(q1);
	cout << "After swapping the second queue is : ";
	print_queue(q2);
	
	cout<<q1.empty(); //returns false since q1 is not empty

	return 0;
}
