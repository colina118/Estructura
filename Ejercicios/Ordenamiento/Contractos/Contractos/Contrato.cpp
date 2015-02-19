#include "Contrato.h"

Contrato::Contrato() : Contrato(0, 0, 0, 0)
{

}

Contrato::Contrato(int num, int d, int m, int a) : numero(num), dia(d), mes(m), a�o(a)
{

}

bool Contrato::operator > (Contrato & Contrato)
{
	if (a�o == Contrato.getA�o())
	{
		if (mes == Contrato.getMes())
		{
			if (dia == Contrato.getDia())
			{
				if (numero > Contrato.getNumero())
				{
					return true;
				}
			}
			else
			{
				if (dia > Contrato.getDia())
				{
					return true;
				}
			}
		}
		else
		{
			if (mes > Contrato.getMes())
			{
				return true;
			}
		}
	}
	else
	{
		if (a�o > Contrato.getA�o())
		{
			return true;
		}
	}
}

std::ostream & operator <<(std::ostream & os, Contrato & contrato)
{
	os << contrato.getNumero() << " " << contrato.getDia() << " " << contrato.getMes() << " " << contrato.getA�o() << " "  << std::endl;

	return os;
}