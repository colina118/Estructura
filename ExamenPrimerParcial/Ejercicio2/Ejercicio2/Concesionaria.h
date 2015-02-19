#include <iostream>
#include <string>


class Concesionaria
{
private:
	int monto;
	std::string tipo;
	std::string comprador;
public:
	Concesionaria() : Concesionaria (0, "", ""){}
	Concesionaria(int m, std::string t, std::string c) : monto(m), tipo(t), comprador(c){}
	int getMonto(){ return monto; }
	std::string getTipo(){ return tipo; }
	std::string getComprador(){ return comprador; }
	

	friend std::ostream & operator <<(std::ostream &, Concesionaria &);

};