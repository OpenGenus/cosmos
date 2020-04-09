#include <iostream>
#include<string>
using namespace std;
void toh(int n,char* src,char* spr,char* final)
{
    if(n==0)
    {
        return;
    }
    toh(n-1,src,final,spr); //first shift n-1 rings from initial block to spare one
    cout<<"Moved "<<n<<" From "<<src<<" -> "<<final<<endl;//left block to the desired final position
    toh(n-1,spr,src,final);//now shift n-1 rings to desired destination and final position
}

int main() {
	//solving tower of hanoi problem using recursion
	int n;
	cout<<"enter the total number of rings to be shifted"<<endl;
	cin>>n;
	char src[]="intial";
	char spr[]="spare";
	char final[]="final";
	toh(n,src,spr,final);
	return 0;
}
 
