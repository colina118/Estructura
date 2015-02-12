#include <iostream>
#include <string>
#include <ostream>

class Persona {
private:
	std::string nombre;
	std::string apellidos;
	int edad;

public:
	Persona() : Persona("", "", 0) {}
	Persona(std::string _nombre, std::string _apellidos, int _edad) : nombre(_nombre), apellidos(_apellidos), edad(_edad) {}

	bool operator >(Persona & persona);
	bool operator <(Persona & persona);
	friend std::ostream & operator << (std::ostream & os, Persona & persona);

};