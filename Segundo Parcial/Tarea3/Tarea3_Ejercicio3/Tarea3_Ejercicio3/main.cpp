#include <iostream>
#include "OrderedLinkedList.h"
#include "Persona.h"

int main(int argc, char **argv)
{
	using namespace mike;
	OrderedLinkedList<Persona> listaAsc(true);
	OrderedLinkedList<Persona> listaDesc(false);
	int opc = 0;
	int cont = 0;
	std::string nombre, apellidos;
	int dia, mes, anio, edad;
	mike::Node<Persona> * holder;

	while (opc != 6)
	{
		std::cout << "Bienvenido al sistema de Personas." << std::endl;
		std::cout << "Eliga una opcion\n1. Agrega una persona\n2. Buscar\n3. Borrar Persona\n4. Ver lista de personas\n5. Borrar\n6. Salir" << std::endl;
		std::cin >> opc;
		switch (opc)
		{
		case 1:
			std::cout << "Nombre de la Persona: ";
			std::cin >> nombre;
			std::cout << "Apellidos de la Persona: ";
			std::cin >> apellidos;
			std::cout << "Edad: ";
			std::cin >> edad;
			std::cout << "Anio de nacimiento: ";
			std::cin >> anio;
			std::cout << "Mes de nacimiento: ";
			std::cin >> mes;
			std::cout << "Dia de nacimiento: ";
			std::cin >> dia;

			listaAsc.insert(Persona(nombre, apellidos, edad, anio, mes, dia));
			listaDesc.insert(Persona(nombre, apellidos, edad, anio, mes, dia));
			break;
		case 2:
			if (listaAsc.empty())
			{
				std::cout << "La lista esta vacia" << std::endl;
				break;
			}
			std::cout << "Ingrese el nombre de la persona que desea buscar: ";
			std::cin >> nombre;
			while (cont < listaAsc.size())
			{
				holder = listaAsc.at(cont);
				if (holder->getInfo().getNombre() == nombre)
				{
					std::cout << holder->getInfo();
					std::cout << "Posicion: " << cont << std::endl << std::endl;
				}
				++cont;
			}
			cont = 0;
			break;
		case 3:
			int pos;
			std::cout << "Dame la posicion que quieres eliminar de la lista: ";
			std::cin >> pos;
			holder = listaAsc.remove(pos);
			delete holder;
			holder = nullptr;
			holder = listaDesc.remove(listaDesc.size() - pos - 1);
			delete holder;
			holder = nullptr;

			break;
		case 4:
			std::cout << "1. Ascendente\n2. Descendente" << std::endl;
			std::cin >> opc;
			if (opc == 1)
			{
				std::cout << listaAsc;
			}
			else
			{
				std::cout << listaDesc;
			}
			opc = 4;

			break;
		case 5:
			listaAsc.clear();
			listaDesc.clear();

			break;
		case 6:
			std::cout << "Adios" << std::endl;
			break;
		default:
			std::cout << "No es valida esa opcion " << std::endl;
			break;
		}
	}



	return 0;
}