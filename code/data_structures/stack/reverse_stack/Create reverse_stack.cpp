#include<iostream>
#include<stack>
using namespace std;
 
stack<int> s;
 
void BottomInsert(int x){
    if(s.size()==0) s.push(x);
    else{
        int a = s.top();
        s.pop();
        BottomInsert(x);
        s.push(a);
    }
}
void reverse(){
    if(s.size()>0){
        int x = s.top();
        s.pop();
        cout<<x<<" ";
        reverse();
        BottomInsert(x);
    }
}

int main()
{
    cout<<"Enter the no. of elements to be inserted"<<endl;
    int n,a;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>a;
        s.push(a);
    }
    cout<<"Reversed Stack"<<endl;
    reverse();
    cout<<endl;
    return 0;
}
