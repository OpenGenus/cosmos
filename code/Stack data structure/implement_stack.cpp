// implement using array 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
class Stack{
public:
// properties of stack 
// 1) top variable and 2) array,3)size of array
int top;
int size;
int *array;

Stack(int size){
    this->size=size;
    top=-1;
    array=new int[size];
}

void push(int element){
// first check if the space is available
if(size-top>1){
    top++;
array[top]=element;
}
else
cout<<"Stack Overflow"<<endl;
return ;
}


void pop(){
if(top>=0){
    top--;
}
else
cout<<"Stack underflow";
}


int peek(){
if(top>=0 && top<size)
return array[top];
else{
    cout<<"Stack is empty"<<endl; 
return -1;
}
}
bool is_empty(){
if(top!=-1)return false;
else
return true;
}
};


int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
Stack s1(5);
s1.push(3);
cout<<s1.peek();
// s1.push(34);
// s1.push(43);
// s1.pop();

// cout<<s1.peek()<<endl;
// if(s1.is_empty()){
//     cout<<"Stack is empty"<<endl;
// }
// else
// cout<<"Stack is not empty"<<endl;


return 0;
}
