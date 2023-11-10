/* Part of Cosmos by OpenGenus Foundation 
 * RSA(Rivest–Shamir–Adleman) Public Key Cryptosystem
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>

long long p, q, n, t, d, e, m[100], en[100];
/*
    p: prime 1
    q: prime 2
    n: p*q
    t: euler totient function phi(n)
    e: encryption key
    d: decryption key

    Public Key: n, e
    Private Key: n, d   (or p, q, t)
*/
char msg[100];

bool prime(int n)
{
	if ( n == 1 )
		return 0;
	int sq = sqrt(n);
	for ( int i = 2 ; i <= sq ; i++ )
	{
		if ( n % i == 0 )
			return 0;
	}
	return 1;
}

void chooseED()
{
	for ( int i = 2 ; i < t ; i++ )
	{
		if ( t % i == 0 )
			continue;
		if ( !prime(i) )
			continue;
		int res = 1;

		while ( 1 )
		{
			res += t;
			if ( res % i == 0 )
			{
				e = i;
				d = res / i;
				return;
			}
		}
	}
}

// fast modular exponentiation, O(log n)
long long modular_pow(long long base, long long exponent, long long modulus)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main()
{
	freopen("rsa_input.in", "r", stdin);
	printf("Enter first prime number:\n");
	scanf("%lld", &p);

	if (  !prime(p) )
	{
		printf("Error: \'p\' is not prime\n");
		exit(0);
	}

	printf("Enter second prime number:\n");
	scanf("%lld", &q);

	if (  !prime(q) )
	{
		printf("Error: \'q\' is not prime\n");
		exit(0);
	}

	n = p * q;
	t = (p-1) * (q-1);
	chooseED();

	printf("Enter your secret message:\n");
	scanf("%s", msg);

	for ( int i = 0 ; msg[i] != '\0' ; i++ )
	{
		m[i] = msg[i];
		en[i] = modular_pow(m[i], e, n);
		en[i+1] = -1;
	}

	printf("Encrypted Message:\n");
	for ( int i = 0 ; en[i] != -1 ; i++ )
	{
		printf("%lld ", en[i]);
	}
	printf("\n");

	long long ans;
	printf("Decrypted Message:\n");
	for ( int i = 0 ; en[i] != -1 ; i++ )
	{
		ans = modular_pow(en[i], d, n);
		printf("%c", (char)ans);
	}
}
