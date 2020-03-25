// Converting prefix to its equivalent postfix notation.
// Part of Cosmos by OpenGenus Foundation

using System; 
using System.Collections.Generic; 

class PretoPost
{ 

// funtion to check if character 
// is operator or not 
static bool isOperator(char x) 
{ 
	switch (x) 
	{ 
		case '+': 
		case '-': 
		case '/': 
		case '*': 
		return true; 
	} 
	return false; 
} 

// Convert Prefix to Postfix expression 
static String PreToPost(String pre_exp) 
{ 

	Stack<String> s= new Stack<String>(); 

	
	int length = pre_exp.Length; 

	
	for (int i = length - 1; i >= 0; i--) 
	{ 

		// check if symbol is operator 
		if (isOperator(pre_exp[i])) 
		{ 

			// pop two operands from stack 
			String op1 = s.Peek(); s.Pop(); 
			String op2 = s.Peek(); s.Pop(); 

			
			String temp = op1 + op2 + pre_exp[i]; 

			// Push String temp back to stack 
			s.Push(temp); 
		} 

		// if symbol is an operand 
		else
		{ 
			// push the operand to the stack 
			s.Push( pre_exp[i]+""); 
		} 
	} 

	// stack contains only the Postfix expression 
	return s.Peek(); 
} 

 
public static void Main(String []args) 
{ 

string exp = Console.ReadLine();
	 
	Console.WriteLine("Postfix : " + PreToPost(exp)); 
} 
} 

 
