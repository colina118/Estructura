#include <iostream>
#include "Concesionaria.h"

template<typename T>
void  agregar(T[], int, std::string, std::string, int, int);


template <typename T>
void imprimeArreglo(T[], int);

int main()
{
	int opc = 0;
	int monto;
	int pos = 0;
	std::string comprador;
	std::string tipo;
	Concesionaria lista[5];

	while (opc != 5)
	{
		std::cout << "1- Agregar\n2- Listado ventas \n3-Listado personas \n4-Imprime" << std::endl;
		std::cin >> opc;
		switch(opc)
		{
			case 1:
				std::cout << "escriba el monto" << std::endl;
				std::cin >> monto;
				std::cin.ignore();
				std::cout << "Escriba el tipo" << std::endl;
				std::getline(std::cin, tipo);
				std::cout << "escriba el nombre del comprador" << std::endl;
				std::getline(std::cin, comprador);
				agregar(lista, monto, tipo, comprador, 0, 5);
				pos++;
				break;
			case 2:	
				//Ordenamiento<Libro>::insercion(lista, 5, [](Libro a, Libro b){ return a.getTitulo() > b.getTitulo(); })
				break;
			case 3:
				break;
			case 4:
				imprimeArreglo<Concesionaria>(lista, 5); 
					break;
		}
	}

	return 0;
}

template <typename T>
void imprimeArreglo(T v[], int longitud)
{
	for (int i = 0; i < longitud; ++i) {
		std::cout << v[i] << " ";
	}

	std::cout << std::endl;
}

template < typename T>
void agregar(T arreglo[], int monto, std::string tipo, std::string comprador, int pos, int size)
{
	if (pos < size)
	{
		arreglo[pos] =  Concesionaria(monto, tipo, comprador);
		pos++;
	}
}