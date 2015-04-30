#include "Persona.h"

Persona::~Persona()
{
	for (auto &i : relaciones)
	{
		i = nullptr;
	}
}

float Persona::promedio()
{
	if (relaciones.size() == 0)
	{
		return -1;
	}
	else
	{
		int sum = 0;
		for (auto i : relaciones)
		{
			sum += i->getMeses();
		}
		float avg;
		avg = sum / relaciones.size();
		return avg;
	}
}

void Persona::porcentaje() const
{
	int mes = 0;
	for (auto i : relaciones)
	{
		mes += i->getMeses();
	}
	float a = static_cast<float>(mes);
	float b = static_cast<float>(edad);
	float pct = a / (b * 12);
	std::cout << "Porcentaje relacion: " << pct * 100 <<  "%" << std::endl;
	std::cout << "Porcentaje sin relacion : " << (1 - pct) * 100 << "%" <<  std::endl;
}

void Persona::agregaRelacion(Relacion * relacion)
{
	relaciones.push_back(relacion);
}

bool Persona::operator == (Persona & persona)
{
	return nombre == persona.getNombre() && apellido == persona.getApellido() && edad == persona.getEdad();
}

std::ostream & operator << (std::ostream & os, const Persona & persona)
{
	os << "Nombre: " << persona.nombre << std::endl;
	os << "Apellido: " << persona.apellido << std::endl;
	os << "Edad (anios): " << persona.edad << std::endl;
	os << "Edad (meses): " << persona.edad * 12 << std::endl;
	os << "Relaciones: " << persona.relaciones.size() << std::endl;
	persona.porcentaje();
	return os;
}