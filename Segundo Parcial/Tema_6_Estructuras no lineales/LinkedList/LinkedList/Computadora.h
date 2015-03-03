#include <iostream>
#include <string>

namespace mike {

	class Computadora {
		std::string pantalla;
		int ram;
		float frecuencia;
	public:

		Computadora() : Computadora("0x0", 0, 0.0) { }

		Computadora(std::string _pantalla, int _ram, float _frecuencia)
			: pantalla(_pantalla), ram(_ram), frecuencia(_frecuencia)
		{}

		friend std::ostream & operator <<(std::ostream & os, Computadora &);
	};

}