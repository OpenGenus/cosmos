#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
class Stack{
int top;
int size;
int*array;
public:
Stack(int size){
    top=-1;
this->size=size;
array=new int[size];
}
void push(int element){
    if(size-top>1)
    {
        top++;
        array[top]=element;
    }
    else
    {
        cout<<"Stack Over flow!!"<<endl;
        return ;
    }
}
void pop(){
    if(top>=0){
     top--;
    }
    else{
        cout<<"Stack Under flow!!"<<endl;
        return;
    }
}
int peek(){
    if(top>=0){
        return array[top];
    }
    else
    return -1;
}

};


int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
Stack s1(5);
s1.push(3);
s1.push(4);
s1.pop();
cout<<s1.peek()<<endl;
return 0;
}
