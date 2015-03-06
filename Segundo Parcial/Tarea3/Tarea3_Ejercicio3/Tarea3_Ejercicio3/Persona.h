#include <string>
#include <iostream>

class Persona
{
private:
	std::string nombre;
	std::string apellidos;
	int edad;
	int dia;
	int mes;
	int ano;
public:
	Persona() {}
	Persona(std::string _nombre, std::string _apellidos, int _edad, int _dia, int _mes, int _ano) :
		nombre(_nombre), apellidos(_apellidos), edad(_edad), dia(_dia), mes(_mes), ano(_ano){}
	~Persona() {}

	std::string getNombre() { return nombre; }
	std::string getApellidos() { return apellidos; }
	int getEdad() { return edad; }
	int getDia() { return dia; }
	int getMes() { return mes; }
	int getAnio() { return ano; }

	friend std::ostream & operator << (std::ostream&, Persona);
	bool operator <(Persona);
	bool operator >(Persona);
};