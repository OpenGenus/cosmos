#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "macros.hpp"
#include <vector>
#include <iomanip>
#include "funcionesAuxiliares.hpp"
#include "Entero.hpp"
using namespace std;

int menu()
{
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion = 2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1, 10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++, 10);
	std::cout <<  "[1] Suma de numeros";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
	PLACE(posicion++, 10);
	std::cout << "[2] Producto de numeros";

	posicion++;
	PLACE(posicion++, 10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++, 10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

	// Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();

	return opcion;
}
void start(int opt)
{
	Entero a;
	Entero b;

	//leemos los datos por teclado
	leerDatos(a, b);
	int tam = getMayorTam(a.getNumero(), b.getNumero());
	comprobarNumeros(tam, a, b);
	if (opt == 0) {
		//Hago la suma
		string resultado = a + b;
		cout << BIGREEN << "Resultado: " << resultado << RESET << endl;
	} else {
		//Hago el producto
		string resultado = a * b;
		cout << BIGREEN "Resultado: " << resultado << RESET << endl;

	}
	getchar();
}
void comprobarNumeros(int numDigitos, Entero &c, Entero &b)
{
	string n1 = c.getNumero(), n2 = b.getNumero();
	int tam = 0, nCeros = 0;
	if (n1.size() > n2.size()) {
		tam = n1.size();
	} else {
		tam = n2.size();
	}

	nCeros = tam - n1.size();
	agregarCerosDelante(n1, nCeros);
	nCeros = tam - n2.size();
	agregarCerosDelante(n2, nCeros);

	if (n1.size() % 2 != 0 ) {
		agregarCerosDelante(n1, 1);
	}
	if ( n2.size() % 2 != 0) {
		agregarCerosDelante(n2, 1);
	}
	c.setNumero(n1);
	b.setNumero(n2);
}
int getMayorTam(string numero1, string numero2)
{
	if (numero1.size() > numero2.size()) {
		return numero1.size();
	} else {
		return numero2.size();
	}
}
void leerDatos(Entero &entero1, Entero &entero2)
{
	string n1, n2;
	cout << "Introduce el primer número: " << endl;
	cin >> n1;
	cout << "Introduce el segundo número: " << endl;
	cin >> n2;
	entero1.setNumero(n1);
	entero2.setNumero(n2);
}


