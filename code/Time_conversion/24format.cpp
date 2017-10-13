#include <iostream>

using namespace std;

int main()
{
    string str[10];
    cout<<"\nenter time...example:'08:34:42PM'...";
    for(int i=0;i<10;i++)
        cin>>str[i];
    if(str[8]=='A')
    {
        if((str[0]==1)&&(str[1]==12))
            {
                str[0]=0;
                str[1]=0;
                for(int i=0;i<10;i++)
                    cout<<str[i];
            }
    }
    
    else
    {
        if((str[0]==1)&&(str[1]==12))
        for(int i=0;i<10;i++)
                cout<<str[i];
        else
        {
            str[0]+=1;
            str[1]+=2;
            for(int i=0;i<10;i++)
                cout<<str[i];
        }
    }
    return 0;
}
