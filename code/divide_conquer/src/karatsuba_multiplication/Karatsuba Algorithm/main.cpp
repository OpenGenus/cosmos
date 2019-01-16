#include <iostream>
#include <string>
#include <stdlib.h>
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"

using namespace std;
int main()
{



	int opcion;

	do {
		// The menu option is chosen
		opcion = menu();

		std::cout << CLEAR_SCREEN;
		PLACE(3, 1);

		// The chosen menu option is executed
		switch (opcion) {
		case 0:
			std::cout << INVERSE;
			std::cout << "End of the program" << std::endl;
			std::cout << RESET;
			break;

		///////////////////////////////////////////////////////////////////

		case 1:
			std::cout << "[1] Add numbers" << std::endl;

			start(0);
			break;

		//////////////////////////////////////////////////////////////////////////////
		case 2:
			std::cout << "[2] Multiply Numbers" << std::endl;
			start(1);
			break;
		//////////////////////////////////////////////////////////////////////////////
		default:
			std::cout << BIRED;
			std::cout << "Opción incorrecta ";
			std::cout << RESET;
			std::cout << "--> ";
			std::cout << ONIRED;
			std::cout << opcion << std::endl;
			std::cout << RESET;
		}

		if (opcion != 0) {
			PLACE(25, 1);
			std::cout << "Pulse ";
			std::cout << BIGREEN;
			std::cout << "ENTER";
			std::cout << RESET;
			std::cout << " para mostrar el ";
			std::cout << INVERSE;
			std::cout << "menú";
			std::cout << RESET;

			// Pausa
			std::cin.ignore();

			std::cout << CLEAR_SCREEN;
		}
	} while (opcion != 0);

	return 0;
}