
#include <bits/stdc++.h>
using namespace std;
 
void Sieve(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    if(n>=2){
    cout << "Following are the prime numbers smaller than or equal to " << n << endl;
    Sieve(n);
	}
	else
	{
	cout<<"No prime numbers less than or equal to "<<n<<endl;	
	}
    return 0;
}
