// Author: Tote93
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>


/* Prototypes */
int getBiggerSize(const std::string &number1, const std::string &number2);
void checkNumbers(int size, std::string &number1, std::string &number2);
std::string KaratsubaMultiply(std::string &number1, std::string &number2, int limit);
std::string AddNumbers(std::string &number1, std::string &number2);
void removeNonSignificantZeros(std::string &c);
void splitString(std::string original, std::string &sub1, std::string &sub2);

int main()
{
	std::string number1, number2;

	std::cout << "Insert the first number \n";
	std::cin >> number1;
	std::cout << "Insert the second number \n";
	std::cin >> number2;

	int size = getBiggerSize(number1, number2);
	checkNumbers(size, number1, number2);

	std::string result = KaratsubaMultiply(number1, number2, number1.length());
	//Returns number to original without non-significant zeros
	removeNonSignificantZeros(number1);
	removeNonSignificantZeros(number2);
	std::cout << "Result " << number1 << " * " << number2 << " = " << result << "\n";
}

int getBiggerSize(const std::string &number1, const std::string &number2)
{
	int numb1Length = number1.length();
	int numb2Length = number2.length();
	return (numb1Length > numb2Length) ? numb1Length : numb2Length;
}

void checkNumbers(int size, std::string &number1, std::string &number2)
{
	int newSize = 0, nZeros = 0;
	newSize = getBiggerSize(number1, number2);

	nZeros = newSize - number1.length();
	number1.insert(number1.begin(), nZeros, '0');
	nZeros = newSize - number2.length();
	number2.insert(number2.begin(), nZeros, '0');

	if (number1.length() % 2 != 0 ) {
		number1.insert(number1.begin(), 1, '0');
	}
	if ( number2.length() % 2 != 0) {
		number2.insert(number2.begin(), 1, '0');
	}
}

std::string KaratsubaMultiply(std::string &number1, std::string &number2, int limit)
{
	int n = number1.length(), s;
	std::string w = "", x = "", y = "", z = "";
	std::string final1 = "", final2 = "", final3 = "";
	std::string total = "";

	if ( n == 1) {
		int integer1, integer2, aux;
		integer1 = atoi ( number1.c_str() );
		integer2 = atoi ( number2.c_str() );
		aux = integer1 * integer2;
		//We can replace two next lines with -> total = to_string(aux) using c++11
		std::ostringstream temp;
		temp << aux;
		total = temp.str();
		removeNonSignificantZeros ( total );
		return total;
	} else {
		s = n / 2;
		splitString ( number1, w, x );
		splitString ( number2, y, z );

		final1 = KaratsubaMultiply ( w, y, n );
		final1.append(2 * s, '0');

		std::string wz = KaratsubaMultiply ( w, z, n );
		std::string xy = KaratsubaMultiply ( x, y, n );
		final2 = AddNumbers ( wz , xy );
		final2.append(s, '0');

		final3 = KaratsubaMultiply ( x, z, n );
		total = AddNumbers ( final1, final2 );
		return ( AddNumbers ( total, final3 ) );
	}
}

void removeNonSignificantZeros(std::string &c)
{
	int acum = 0;
	for (int i = 0; i < c.length(); ++i) {
		if (c[i] != '0') {
			break;
		} else {
			acum++;
		}
	}
	if (c.length() != acum) {
		c = c.substr(acum, c.length());
	} else {
		c = c.substr(acum - 1, c.length());
	}
}

void splitString(std::string original, std::string &sub1, std::string &sub2)
{
	int n, n1, n2;
	sub1 = sub2 = "";
	n = original.length();

	if (n % 2 == 0) {
		n1 = n / 2;
		n2 = n1;
	} else {
		n1 = (n + 1) / 2;
		n2 = n1 - 1;
	}

	sub1 = original.substr(0, n1);
	sub2 = original.substr(n1, n);

	if (sub1.length() % 2 != 0 && sub2.length() > 2) {
		sub1.insert(sub1.begin(), 1, '0');
	}
	if (sub2.length() > 2 && sub2.length() % 2 != 0) {
		sub2.insert(sub2.begin(), 1, '0');
	}
}

std::string AddNumbers(std::string &number1, std::string &number2)
{
	int x, y, aux = 0, aux2 = 0;
	int digitos = getBiggerSize(number1, number2);
	std::string total = "", total2 = "", cadena = "";
	int n1 = number1.length();
	int n2 = number2.length();

	if ( n1 > n2 ) {
		number2.insert(number2.begin(), n1 - n2, '0');
	} else {
		number1.insert(number1.begin(), n2 - n1, '0');
	}

	for (int i = digitos - 1; i >= 0; i--) {
		x = number1[i] - '0';
		y = number2[i] - '0';
		aux = x + y + aux2;

		if (aux >= 10) {
			aux2 = 1;
			aux = aux % 10;
		} else {
			aux2 = 0;
		}
		total2 = '0' + aux;
		total.insert(0, total2);
		if (i == 0 and aux2 == 1) {
			total2 = "1";
			total.insert(0, total2);
			removeNonSignificantZeros(total);
			return total;
		}
	}
	removeNonSignificantZeros(total);
	return total;
}
