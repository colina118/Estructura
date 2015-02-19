#include "Libro.h"

Libro::Libro() : Libro(" ", " ", 0, 0, "", "")
{

}

Libro::Libro(std::string t, std::string a, int n, int a�, std::string e, std::string ed) : titulo(t), autor(a), numPaginas(n), a�o(a�), editorial(e), edicion(ed)
{

}


std::ostream & operator <<(std::ostream & os, Libro & libro)
{
	os << libro.titulo << " "<< libro.autor  << " " << libro.edicion << " " << libro.editorial << " " << libro.numPaginas << " " << libro.a�o << " " << std::endl;

	return os;
}

bool Libro::operator==(Libro & libro)
{
	return titulo == libro.titulo;
}