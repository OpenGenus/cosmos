#include<iostream>
using namespace std;

int main()
{
    float op1;
    float op2;
    float ans;
    char choice='y';
    char ch;

    cin>>op1;
    cin>>op2;

    do{
        cout<<"\nEnter your choice:\n'+' for Addition\n'*' for Multiplication\n'/' for Divison\n'%' for Modulus\n'-' for Subtraction\n";
        cin>>ch;
        switch(ch)
        {
            //Addition
            case '+' : ans = op1 + op2 ;
                       cout << "Addition" << " : " << ans << endl;
                       break;
            //Multiplication
            case '*' :  ans = op1 * op2 ;
                        cout << "Multiplication" << " : " << ans << endl;
                        break;
            //Divison
            case '/' :  ans = op1 / op2;
                        cout << "Divison" << " : " << ans << endl;
                        break;
            //Modulus
            case '%' :  cout << "Modulus" << " : " << int(op1) % int(op2) << endl;
                        break;
            //Subtraction
            case '-' :  ans = op1 - op2;
                        cout << "Subtraction" << " : " << ans << endl;
                        break;

            //In case of wrong choice
            default  :  cout<<"Invalid symbol!";
                        break;
        }
        cout<<"\nDo you want to continue(y/n)";
        cin>>choice;

    }while(choice=='y' || choice=='Y');

return 0;
}
