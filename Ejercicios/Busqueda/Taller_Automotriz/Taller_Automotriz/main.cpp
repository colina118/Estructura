#include <iostream>
#include "Vehiculo.h"
#include "Busqueda.h"

template <typename T>
void imprimeArreglo(T[], int);

int main()
{
	int posEncontrado = 0;
	int plac;
	Vehiculo coches[5];
	int posi;
	int pos;
	coches[0] = Vehiculo(123, 0, 0);
	coches[1] = Vehiculo(234, 0, 0);
	coches[2] = Vehiculo(345, 0, 0);
	imprimeArreglo<Vehiculo>(coches, 5);

	coches[0].agregaServicio(2);
	coches[0].agregaServicio(3);
	coches[1].agregaServicio(4);
	imprimeArreglo<Vehiculo>(coches, 5);

	std::cout << "Escribe el numero de placa" << std::endl;
	std::cin >> plac;

	posi = Busqueda<Vehiculo, int>::busquedaSecuencialPosicion(coches, plac, 5, [](Vehiculo a, int b){ return a.getPlaca() == b; });
	if (posi == -1)
	{
		std::cout << "Ese auto no existe" << std::endl;
	}
	else
	{
		std::cout << coches[posi-1] << std::endl;
	}

	pos = Busqueda<Vehiculo, int>::busquedaSecuencialPos(coches, 0, 5, [](Vehiculo a, int b){return a.getContServicio() > b; }, [](Vehiculo c){return c.getContServicio(); });
	if (pos != -1)
	{
		std::cout << "Tu coche con mayor num de servicios es: " << std::endl;
		std::cout << coches[pos] << std::endl;
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