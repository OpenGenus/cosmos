#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "macros.hpp"
#include <vector>
#include <iomanip>
#include "Entero.hpp"
using namespace std;

int menu();//!<  \brief Menu

/**
 * @brief      Inicia los algoritmos
 *
 * @param[in]  opt   La option
 */
void start(int opt);
void comprobarNumeros(int numDigitos, Entero &c, Entero &b);
int getMayorTam(string numero1, string numero2);
void leerDatos(Entero &entero1, Entero &entero2);
// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

