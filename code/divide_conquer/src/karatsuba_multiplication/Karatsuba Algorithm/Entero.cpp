#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include "macros.hpp"
#include "funcionesAuxiliares.hpp"
#include "Entero.hpp"


using namespace std;

string Entero::operator+(Entero &E)
{
	string numero = E.getNumero();
	string numero2 = this->getNumero();
	return sumarNumero(numero, numero2);
}
string sumarNumero(string &numero1, string &numero2)
{
	int x, y, aux = 0, aux2 = 0; //para sumar

	int digitos = getMayorTam(numero1, numero2); //Obtenemos el mayor tamaño del numero

	string total = "";
	string total2 = "";
	string cadena = "";
	int n1 = numero1.size(); //Almacenamos el tamaño del numero1
	int n2 = numero2.size(); //Almacenamos el tamaño del numero2
	//Se determina si es necesario agregarle ceros no significativos a un numero u a otro
	if ( n1 > n2 ) {
		agregarCerosDelante ( numero2, n1 - n2 );
	} else {
		agregarCerosDelante ( numero1, n2 - n1 );
	}

	for (int i = digitos - 1; i >= 0; i--) {
		//Se convierte el string a digito
		x = numero1[i] - '0';
		y = numero2[i] - '0';
		aux = x + y + aux2;
		//aux2 en la primera iteración vale 0 porque no nos llevamos ninguna.
		if (aux >= 10) {
			aux2 = 1;
			aux = aux % 10;
		} else {
			aux2 = 0;
		}
		total2 = '0' + aux; //convertimos el digito a caracter y lo introducimos en la cadena
		total.insert(0, total2);
		//Estamos en la ultima iteracion y el aux2 vale=1 -> indica que hay que sobreflujo y hay que añadir un 1 significativo al resultado
		if (i == 0 and aux2 == 1) {
			total2 = "1";
			total.insert(0, total2);
			quitarCerosNoSignificativos(total);
			return total;
		}
	}
	quitarCerosNoSignificativos(total);
	return total;
}

string Entero::operator*(Entero &E)
{
	int limite = 0;
	cout << BYELLOW << "Establece el limite deseado:" << RESET << endl;
	while (!(cin >> limite)) {
		std::cin.clear();
		std::cin.ignore(80, '\n');
		std::cout << RED << " Limite no valido, intentelo de nuevo" << RESET << std::endl;
	}
	//Guardamos los numeros y posteriormente llamamos al producto recursivo
	string numero1 = this->getNumero();
	string numero = E.getNumero();

	string resultado = multiplicar(numero1, numero, limite);
	return resultado;
}
string multiplicar(string &numero1, string &numero2, int limite)
{

	//declaración de los numeros con los que operaremos
	int n = numero1.length(), s;
	string w = "", x = "", y = "", z = ""; //almacena digitos que quedan
	string final1 = "", final2 = "", final3 = ""; //Valores usados para realizar las sumas
	string total = "", aux;

	//Algoritmo Multiplicación
	if ( n <= limite) {
		int Entero1, Entero2, aux; //aux nos servira para pasar el numero a cadena
		Entero1 = stoi ( numero1 );
		Entero2 = stoi ( numero2 );
		aux = Entero1 * Entero2; //multiplicamos los numeros y los almacenamos en aux para ahora convertirlo en cadena con to_string
		total = to_string ( aux );
		quitarCerosNoSignificativos ( total );
		return total;
	} else {
		s = n / 2;
		//Particionamos el numero y los almacenamos en w, x, y, z
		partirCadena ( numero1, w, x );
		partirCadena ( numero2, y, z );
		//cout << numero1 << " " << numero2 << " " << w << " " << x << " " << y << " " << z << endl;

		//Primera parte a guardar para realizar la suma
		final1 = multiplicar ( w, y, limite );
		agregarCerosFinal ( final1, 2 * s );

		//Segunda parte a guardar para realizar la suma
		string wz = multiplicar ( w, z, limite );
		string xy = multiplicar ( x, y, limite );
		final2 = sumarNumero ( wz , xy );
		agregarCerosFinal ( final2, s );

		//Tercera parte a guardar para realizar la suma
		final3 = multiplicar ( x, z, limite );
		total = sumarNumero ( final1, final2 );
		return ( sumarNumero ( total, final3 ) );

	}
}

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Entero const &entero)
{
	stream << entero.getNumero();
	return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, Entero &entero)
{

	string numero1;
	stream >> numero1;
	entero.setNumero(numero1);
	return stream;
}