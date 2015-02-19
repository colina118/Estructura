#include "Vehiculo.h"

void Vehiculo::agregaServicio(int num)
{
	servicios[contServicio] = num;
	contServicio++;
	switch (num)
	{
	case 1:
		costo += 300;
		break;
	case 2:
		costo += 500;
		break;
	case 3:
		costo += 670;
		break;
	case 4:
		costo += 1000;
		break;
	default:
		std::cout << "No hay esa opción de servicio" << std::endl;
		break;
	}
}

std::ostream & operator <<(std::ostream & os, Vehiculo & vehiculo)
{
	os << "tu placa es:" << vehiculo.getPlaca() << std::endl << "tu costo de servicios es:  " << vehiculo.getCosto() << std::endl << "Tu numero de servicios es " << vehiculo.getContServicio() << std::endl;

	return os;
}