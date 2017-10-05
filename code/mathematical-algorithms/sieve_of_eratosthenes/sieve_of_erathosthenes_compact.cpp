#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	n = n+1;
	bool primes[n];

	for(int i=0;i<n;++i){
		primes[i] = true;
	}
	primes[0] = false;	// as 0 is not a prime
	primes[1] = false;	// as 1 is not a prime
	int k = 2;
	for(int i=2;i<n;++i){
		while( primes[k] != true ){
			k++;
		}
		if(primes[i] == true){
				for(int j=i; j < n; j = j+i){
					if(j!=i)
					primes[j] = false;
				}}
	}

	for(int i=2; i<n; ++i){
		if(primes[i] == true)
			cout << i <<	' ';
	}
	cout << endl;
}
