#include "Relacion.h"
#include "Persona.h"

Relacion::~Relacion()
{
	uno = nullptr;
	dos = nullptr;
}

 Relacion::Relacion(Persona * _uno, Persona * _dos, int _duracion)
{
	uno = _uno;
	dos = _dos;
	duracion = _duracion;

	uno->agregaRelacion(this);
	dos->agregaRelacion(this);


}

std::ostream & operator << (std::ostream & os, const Relacion & relacion)
{
	os << "Duro: " << relacion.duracion << "meses." << std::endl;
	os << *relacion.uno << std::endl;
	os << "---------- con -----------" << std::endl;
	os << *relacion.dos << std::endl;
	return os;
}


