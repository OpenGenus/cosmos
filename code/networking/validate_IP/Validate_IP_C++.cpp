// written by hg398


#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;

int main()
{
    int dot=0,count=0;                                                          
    char *str=new char[15];                                                     // str stores ip address
    gets(str);
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='.')
        dot++;
    }
    char str1[4];
    char *token=strtok(str,".");
    if(dot==3)
    {
        while(token!=NULL)
        {
            strcpy(str1,token);
            if(atoi(str1)>=0 && atoi(str1)<=255)
            count++;
            token=strtok(NULL,".");
        }
        if(count==4)
        cout<<"Valid IP Address";
        else
        cout<<"Invalid IP Address";
    }
    else
    cout<<"Invalid IP Address";
    return 0;
    
}
