#include <deque>
#include <iostream>

using namespace std;

//this is so the minqueue can be used with different types
//check out the templeting documentation for more info about this

//This version of minqueue is built upon the deque data structure
template <typename T>
class MinQueue {

 public:

    MinQueue() {}
    
    bool is_empty() const{
        //utilizes the size parameter that deque provides
        if (q.size() > 0){
            return true;
        }
        return false;
    }

    int size() const{
        return q.size();
    }

    T pop(){
        //pop should only be called when there is an item in the 
        //minQueue or else a deque exception will be raised
        T temp = q.front();
        q.pop_front();
        return temp;
    }

    const T & top(){
        return q.front();
    }

    void push(const T &item){
        q.push_back(item);
        //this forloop is to determine where in the minQueue the 
        //new element should be placed
        for (int i = q.size()-1; i > 0; --i){
            if (q[i-1] > q[i]){
                swap(q[i-1], q[i]);
            }
            else{
                break;
            }
        }
    }

private:
  deque<T> q;
};

int main(){
    MinQueue<int> minQ;
    //Here is a testing of the algorithim
    cout << minQ.size() << endl;
    minQ.push(2);
    cout << minQ.size() << endl;
    cout << minQ.top() << endl;
    minQ.push(1);
    cout << minQ.top() << endl;
    minQ.pop();
    cout << minQ.top() << endl;
    minQ.pop();
    cout << minQ.size() << endl;
    minQ.push(10);
    cout << minQ.top() << endl;
    minQ.push(8);
    cout << minQ.top() << endl;
    minQ.push(7);
    cout << minQ.top() << endl;
    minQ.push(6);
    cout << minQ.top() << endl;
    minQ.push(1);
    cout << minQ.top() << endl;


    return 0;
}
