
#include <bits/stdc++.h>
using namespace std;

int func2(int n)
{

	int A[10] = { 0 };
	int xt = 0;


	while (n) {
		int r = n % 10;
		A[r] = 1;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (A[i])
			xt++;
	}
	return xt;
}

int ct_d(int n)
{
	int ct = 0;

	while (n) {
		int r = n % 10;
		ct++;
		n /= 10;
	}
	return ct;
}


int  func1(int n)
{
    int a=INT_MAX;
	while (n < a) {
		int dd = func2(n + 1);

		
		int td = ct_d(n + 1);

		if (dd == td) {

		
			return n + 1;
		}

		else
		
			n++;
	}
	return -1;
}

int main()
{
     ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int number;
    cin>>number;

	cout << func1(number);

	return 0;
}
