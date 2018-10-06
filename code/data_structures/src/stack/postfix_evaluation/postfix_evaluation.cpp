#include<bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/')
	return true;
	return false;
}
int calculate(int a,int b,char c)
{
	if(c=='+')
	return a+b;
	else if(c=='-')
	return a-b;
	else if(c=='*')
	return a*b;
	else
	return a/b;
}
int PFE_Value(string exp)
{
	stack<int>p;
	int l=exp.length();
	for(int i=0;i<l;i++)
	{
		if(isOperator(exp[i]))
		{
			if(!p.empty())
			{
				int a=p.top();
				p.pop();
				int b=p.top();
				p.pop();
				a=calculate(b,a,exp[i]);
				p.push(a);
			}
			else
			{
				cout<<"Invalid postfix expression!"<<endl;
				return INT_MIN;
			}
		}
		else 
		{
			p.push(exp[i]-'0');
		}
	}
	if(p.size()==1)
	return p.top();
	else
	{
		cout<<"Invalid postfix expression!"<<endl;
		return INT_MIN;
	}
}
int main(){
	string s;
	cout<<"Enter the postfix expression :"<<endl;
	cin>>s;
	cout<<"Value of expression :"<<endl;
	if(PFE_Value(s)!=INT_MIN)
    cout<<PFE_Value(s);
    
}
