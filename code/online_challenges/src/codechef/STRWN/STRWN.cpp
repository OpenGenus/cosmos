#include <iostream>

using namespace std;

int main() 
{
	long long int d,v,w;
	cin>>d>>v>>w;
	if(v==0 && d==0 && w==0) 
	{
	    cout<<0<<"\n";
	    return 0;
	}
	else if(v==0 && d==0) 
        {
            cout<<w<<"\n";
	    return 0;
        }
	else if(v==0 && w==0) 
        {
            cout<<d<<"\n"; 
	    return 0;
        }
	else if(w==0 && d==0) 
        { 
            cout<<v<<"\n";
	    return 0;
        }
	else if(v==0)
        {  
            cout<<w<<"\n";
	    return 0;
        }
	else if(d==0)
        {
            cout<<v<<"\n";
	    return 0;
        }
	else if(w==0)
        {
            cout<<d<<"\n";
	    return 0;
        }
	cout<<1<<"\n";
	return 0;
}
