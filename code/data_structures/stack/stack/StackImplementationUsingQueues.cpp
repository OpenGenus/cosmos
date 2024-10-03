#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
class STACK{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int data){
        if(q1.empty()){
            q2.push(data);
        }else{
            q1.push(data);
        }
        return;
    }
    int pop(){
        int i,size,data;
        if(q1.empty()){
            size=q2.size();
            i=0;
            while(i<size-1){
                q1.push(q2.front());
                q2.pop();
                i=i+1;
            }
            data=q2.front();
            q2.pop();
            return data;
        }else{
            size=q1.size();
            i=0;
            while(i<size-1){
                q2.push(q1.front());
                q1.pop();
                i=i+1;
            }
            data=q1.front();
            q1.pop();
            return data;
        }
    }
    void printSTACK(){
        if(q1.empty()){
            while(!q2.empty()){
                cout<<q2.front()<<" ";
                q1.push(q2.front());
                q2.pop();
            }
        }else{
            while(!q1.empty()){
                cout<<q1.front()<<" ";
                q2.push(q1.front());
                q1.pop();
            }
        }
        return;
    }
};
int main(){
    STACK stack;
    stack.push(3);
    stack.push(2);
    stack.printSTACK();
    int data=stack.pop();
    cout<<endl<<data<<endl;
    return 0;
}
