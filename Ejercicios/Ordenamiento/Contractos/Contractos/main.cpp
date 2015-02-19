#include <iostream>
#include "Contrato.h"
#include "Ordenamiento.h"

template <typename T>
void imprimeArreglo(T[], int);

int main()
{
	Contrato contratos[3];
	contratos[0] = Contrato(4, 12, 11, 1994);
	contratos[1] = Contrato(3, 12, 9, 1986);
	contratos[2] = Contrato(2, 12, 11, 1994);

	imprimeArreglo<Contrato>(contratos, 3);

	Ordenamiento<Contrato>::seleccion(contratos, 3, [](Contrato a, Contrato b){return a > b; });

	imprimeArreglo<Contrato>(contratos, 3);

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