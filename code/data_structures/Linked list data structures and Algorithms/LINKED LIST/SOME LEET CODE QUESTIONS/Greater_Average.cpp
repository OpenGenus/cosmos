#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
void func(float a,float b,float c){
    float av=(a+b)/2;

    if(av>c){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
ll t;
cin>>t;
while (t--)
{
    float a,b,c;
    cin>>a>>b>>c;
    func(a,b,c);
}

return 0;
}
