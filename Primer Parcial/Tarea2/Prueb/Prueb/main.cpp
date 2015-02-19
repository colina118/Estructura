#include <iostream>
#include <string>
#include <cstdlib>
#include "OrdenamientoGenerico.h"

//probando

char genRandom()
{
	static const char alphanum[] =
		"0123456789"
		"!@#$%^&*"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	int stringLength = sizeof(alphanum) - 1;
	return alphanum[rand() % stringLength];
}

void fill(std::string list[], int size)
{
	std::string str;
	for (int i = 0; i < size; i++)
	{
		for (int a = 0; a < 5; a++)
		{
			str += genRandom();
		}

		list[i] = str;
		str.clear();
	}
}

void printArreglo(std::string lista[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << lista[i] << std::endl;
	}
}

int main()
{
	const int size = 1000;
	std::string lista[size];
	int opc;
	do
	{


		std::cout << "Bienvenido seleccione alguna opción" << std::endl;
		std::cout << "1. Genera el arreglo" << std::endl;
		std::cout << "2. Imprime el arreglo" << std::endl;
		std::cout << "3. Ordenar ascendentemente con bubble sort" << std::endl;
		std::cout << "4. Ordenar ascendentemente con insertion sort" << std::endl;
		std::cout << "5. Ordenar ascendentemente con selection sort" << std::endl;
		std::cout << "6. Ordenar descendentemente con bubble sort" << std::endl;
		std::cout << "7. Ordenar descendentemente con insertion sort" << std::endl;
		std::cout << "8. Ordenar descendentemente con selection sort" << std::endl;
		std::cout << "9. Salir del programa" << std::endl;

		std::cin >> opc;

		switch (opc)
		{

		case 1:
		{
			fill(lista, size);
		}
			break;
		case 2:
		{
			printArreglo(lista, size);
		}
			break;
		case 3:
		{
			Ordenamiento<std::string>::burbuja(lista, size, Ordenamiento<std::string>::asc);
		}
			break;
		case 4:
		{
			Ordenamiento<std::string>::insercion(lista, size, Ordenamiento<std::string>::asc);
		}
			break;
		case 5:
		{
			Ordenamiento<std::string>::seleccion(lista, size, Ordenamiento<std::string>::asc);
		}
			break;
		case 6:
		{
			Ordenamiento<std::string>::burbuja(lista, size, Ordenamiento<std::string>::desc);
		}
			break;
		case 7:
		{
			Ordenamiento<std::string>::insercion(lista, size, Ordenamiento<std::string>::desc);
		}
			break;
		case 8:
		{
			Ordenamiento<std::string>::seleccion(lista, size, Ordenamiento<std::string>::desc);
		}
		default:
			break;
		}

	} while (opc != 9);

	/*const int size = 10;
	std::string lista[size];
	fill(lista, 10);
	printArreglo(lista, 10);
	Ordenamiento<std::string>::seleccion(lista, size, Ordenamiento<std::string>::asc);
	std::cout << std::endl;
	printArreglo(lista, 10);
	*/

	return 0;
}