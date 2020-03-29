#include <iostream>
#include <math.h>
#include <stdlib.h>
#define ll long long

/*
    e: encryption key
    d: decryption key
    Public Key: n, encryptionkey
    Private Key: n, decryptionkey (or prime1, prime2, totifun)
*/

ll prime1, prime2, n, totifun, decryptionkey, encryptionkey, text[100], ciphertext[100];
std::string plaintext;

int isprime(ll n)
{
	if (n == 1)
		return 0;
	ll sq = sqrt(n);
	for (int i = 2; i <= sq; ++i)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

void deter()
{
	for (int i = 2; i < totifun; ++i)
	{
		if (totifun % i == 0)
			continue;
		if (!isprime(i))
			continue;
		ll res = 1;

		while (1)
		{
			res += totifun;
			if (res % i == 0)
			{
				encryptionkey = i;
				decryptionkey = res / i;
				return;
			}
		}
	}
}

ll modular(ll base, ll exponent, ll modulus)
{
	ll result = 1;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

int main(int argc, char **argv)
{
	freopen("rsa_input.in", "r", stdin); //You can give your custom inputs by commenting this line.

	std::cout << "Enter First Prime Number: ";
	std::cin >> prime1;
	if (!isprime(prime1))
	{
		std::cout << std::endl
				  << "Entered number is not prime.";
		exit(0);
	}

	std::cout << std::endl;
	std::cout << "Enter First Prime Number: ";
	std::cin >> prime2;
	if (!isprime(prime2))
	{
		std::cout << std::endl
				  << "Entered number is not prime.";
		exit(0);
	}

	n = prime1 * prime2;
	totifun = (prime1 - 1) * (prime2 - 1);
	deter();

	std::cout << std::endl;
	std::cout << "Enter The Secret Message: ";
	std::cin >> plaintext;

	for (int i = 0; plaintext[i] != '\0'; ++i)
	{
		text[i] = plaintext[i];
		ciphertext[i] = modular(text[i], encryptionkey, n);
		ciphertext[i + 1] = -1;
	}

	std::cout << std::endl
			  << std::endl;
	std::cout << "Encrypted Message is: ";
	for (int i = 0; ciphertext[i] != -1; ++i)
	{
		std::cout << ciphertext[i] << " ";
	}
	std::cout << std::endl
			  << std::endl;

	ll ans;
	std::cout << "Decrypted Message is: ";
	for (ll i = 0; ciphertext[i] != -1; ++i)
	{
		ans = modular(ciphertext[i], decryptionkey, n);
		std::cout << (char)ans;
	}
}
