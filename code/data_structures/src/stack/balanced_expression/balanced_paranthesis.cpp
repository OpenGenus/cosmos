#include <iostream>
#include <stack>
using namespace std;

bool checkBalanced(string s) {
	if (s.length() % 2 != 0) return false;
	stack <char> st;
	for (int i=0;i < s.length();i++) {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
			st.push(s[i]);
		}
		else {
			char temp = st.top();
			if (s[i] == '}' && temp == '{') st.pop();
			else if (s[i] == ']' && temp == '[') st.pop();
			else if (s[i] == ')' && temp == '(') st.pop();
			else return false;
		}
	}
	return st.empty();
}

int main()
{
	string s;
	cin >> s;
	bool res = checkBalanced(s);
	if (res) {
		cout << "Expression is balanced";
	}
	else {
		cout << "Expression is not balanced";
	}
	return 0;
}
