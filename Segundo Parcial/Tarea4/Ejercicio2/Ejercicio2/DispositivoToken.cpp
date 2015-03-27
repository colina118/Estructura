#include "DispositivoToken.h"

namespace mike{
	std::ostream & operator <<(std::ostream & os, mike::DispositivoToken & c)
	{
		os << "Ip : " << c.ip << std::endl;
		os << "modelo : " << c.modelo << std::endl;
		os << "numero : " << c.numero << std::endl;

		return os;
	}

	bool DispositivoToken::operator !=(DispositivoToken & dispo)
	{
		return !(*this == dispo);
	}

	bool DispositivoToken::operator ==(DispositivoToken & dispo)
	{
		return ip == dispo.ip;
	}
}