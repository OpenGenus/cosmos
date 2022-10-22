#include <iostream>
using namespace std;

class student{
    public:
    int x;
    int y;
    student(){
        
    }
     student(int x,int y){
         this->x=x;
          this->y=y;
     }
     student operator + (student s){
           student ans;
         ans.x = this->x- s.x;
         ans.y = this->y-  s.y;
         return ans;
     }
};
int main() {
	// your code goes here
	student stu1(4,5);
    student stu2(5,6);
    student stu3=stu1 + stu2;
     cout<<stu3.x<<" "<<stu3.y;
	return 0;
}
