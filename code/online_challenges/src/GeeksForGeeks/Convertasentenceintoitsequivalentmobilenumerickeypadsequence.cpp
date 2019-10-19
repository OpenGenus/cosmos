/Algorithm :
//1.Create a string for respective letter on keypad (str).
//2.To the respective function send differnece ASCII value of respective letter and 65.
//3.Now return the string value with respective index.
//4.Print the numbers and if " " is present print 0.


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

 string ret(int i)
 {
     string str[]=
     {
        "2","22","222","3","33","333","4","44","444","5","55","555","6","66","666",
     
         "7","77","777","7777","8","88","888","9","99","999","9999"
     };
     
     
     return str[i];
 }


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        
        string s;
        getline(cin,s);
        int i=0;
        while(s[i]!='\0')
        {
            if(s[i]==' ')
            cout<<0;
            else
            cout<<ret((int)s[i]-65);
            
            i++;
        }
        cout<<endl;
        
    }
    return 0;
}
