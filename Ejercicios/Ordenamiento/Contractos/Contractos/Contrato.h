#include <iostream>

class Contrato
{
private:
	int numero;
	int dia;
	int mes;
	int a�o;

public:
	Contrato();
	Contrato(int, int, int, int);
	int getNumero(){ return numero; }
	int getDia(){ return dia; }
	int getMes(){ return mes; }
	int getA�o(){ return a�o; }

	bool operator >(Contrato &);

	friend std::ostream & operator <<(std::ostream &, Contrato &);

};