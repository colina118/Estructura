#include <iostream>
#include "LinkedList.h"
#include <string>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(nullptr));
	using namespace mike;
	float rando;
	LinkedList<float>  lista;
	LinkedList<float> list;
	LinkedList<float> listaa;
	int tam, cont = 0, tama;
	bool test;

	std::cout << "Eliga cuantos numeros van en la primera lista" << std::endl;
	std::cin >> tam;
	std::cout << "Eliga cuantos numeros van en la segunda lista" << std::endl;
	std::cin >> tama;

	for (int i = 0; i < tam; i++)
	{
		rando = rand() % 100;
		rando = rando / 10;

		lista.insert(rando, i);
	}

	for (int j = 0; j < tama; j++)
	{
		rando = rand() % 100;
		rando = rando / 10;

		list.insert(rando, j);
	}
	
	
	/*lista.insert(2, 0);
	list.insert(2, 0);
	list.insert(1, 2);
	lista.insert(1, 0);
	*/

	std::cout << lista << std::endl;
	std::cout << list << std::endl;

	std::cout << "Eiga operacion\n1. Union\n2. Interseccion\n3. Resta lista1-lista2\n4. Resta lista2-lista1\n5. Multiplicacion" << std::endl;
	int eleccion;
	std::cin >> eleccion;
	switch (eleccion)
	{
	case 1:
		for (auto i : lista)
		{
			listaa.insertBack(i.getInfo());
		}
		for (auto j : list)
		{
			cont = 0;
			test = true;
			while (test == true && cont < listaa.size())
			{
				if (j.getInfo() == listaa.at(cont)->getInfo())
				{
					test = false;
					break;
				}
				++cont;
			}
			if (test)
			{
				listaa.insertBack(j.getInfo());
			}
		}
		std::cout << std::endl << listaa << std::endl;
		break;
	case 2:
		for (auto i : lista)
		{
			for (auto j : list)
			{
				if (i.getInfo() == j.getInfo())
				{
					listaa.insertBack(i.getInfo());
					break;
				}
			}
			cont++;
		}
		std::cout << listaa << std::endl;
		break;
	case 3:
		for (auto i : lista)
		{
			cont = 0;
			for (auto j : list)
			{
			if (i.getInfo() == j.getInfo())
				{
					cont = -1;
					break;
				}
			}
			if (cont != -1)
			{
				listaa.insertBack(i.getInfo());
			}
		}
		std::cout << listaa << std::endl;
		break;
	case 4:
		for (auto i : list)
		{
			cont = 0;
			for (auto j : lista)
			{
				if (i.getInfo() == j.getInfo())
				{
					cont = -1;
					break;
				}
			}
			if (cont != -1)
			{
				listaa.insertBack(i.getInfo());
			}
		}
		std::cout << listaa << std::endl;
		break;
	case 5:
		for (auto i : lista)
		{
			float a = 1;
			for (auto j : list)
			{
				a = i.getInfo() * j.getInfo();
				listaa.insertBack(a);
			}
		}
		std::cout << listaa << std::endl;
		break;
	}


	return 0;
}