#include <bits/stdc++.h>
using namespace std;


void sieve(long long n, bool prime[]){
	prime[0]=prime[1]=false;
	for(int i=2;i<n;i++){
		prime[i]=true;
	}
	for(int i=2;i*i<=n;i++){
		if(prime[i]==true){
			for(int j = 2 ; j*i <n ;j++){
				prime[i*j]=false;
			}
		}
	}
}

bool check_prime(long long num){
	if(num==2||num==3)
		return true;
	if(num==1||num==0)
		return false;
	for(int i=3;i*i<=num;i+=2){
		if(num%i==0)
			return false;
	}
	return true;
}

bool check_right(long long num){
	if(check_prime(num)==false)
		return false;
	bool isprime[num+1];
	sieve(num+1,isprime);
	for(int i = num;i>0;i/=10){
		if(isprime[i]==false)
			return false;
	}
	return true;
}

int countdigits(long long number){
	int count=0;
	for(int i=number;i>0;i/=10)
		++count;
	return count;
}

bool check_left(long long num){
	if(check_prime(num)==false)return false;
	int cou = countdigits(num);
	bool isprime[num+1];
	sieve(num+1,isprime);
	for(int i = num;i>0;i--){
		int mod=pow(10,i);
		if(isprime[num%mod]==false)return false;
	}
	return true;
}

bool check_two_way_truncatable(long long num){
	return check_left(num)&&check_right(num);
}
int main(){
	int counter=0,count=0;
	long long sum=0,num=11;
	vector<long long>truncatable_prime;
	while(counter!=11){
		//cout<<count<<" ";
		if(check_two_way_truncatable(num)==true){
			truncatable_prime.push_back(num);
			counter++;
			cout<<num<<" "<<counter<<endl;
		}
		num+=2;
	}

	for(int i=0;i<truncatable_prime.size();i++){
		cout<<truncatable_prime[i]<<" ";
	}
	/*bool isprime[50];
	sieve(50,isprime);
	for(int i=0;i<50;i++){
		if(isprime[i]){cout<<i<<" ";}
	}*/
}