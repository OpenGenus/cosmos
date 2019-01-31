// Author: Tote93
#include <iostream>
#include <string> 
#include <sstream>
#include <stdlib.h> 
using namespace std;

/* Prototypes */
void addZerosAtFirst(string &c, int nZeros);
int getBiggerSize(string number1, string number2);
void checkNumbers(int size, string &number1, string &number2);
string KaratsubaMultiply(string &numero1, string &numero2, int limite);
string AddNumbers(string &numero1, string &numero2);
void removeNonSignificantZeros(string &c);
void splitString(string original, string &sub1, string &sub2);

int main(){
	string number1, number2;

	cout<< "Insert the first number"<<endl;
	cin >> number1;
	cout<< "Insert the second number"<<endl;
	cin >> number2;	
	
	int size = getBiggerSize(number1, number2);	
	checkNumbers(size, number1, number2);
	
	string result = KaratsubaMultiply(number1, number2, number1.size());
	//Returns number to original without non-significant zeros
	removeNonSignificantZeros(number1);
	removeNonSignificantZeros(number2);
	cout << "Result "<<number1<<" * "<<number2<<" = "<<result<<endl;
}

int getBiggerSize(string number1, string number2){
	if (number1.size() > number2.size()) {
		return number1.size();
	} 
	else {
		return number2.size();
	}	
}

void checkNumbers(int size, string &number1, string &number2){
	int newSize = 0, nZeros = 0;
	if (number1.size() > number2.size()) {
		newSize = number1.size();
	} else {
		newSize = number2.size();
	}

	nZeros = newSize - number1.size();
	addZerosAtFirst(number1, nZeros);
	nZeros = newSize - number2.size();
	addZerosAtFirst(number2, nZeros);

	if (number1.size() % 2 != 0 ) {
		addZerosAtFirst(number1, 1);
	}
	if ( number2.size() % 2 != 0) {
		addZerosAtFirst(number2, 1);
	}	
}

void addZerosAtFirst(string &c, int nZeros)
{
	//Add a number of Zeros at first of the string that has been passed as argument
	string aux = "";
	aux.append(nZeros, '0');
	aux.append(c);
	c = aux;
}

string KaratsubaMultiply(string &numero1, string &numero2, int limite)
{
	int n = numero1.length(), s;
	string w = "", x = "", y = "", z = ""; 
	string final1 = "", final2 = "", final3 = "";
	string total = "";

	if ( n == 1) {
		int Entero1, Entero2, aux;
		Entero1 = atoi ( numero1.c_str() );
		Entero2 = atoi ( numero2.c_str() );
		aux = Entero1 * Entero2;
		//We can replace two next lines with -> total = to_string(aux) using c++11
		ostringstream temp;
		temp<<aux;
		total = temp.str();
		removeNonSignificantZeros ( total );
		return total;
	} else {
		s = n / 2;
		splitString ( numero1, w, x );
		splitString ( numero2, y, z );

		final1 = KaratsubaMultiply ( w, y, limite );
		final1.append(2 * s, '0');		

		string wz = KaratsubaMultiply ( w, z, limite );
		string xy = KaratsubaMultiply ( x, y, limite );
		final2 = AddNumbers ( wz , xy );
		final2.append(s, '0');

		final3 = KaratsubaMultiply ( x, z, limite );
		total = AddNumbers ( final1, final2 );
		return ( AddNumbers ( total, final3 ) );
	}
}

void removeNonSignificantZeros(string &c)
{
	int acum = 0;
	for (int i = 0; i < c.length(); ++i) {
		if (c[i] != '0') {
			break;
		} else {
			acum++;
		}
	}	
	if (c.size() != acum) {
		c = c.substr(acum, c.length());
	} else {
		c = c.substr(acum - 1, c.length());
	}
}

void splitString(string original, string &sub1, string &sub2)
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

	if (sub1.size() % 2 != 0 && sub2.size() > 2) {
		addZerosAtFirst(sub1, 1);
	}
	if (sub2.size() > 2 && sub2.size() % 2 != 0) {
		addZerosAtFirst(sub2, 1);
	}
}

string AddNumbers(string &numero1, string &numero2)
{
	int x, y, aux = 0, aux2 = 0;
	int digitos = getBiggerSize(numero1, numero2); 
	string total = "", total2 = "", cadena = "";
	int n1 = numero1.size(); 
	int n2 = numero2.size();

	if ( n1 > n2 ) {
		addZerosAtFirst ( numero2, n1 - n2 );
	} else {
		addZerosAtFirst ( numero1, n2 - n1 );
	}

	for (int i = digitos - 1; i >= 0; i--) {
		x = numero1[i] - '0';
		y = numero2[i] - '0';
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
