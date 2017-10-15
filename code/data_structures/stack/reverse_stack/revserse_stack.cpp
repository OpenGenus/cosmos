// liberaries and headers
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
	// declaring stacks
	stack<int> stack,revstack;

	// pushing values in the stack
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);


	// displaying elements in stack and pushing in revstack for reverse stack
	cout<<"ORIGINAL STACK\n";
	while(!stack.empty())
	{
		int w = stack.top();
		revstack.push(w);
		cout<<w<<" ";
		stack.pop();
	}

	cout<<endl;

	// displaying reversed stack
	cout<<"REVERSE STACK\n";
	while(!revstack.empty())
	{
		int w = revstack.top();
		cout<<w<<" ";
		revstack.pop();
	}


	return 0;
}
