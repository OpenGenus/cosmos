#include <iostream>
using namespace std;

int main() {
unsigned long int t;
cin>>t;
while(t--)
{
    unsigned long int N,K,arr[26]={0},temp;
    int count1=0;
    char str[1000000];
    cin>>N>>K;
    cin>>str;
    temp=0;
    while(temp<N)
    {
        switch(str[temp])
        {
            case 'a':
            arr[0]++;
            break;
            case 'b':
            arr[1]++;
            break;
            case 'c':
            arr[2]++;
            break;
            case 'd':
            arr[3]++;
            break;
            case 'e':
            arr[4]++;
            break;
            case 'f':
            arr[5]++;
            break;
            case 'g':
            arr[6]++;
            break;
            case 'h':
            arr[7]++;
            break;
            case 'i':
            arr[8]++;
            break;
            case 'j':
            arr[9]++;
            break;
            case 'k':
            arr[10]++;
            break;
            case 'l':
            arr[11]++;
            break;
            case 'm':
            arr[12]++;
            break;
            case 'n':
            arr[13]++;
            break;
            case 'o':
            arr[14]++;
            break;
            case 'p':
            arr[15]++;
            break;
            case 'q':
            arr[16]++;
            break;
            case 'r':
            arr[17]++;
            break;
            case 's':
            arr[18]++;
            break;
            case 't':
            arr[19]++;
            break;
            case 'u':
            arr[20]++;
            break;
            case 'v':
            arr[21]++;
            break;
            case 'w':
            arr[22]++;
            break;
            case 'x':
            arr[23]++;
            break;
            case 'y':
            arr[24]++;
            break;
            case 'z':
            arr[25]++;
            break;
            
            
        }
        temp++;
    }
    for(int i=0;i<26;i++)
    {
      if(arr[i]%2!=0)
      count1++;
      else if(arr[i]%2==0)
      {
          if(arr[i]/2>K)
          count1++;
      }
    }
    if(count1>0)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
    
    
}

	return 0;
}
