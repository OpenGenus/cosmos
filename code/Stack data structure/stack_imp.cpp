/* implement using arrays*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
class Stack{

int size;
int *array;
int top;
public:
Stack(int size){
    top=-1;
    this->size=size;
    array=new int[size];
}
void push(int element){
if(size-top>1){
    top++;   
array[top]=element;

}
else
cout<<"Stack Overflow!!"<<endl;
return;
}
void pop(){
if(top>=0){
top--;
}
else{
    cout<<"Stack Under Flow"<<endl;
}
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
if(top==-1)return true;
else
return false;
}
int get_size(){
return top;
}

};



int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
Stack s1(5);
s1.push(3);
cout<<s1.peek()<<" ";
return 0;
}
