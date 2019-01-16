#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <string.h>
#include <string>
#include <iostream>
#include "funcionesbajonivel.hpp"
using namespace std;


string reservarCadena(int n)
{
	string cadena;
	cadena.resize(n);
	return cadena;
}
//Divide la cadena "original" en dos subcadenas sub1 y sub2, siendo ambas del mismo tamaño cuando el número de caracteres de original es par
//En caso de que el numero de cifras sea impar, se obligará a que sea par para realizar la particion correctamente
void partirCadena(string original, string &sub1, string &sub2)
{
	int n;
	int n1, n2;

	sub1 = sub2 = ""; //Limpiamos las dos subcadenas para evitar errores

	n = original.length(); //Obtengo la longitud de la cadena origen

	if (n % 2 == 0) { //n es par, por tanto ambas cifras son pares
		n1 = n / 2;
		n2 = n1;
	} else { //n es impar, por tanto la segunda cifra tendra n1-1
		n1 = (n + 1) / 2;
		n2 = n1 - 1;
	}
	//Devuelve una parte del string definida por los parámetros inicio, fin
	sub1 = original.substr(0, n1);
	sub2 = original.substr(n1, n);

	//En caso de que la subcadena1 sea impar y su tamaño sea > 2, se agregará un cero no significativo
	if (sub1.size() % 2 != 0 && sub2.size() > 2) {
		agregarCerosDelante(sub1, 1);
	}
	//En caso de que la subcadena2 sea impar y su tamaño sea > 2, se agregará un cero no significativo
	if (sub2.size() > 2 && sub2.size() % 2 != 0) {
		agregarCerosDelante(sub2, 1);
	}
	//Con esto se consigue que siempre sea un numero divisible entre 2
}

void agregarCerosFinal(string &c, int nCeros)
{
	c.append(nCeros, '0');//Agregamos un numero de ceros al final de la cadena pasada
}

void agregarCerosDelante(string &c, int nCeros)
{
	string aux = "";
	aux.append(nCeros, '0');
	aux.append(c);
	c = aux;
	//Agregamos un numero de Ceros delante de la cadena que ha sido pasada
}

void quitarCerosNoSignificativos(string &c)
{
	int contador = 0;
	for (int i = 0; i < c.length(); ++i) {
		if (c[i] != '0') {
			break;
		} else {
			contador++;
		}
	}
	//Hay distinto numero de ceros que de cifras => 0001 (4), por tanto se quitaran todos los no significativos
	if (c.size() != contador) {
		c = c.substr(contador, c.length());
	} else {
		c = c.substr(contador - 1, c.length());//Todos los numeros son 0, por tanto se quitaran todos menos 1.
	}

}
