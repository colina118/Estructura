#include <iostream>
#include <string>
#include "LinkedList.h"

bool esPrimo(int, int);

int main()
{
	using namespace mike;
	LinkedList<int> * lista = new LinkedList<int>();
	LinkedList<int> * list = new LinkedList<int>();
	int inicio = 0;
	int fin = 0;
	int n = 0;
	int resta;
	int con = 0;


	std::cout << "Donde inicia el rango?" << std::endl;
	std::cin >> inicio;
	std::cout << "Donde termina el rango?" << std::endl;
	std::cin >> fin;
	std::cout << "Cuantos numeros quieres imprimir" << std::endl;
	std::cin >> n;

	resta = fin - inicio;
	while (inicio < fin && con < n)
	{
		int cont = 0;
		if (inicio == 0)
		{
			cont = 1;
		}
		else if (inicio == 1)
		{
			cont = 1;
		}
		else
		{
			for (int j = 2; j < inicio; j++)
			{
				if (inicio%j == 0)
				{
					cont++;
					break;
				}
			}
		}
		if (cont == 0)
		{
			lista->insertFront(inicio);
			con++;
		}
		inicio++;
	}


	std::cout << *lista << std::endl;
	std::cout << *list << std::endl;
	return 0;

}

