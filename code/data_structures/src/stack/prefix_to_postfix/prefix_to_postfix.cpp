#include <iostream> 
#include <stack> 
#include <string>
using namespace std; 

// funtion to check if character is operator or not 
bool isOperator(char ch) { 
switch (ch) { 
case '+': 
case '-': 
case '/': 
case '*': 
	return true; 
} 
return false; 
} 

// Convert prefix to Postfix expression 
string PreToPost(string pre_exp) { 

stack<string> s; 

int length = pre_exp.size(); 

 
for (int i = length - 1; i >= 0; i--) { 

	// check if symbol is operator 
	if (isOperator(pre_exp[i])) { 

	// pop two operands from stack 
	string op1 = s.top(); 
	        s.pop(); 
	string op2 = s.top(); 
	        s.pop(); 

	 
	string temp = op1 + op2 + pre_exp[i]; 

	// Push string temp back to stack 
	s.push(temp); 
	} 

	// if symbol is an operand 
	else { 

	// push the operand to the stack 
	s.push(string(1, pre_exp[i])); 
	} 
} 


return s.top(); 
} 

int main() { 
string pre_exp;
cin>>pre_exp;
cout << "Postfix : " << PreToPost(pre_exp); 
return 0; 
} 
