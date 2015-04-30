#include "Contenedor.h"
#include <stack>

const int max_lugar = 5;
const int max_contenedor = 5;

bool insertProducto(int lugar, int contenedor, std::vector<std::stack<Contenedor>> & empresa, Producto producto);
bool insertContenedor(int contenedor, std::vector<std::stack<Contenedor>> & empresa, Contenedor container);
void show(std::vector<std::stack<Contenedor>> & empresa);

int main()
{
	std::vector<Producto> electronicos;
	std::vector<Producto> ropa;
	Contenedor b(1);
	Contenedor c(2);
	std::vector<std::stack<Contenedor>> empresa(max_lugar);
	Producto zapatos("zapatos", 700, 2);
	Producto camisa("camisa", 400, 10);
	Producto computadora("computadora", 20000, 15);
	Producto chamarra("chamarra", 900, 7);
	Producto tablets("ipad", 8000, 20);

	insertContenedor(0, empresa, b);
	insertContenedor(1, empresa, c);
	
	insertProducto(0, 0, empresa, computadora);
	insertProducto(0, 0, empresa, Producto("ipod", 3000, 50));
	insertProducto(0, 0, empresa, tablets);
	insertProducto(1, 0, empresa, zapatos);
	insertProducto(1, 0, empresa, camisa);
	insertProducto(1, 0, empresa, chamarra);
	insertProducto(0, 1, empresa, Producto("playstation 4", 7000, 10));
	insertProducto(0, 1, empresa, Producto("xbox one", 6900, 3));


	show(empresa);
	
	


	return 0;
}

bool insertProducto(int lugar, int contenedor, std::vector<std::stack<Contenedor>> & empresa, Producto producto)
{
	if (lugar >= max_lugar || lugar < 0 || contenedor >= max_contenedor || contenedor < 0)
	{
		return false;
	}
	else if (empresa[lugar].size() <= contenedor)
	{
		return false;
	}
	else
	{
		std::stack<Contenedor> aux;
		for (int i = 0; i < contenedor; ++i)
		{
			aux.push(empresa[lugar].top());
			empresa[lugar].pop();
		}
		empresa[lugar].top().insertaProducto(producto);
		while (!aux.empty())
		{
			empresa[lugar].push(aux.top());
			aux.pop();
		}
		return true;
	}
}

bool insertContenedor(int contenedor, std::vector<std::stack<Contenedor>> & empresa, Contenedor container)
{
	if (contenedor >= max_contenedor || contenedor < 0 || empresa[contenedor].size() >= max_contenedor)
	{
		return false;
	}
	else
	{
		empresa[contenedor].push(container);
		return true;
	}
}

void show(std::vector<std::stack<Contenedor>> & empresa)
{
	int total = 0;
	int num_pila = 0;

	for (auto i : empresa)
	{
		while (!i.empty())
		{
			std::cout << i.top() << std::endl;
			total += i.top().getTotal();
			i.pop();
		}
		++num_pila;
	}
	std::cout << "Total de almacen: " << total << std::endl;

}