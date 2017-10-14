#include <bits/stdc++.h>
using namespace std;
#define int long long int
void pushatbottom(stack<int>& s, int t)
{
    if (s.empty() == true) {
        s.push(t);
        return;
    }
    int p = s.top();
    s.pop();
    pushatbottom(s, t);
    s.push(p);
}
void reversei(stack<int>& s)
{
    if (s.empty() == true)
        return;
    int t = s.top();
    s.pop();
    reversei(s);
    pushatbottom(s, t);
}
main()
{
    cout << "Enter the number of elements in the stacks and push in accordance "
            "with that\n";
    int x;
    cin >> x;
    stack<int> s;
    int i;
    for (i = 0; i < x; i++) {
        int p;
        cin >> p;
        s.push(p);
    }
    reversei(s);
    cout << "Reversed stack is: \n";
    while (s.empty() == false) {
        cout << s.top() << "\n";
        s.pop();
    }
}
