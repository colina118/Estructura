#include <iostream>

class Contrato
{
private:
	int numero;
	int dia;
	int mes;
	int año;

public:
	Contrato();
	Contrato(int, int, int, int);
	int getNumero(){ return numero; }
	int getDia(){ return dia; }
	int getMes(){ return mes; }
	int getAño(){ return año; }

	bool operator >(Contrato &);

	friend std::ostream & operator <<(std::ostream &, Contrato &);

};