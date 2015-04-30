#include "Contenedor.h"


int main()
{
	std::vector<Producto> a;
	Producto zapatos("zapatos", 700, 2);
	Producto camisa("camisa", 400, 10);
	Producto computadora("computadora", 20000, 15);
	Producto chamarra("chamarra", 900, 7);
	Producto tablets("tablets", 8000, 20);
	a.push_back(computadora);
	a.push_back(tablets);
	std::cout << computadora << std::endl;
	//Contenedor a(;
	return 0;
}