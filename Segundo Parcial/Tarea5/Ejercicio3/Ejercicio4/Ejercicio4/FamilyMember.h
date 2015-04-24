#include <iostream>
#include <string>

namespace mike
{
	class FamilyMember
	{
		std::string nombre;
		bool alive;
	public:
		FamilyMember() : FamilyMember(){ }
		FamilyMember(std::string _nombre, bool _alive) : nombre(_nombre), alive(_alive){ }
		void setNombre(std::string _nombre){ nombre = _nombre; }
		std::string getNombre(){ return nombre; }
		void setAlive(bool _alive){ alive = _alive; }
		bool getAlive(){ return alive; }

		friend std::ostream & operator <<(std::ostream & os, FamilyMember &);
	};
}