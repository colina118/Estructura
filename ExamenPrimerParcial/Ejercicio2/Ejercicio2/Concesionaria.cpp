#include "Concesionaria.h"

std::ostream & operator <<(std::ostream & os, Concesionaria & concesionaria)
{
	os << "El monto es:" << concesionaria.getMonto() << std::endl << "El tipo es: " << concesionaria.getTipo() << std::endl << "El comprador es " << concesionaria.getComprador() << std::endl;

	return os;
}