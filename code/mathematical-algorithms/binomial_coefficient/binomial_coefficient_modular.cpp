//Author:Arpan Konar
/*
Part of Cosmos by OpenGenus Foundation
*/
//Constraint: n<=10^6 and r<=10^6
#include <iostream>
using namespace std;
#define M 1000001					
long long mod=1000000007;			
long long fact[M+1];				//Array which stores factorial values
long long inv[M+1];					//Array which stores inverse factorial values
//Function to calculate (a^b)%p
long long power(long long a, long long b, long long p){
	long long x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = (x*y)%p;
		}
		y = (y*y)%p;
		b /= 2;
	}
	return x%p;
}
//Function to calculate modular inverse using Fermat's little theorem
long long modular_inverse(long long n){
	return power(n, mod-2, mod);
}	
//Function which calculates inverse factorial and stores them in an array
void fill()
{
	fact[0]=1;
	for(long long i=1;i<=M;i++)
	fact[i]=(fact[i-1]*i)%mod;
	inv[M]=modular_inverse(fact[M]);
	for(long long i=M-1;i>=0;i--)
	inv[i] =(inv[i+1]*1ll*(i+1*1ll))%mod;
}
//Function to find nCr%1000000007
long long coeff(long long n,long long k)
{
    long long f=fact[n];
    f=(f*inv[k])%mod;
    f=(f*inv[n-k])%mod;
    return f;
}
//Main function
int main()
{
	fill();
	cout<<"Enter n and r to calculate nCr(modulo)1000000007:"<<endl;
	long long n,r;
	cin>>n>>r;
	cout<<coeff(n,r)<<endl;
}
