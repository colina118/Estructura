#include <iostream>
#include "Libro.h"
#include <string>
#include "Busqueda.h"

template<typename T>
void  agregar(T[], std::string, std::string, int , int, std::string, std::string, int pos, int size);


template <typename T>
void imprimeArreglo(T[], int);

int* nuevaBusqueda(int*, int&);

template <typename T>
void pull(T[], int, int);

int main()
{

	const int size = 10;
	int *posi = new int[size];
	int posEncontrado = 0;
	int pos = 0;
	Libro biblioteca[size];
	int opc;
	/*biblioteca[0] = Libro ("hola", "miguel", 23, 1994, "panini", "si");
	biblioteca[1] = Libro ("hola", "miguel", 23, 1994, "panini", "si");
	biblioteca[2] = Libro("eragon", "paulini", 589, 2007, "got", "adios");*/
	//imprimeArreglo<Libro>(biblioteca, size);
	
	do
	{
		std::cout << "1-agrega libro \n2-Imprime arreglo \n3-Busca Libro por autor \n4-Busca libros antes de una fecha \n5-Busca libros despues de una fecha \n6-Buscar por una editorial \n7-Buscar libros entre dos fechas \n8-Elimina un libro \n9-Salir" << std::endl;
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
			std::getline (std::cin, e);
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
			std::cout << "Entre el nombre del autor del libro a buscar: ";

			std::string titulo;

			std::getline (std::cin, titulo);

			Libro biblioteca2[size];

			posi = nuevaBusqueda(posi, posEncontrado);

			posi = Busqueda<Libro, std::string>::busquedaSecuencialPosicion(biblioteca, titulo, size, posi, posEncontrado, [](Libro a, std::string b){return a.getAutor() == b; });

			for (int i = 0; i < posEncontrado; i++)
			{
				biblioteca2[i] = biblioteca[posi[i]];
			}
				imprimeArreglo<Libro>(biblioteca2, size);
		}
			break;
		case 4:
		{
			std::cout << "Pon la fecha para buscar libros anteriores" << std::endl;
			int fecha;
			std::cin >> fecha;
			Libro biblioteca2[size];

			posi = nuevaBusqueda(posi, posEncontrado);
			posi = Busqueda<Libro, int>::busquedaSecuencialPosicion(biblioteca, fecha, size, posi, posEncontrado, [](Libro a, int b){return a.getAño() < b; });

			for (int i = 0; i < posEncontrado; i++)
			{
				biblioteca2[i] = biblioteca[posi[i]];
			}
			imprimeArreglo<Libro>(biblioteca2, size);
		}
			break;
		case 5:
		{
			std::cout << "Pon la fecha para buscar libros despues de ese año" << std::endl;
			int date;
			std::cin >> date;
			Libro biblioteca2[size];

			posi = nuevaBusqueda(posi, posEncontrado);
			posi = Busqueda<Libro, int>::busquedaSecuencialPosicion(biblioteca, date, size, posi, posEncontrado, [](Libro a, int b){return a.getAño() > b; });
			for (int i = 0; i < posEncontrado; i++)
			{
				biblioteca2[i] = biblioteca[posi[i]];
			}
			imprimeArreglo<Libro>(biblioteca2, size);
			
		}
			break;
		case 6:
		{
			std::cout << "Entre el nombre de la editorial del libro a buscar: ";

			std::string titulo;

			std::getline(std::cin, titulo);

			Libro biblioteca2[size];

			posi = nuevaBusqueda(posi, posEncontrado);

			posi = Busqueda<Libro, std::string>::busquedaSecuencialPosicion(biblioteca, titulo, size, posi, posEncontrado, [](Libro a, std::string b){return a.getEditorial() == b; });

			for (int i = 0; i < posEncontrado; i++)
			{
				biblioteca2[i] = biblioteca[posi[i]];
			}
			imprimeArreglo<Libro>(biblioteca2, size);
		}
			break;
		case 7:
		{
			std::cout << "Pon la fecha para buscar libros despues de ese año" << std::endl;
			int date1;
			std::cout << "Pon la fecha para buscar antes de ese año" << std::endl;
			int date2;
			std::cin >> date1;
			std::cin >> date2;
			Libro biblioteca2[size];

			posi = nuevaBusqueda(posi, posEncontrado);
			posi = Busqueda<Libro, int>::busquedaSecuencial(biblioteca, date1, size, posi, posEncontrado, date2, [](Libro a, int b, int c){return (a.getAño() > b && a.getAño() < c); });
			for (int i = 0; i < posEncontrado; i++)
			{
				biblioteca2[i] = biblioteca[posi[i]];
			}
			imprimeArreglo<Libro>(biblioteca2, size);
		}
			break;
		case 8:
		{
			int erase;
			std::cout << "Escribe la posicion del libro que deseas borrar" << std::endl;
			std::cin >> erase;
			pull(biblioteca, erase, size);

		}
			
		}
	} while (opc != 9);

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
void pull(T arreglo[], int pos, int size)
{
	T temp;
	for (int i = pos; i < size; i++)
	{
		//arreglo[i - 1] = 0;
		temp = arreglo[i];
		arreglo[i - 1] = temp;
	}
	pos--;

}

template <typename T>
void imprimeArreglo(T v[], int longitud)
{
	for (int i = 0; i < longitud; ++i) {
		std::cout << v[i] << " ";
	}

	std::cout << std::endl;
}

int* nuevaBusqueda(int* encontrados, int &posEncontrados)
{
	int* encontradosNuevo = new int[10];
	posEncontrados = 0;
	delete[] encontrados;
	encontrados = encontradosNuevo;
	encontradosNuevo = NULL;
	return encontrados;
}
