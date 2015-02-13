#include "Libro.h"

Libro::Libro() : Libro(" ", " ", 0, 0, "", "")
{

}

Libro::Libro(std::string t, std::string a, int n, int añ, std::string e, std::string ed) : titulo(t), autor(a), numPaginas(n), año(añ), editorial(e), edicion(ed)
{

}


std::ostream & operator <<(std::ostream & os, Libro & libro)
{
	os << libro.titulo << " "<< libro.autor  << " " << libro.edicion << " " << libro.editorial << " " << libro.numPaginas << " " << libro.año << " " << std::endl;

	return os;
}

bool Libro::operator==(Libro & libro)
{
	return titulo == libro.titulo;
}