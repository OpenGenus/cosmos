#include <iostream>
#define MAX_SIZE 100
using namespace std;

void printHelper(int pos, int n, int open, int close){
    static char str[MAX_SIZE];

    if(close == n){
        cout << str << endl;
        return;
    }
    else{
        if(open > close){
            str[pos] = '}';
            printHelper(pos+1, n, open, close+1);
        }

        if(open < n){
            str[pos] = '{';
            printHelper(pos+1, n, open+1, close);
        }
    }
}

void printParentheses(int n){
    if(n>0)
        printHelper(0, n, 0, 0);
    return;
}

int main() {
    int n = 3;
    printParentheses(n);
    return 0;
}
