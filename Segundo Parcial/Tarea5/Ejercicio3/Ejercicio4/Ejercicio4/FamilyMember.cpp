#include "FamilyMember.h"

namespace mike{
	std::ostream & operator <<(std::ostream & os, mike::FamilyMember & c)
	{
		os << "Nombre : " << c.nombre << std::endl;
	
		if (c.alive)
		{
			os << "Esta vivo" << std::endl;
		}
		else
		{
			os << "Esta muerto" << std::endl;
		}

		return os;
	}
}