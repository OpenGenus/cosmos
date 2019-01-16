#ifndef _ENTERO_HPP_
#define _ENTERO_HPP_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string.h>
#include <string>
#include <cassert>
#include <math.h>
#include "funcionesbajonivel.hpp"
using namespace std;

/**
 * @brief      Clase
 */
class Entero
{
private:
	string _numero1;
public:

	/**
	 * @brief      Constructor por defecto
	 */
	Entero() {}

	inline void setNumero(string num) {_numero1 = num;}
	inline string getNumero() const {return _numero1;}


	string operator+(Entero &E);

	string operator*(Entero &E);


};
string sumarNumero(string &numero1, string &numero2);
string multiplicar(string &numero1, string &numero2, int limite);

ostream &operator<<(ostream &stream, Entero const &entero);
// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, Entero &entero);


// Fin de _Ordenacion_HPP_
#endif

