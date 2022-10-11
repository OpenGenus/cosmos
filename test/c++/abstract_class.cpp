#include <iostream>
using namespace std;

class student{
    public:
    virtual void show()=0;
    //      cout<<"I am parent"<<endl;
    // }
};
class child:public student{
  public:
//   void show(){
//       cout<<"I am child"<<endl;
//   }
};

// class child1:public child{
//     public:
//     void show(){
//         cout<<"This is child 2";
//     }
// };
int main() {
	// your code goes here
//     child *p;
//     child1 c;
//     p= &c;
//     // child1
//     //  // to implement early binding we dont use virtual keyword in parent class , so output will be "I am parent"
//     // // to implement late binding use virtual keyword in parent class, so output is "I am child"
//     p->show();
// 	return 0;
    child c;
    c.show();
    return 0;
}
