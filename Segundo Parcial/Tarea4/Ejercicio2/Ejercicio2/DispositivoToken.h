#include <iostream>
#include <string>

namespace mike{

	class DispositivoToken
	{
		std::string ip;
		std::string modelo;
		int numero;
	public:
		DispositivoToken();
		DispositivoToken(std::string _ip, std::string _modelo, int _numero)
			: ip(_ip), modelo(_modelo), numero(_numero)
		{}

		friend std::ostream & operator <<(std::ostream & os, DispositivoToken &);

		bool operator != (DispositivoToken & dispo);
		bool operator == (DispositivoToken & dispo);
	};
}