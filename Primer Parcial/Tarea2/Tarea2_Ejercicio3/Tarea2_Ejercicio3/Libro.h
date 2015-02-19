#include <iostream>
#include <string>

class Libro
{
private:
	std::string titulo;
	std::string autor;
	int numPaginas;
	int año;
	std::string editorial;
	std::string edicion;

public:
	Libro();
	Libro(std::string, std::string, int, int, std::string, std::string);
	void setTitulo(std::string _titulo){ titulo = _titulo; }
	std::string getTitulo(){ return titulo; }
	void setAutor(std::string _autor) { autor = _autor; }
	std::string getAutor(){ return autor; }
	void setNumPaginas(int _numPaginas){ numPaginas = _numPaginas; }
	int getNumPaginas(){ return numPaginas; }
	void setAño(int _año){ año = _año; }
	int getAño(){ return año; }
	void setEditorial(std::string _editorial){ editorial = _editorial; }
	std::string getEditorial(){ return editorial; }
	void setEdicion(std::string _edicion){ edicion = edicion; }
	std::string getEdicion(){ return edicion; }

	bool operator == (Libro &);
	bool operator != (Libro &);
	bool operator > (Libro &);


	friend std::ostream & operator <<(std::ostream &, Libro &);
};
