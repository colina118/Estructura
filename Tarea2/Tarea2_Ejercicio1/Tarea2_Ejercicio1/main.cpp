#include <iostream>
#include "Libro.h"
#include <string>
#include "Busqueda.h"

template<typename T>
void  agregar(T[], std::string, std::string, int , int, std::string, std::string, int pos, int size);


template <typename T>
void imprimeArreglo(T[], int);

int main()
{

	const int size = 10;
	
	int pos = 0;
	Libro biblioteca[size];
	Libro biblioteca2[size];
	int opc;
	/*biblioteca[0] = Libro ("hola", "miguel", 23, 1994, "panini", "si");
	biblioteca[1] = Libro ("hola", "miguel", 23, 1994, "panini", "si");
	biblioteca[2] = Libro("eragon", "paulini", 589, 2007, "got", "adios");*/
	//imprimeArreglo<Libro>(biblioteca, size);
	
	do
	{
		std::cout << "1-agrega libro \n2-Imprime arreglo \n3-Busca Libro" << std::endl;
		std::cin >> opc;
		std::cin.ignore();
		switch (opc)
		{
		case 1:
		{
			std::string tit, au, ed, e;
			int num = 0;
			int añ = 0;
			std::cout << "Escribe el titulo del libro" << std::endl;
			std::getline (std::cin, tit);
			std::cout << "Escribe el nombre del autor" << std::endl;
			std::getline (std::cin, au);
			std::cout << "Escribe la editorial" << std::endl;
			std::getline (std::cin, ed);
			std::cout << "Escribe la edicion" << std::endl;
			std::cin >> e;
			std::cout << "Escribe el numero de paginas" << std::endl;
			std::cin >> num;
			std::cout << "Escribe el año" << std::endl;
			std::cin >> añ;
			agregar(biblioteca, tit, au, num, añ, ed, e, pos, size);
			pos++;
		}
			break;
		case 2:
		{
			imprimeArreglo<Libro>(biblioteca, size);
		}
			break;
		case 3:
		{
			int *posi = new int[size];
			int a;
			std::cout << "Entre el titulo del libro a buscar: ";

			std::string titulo;

			std::cin >> titulo;
			int *posi = Busqueda<Libro>::busquedaSecuencialPosicion(biblioteca, Libro(titulo, " ", 0, 0, "No importa", "No importa"), size, posi);
			for (int i = 0; i < size; i++)
			{
				biblioteca2[i] = biblioteca[posi[i]];
			}
				imprimeArreglo<Libro>(biblioteca2, size);
		}

		}
	} while (opc != 10);

	return 0;
}

template < typename T>
void agregar(T arreglo[], std::string tit, std::string a, int num, int añ, std::string ed, std::string e, int pos, int size)
{
	if (pos < size)
	{
		arreglo[pos] = Libro(tit, a, num, añ, ed, e);
		pos++;
	}
}

template <typename T>
void imprimeArreglo(T v[], int longitud)
{
	for (int i = 0; i < longitud; ++i) {
		std::cout << v[i] << " ";
	}

	std::cout << std::endl;
}
