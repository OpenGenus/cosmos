#include<iostream>
using namespace std;
int main()
{
  int a[3], b[3];
  int c[] = {0, 0};
  for (int i = 0; i < 3; i++) 
    {
        cin >> a[i];
    }
    for(int j = 0; j < 3; j++)
    {
        cin>>b[j];
    }
    for(int i = 0; i < 3; i++)
    {
        if(a[i] > b[i])
        c[0]++;
        if(a[i] < b[i])
        c[1]++;
  }
  cout<<c[0]<<" "<<c[1];

    return 0;
}
