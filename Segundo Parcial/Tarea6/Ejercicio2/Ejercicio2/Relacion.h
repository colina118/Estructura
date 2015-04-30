#ifndef RELACION_H
#define RELACION_H
#include "Persona.h"
#include <iostream>
#include <string>

class Persona;

class Relacion
{
private:
	Persona* uno = nullptr;
	Persona * dos = nullptr;
	int duracion;
public:
	~Relacion();
	Relacion(){}
	Relacion(Persona* _uno, Persona * _dos, int _duracion);

	void setUno(Persona * _uno) { uno = _uno; }
	void setDos(Persona		* _dos) { dos = _dos; }
	void setMeses(int _duracion) { duracion = _duracion; }

	Persona * getUno() { return uno; }
	Persona * getDos() { return dos; }
	int getMeses() { return duracion; }


	friend std::ostream & operator << (std::ostream & os, const Relacion & relacion);

};

#endif // RELACION_H