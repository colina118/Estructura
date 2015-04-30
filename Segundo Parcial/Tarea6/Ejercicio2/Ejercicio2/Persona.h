#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>
#include "Relacion.h"
#include <vector>

class Relacion;

class Persona
{
private:
	std::string nombre;
	std::string apellido;
	int edad;
	std::vector<Relacion *> relaciones;

public:
	Persona() : Persona(" ", " ", 0) {}
	Persona(std::string _nombre, std::string _apellido, int _edad) : nombre(_nombre), apellido(_apellido), edad(_edad) {}
	~Persona();

	std::string getNombre() { return nombre; }
	std::string getApellido() { return apellido; }
	unsigned int getEdad() { return edad; }
	std::vector<Relacion *> * getRelaciones() { return &relaciones; }

	void agregaRelacion(Relacion * relacion);
	void setNombre(std::string _nombre) { nombre = _nombre; }
	void setApellido(std::string _apellido) { apellido = _apellido; }
	void setEdad(unsigned int _edad) { edad = _edad; }

	float promedio();
	void porcentaje() const;

	bool operator == (Persona & persona);
	friend std::ostream & operator << (std::ostream & os, const Persona & persona);
};

#endif // PERSONA_H