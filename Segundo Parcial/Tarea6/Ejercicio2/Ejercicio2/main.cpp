#include <iostream>
#include "Persona.h"
#include "Relacion.h"
#include <map>
#include <vector>
using namespace std;
void agregaPersona(std::string nombre, std::string apellido, int edad, vector<Persona *> & individuos);
void agregaRelacion(int pos1, int pos2, int meses, vector<Persona *> & individuos, vector<Relacion *> & relaciones);

int main(int argc, char **argv)
{
	vector<Relacion *> relaciones;
	vector<Persona *> individuos;

	/* Crear individuos */
	agregaPersona("Santiago", "Rodriguez", 20, individuos);
	agregaPersona("Emilio", "Ferreira", 21, individuos);
	agregaPersona("Jeronimo", "Escalante", 22, individuos);
	agregaPersona("Santiago", "Andrade", 23, individuos);
	agregaPersona("Ximena", "Rodriguez", 18, individuos);
	agregaPersona("Pitbull", "Puerta", 19, individuos);
	agregaPersona("Ke$ha", "Techo", 22, individuos);
	agregaPersona("Sergio", "Piso", 21, individuos);

	/* Crear relaciones */
	agregaRelacion(0, 4, 4, individuos, relaciones);
	agregaRelacion(2, 3, 12, individuos, relaciones);
	agregaRelacion(4, 5, 12, individuos, relaciones);
	agregaRelacion(1, 5, 12, individuos, relaciones);
	agregaRelacion(2, 5, 12, individuos, relaciones);

	/* Imprimir relaciones */
	for (auto i : relaciones)
	{
		cout << *i;
	}

	/* Encontrar Persona con mayor numero de relaciones */
	Persona * max = individuos[0];

	for (auto p : individuos)
	{
		if (p->getRelaciones()->size() > max->getRelaciones()->size())
		{
			max = p;
		}
	}

	std::cout << "Persona con mas relaciones: " << std::endl;
	std::cout << *max << std::endl;

	/* Encontar individuos que no han tenido relaciones */
	std::cout << "individuos sin relaciones" << std::endl;

	for (auto i : individuos)
	{
		if (i->getRelaciones()->size() == 0)
		{
			std::cout << *i << std::endl;
		}
	}

	/* Encontrar Persona más estable en sus relaciones */
	max = individuos[0];
	for (auto p : individuos)
	{
		if (p->promedio() > max->promedio())
		{
			max = p;
		}
	}
	std::cout << "Persona mas estable: " << std::endl;
	std::cout << *max;
	std::cout << "Promedio de relacion: " << max->promedio() << " meses" << std::endl << std::endl;

	/* Liberar memoria */
	for (auto i : relaciones)
	{
		i->setUno(nullptr);
		i->setDos(nullptr);
		delete i;
	}

	for (auto j : individuos)
	{
		delete j;
	}
	return 0;
}

void agregaPersona(std::string nombre, std::string apellido, int edad, vector<Persona *> & individuos)
{
	Persona * tmp = new Persona(nombre, apellido, edad);
	individuos.push_back(tmp);
}

void agregaRelacion(int pos1, int pos2, int meses, vector<Persona *> & individuos, vector<Relacion *> & relaciones)
{
	Relacion * tmp = new Relacion(individuos[pos1], individuos[pos2], meses);
	relaciones.push_back(tmp);
}