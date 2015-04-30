#include "Producto.h"
#include <vector>

class Contenedor
{
private:
	int numero;
	std::vector<Producto> lista_productos;
	int precio = 0;

public:
	~Contenedor() {}
	//Contenedor(){ 0, lista_productos, 0; }
	Contenedor(int _numero) : numero(_numero) {}

	void setNumero(int _numero) { numero = _numero; }
	void setLista(std::vector<Producto> _lista_productos) { lista_productos = _lista_productos; }

	int getNumero(){ return numero; }
	std::vector<Producto> getProducto() { return lista_productos; }
	int getTotal();

	void insertaProducto(Producto);

	friend std::ostream & operator <<(std::ostream & os, Contenedor &);


};

int Contenedor::getTotal()
{
	int total = 0;
	for (auto i : lista_productos)
	{
		total += i.getTotal();
	}
	return total;
}

void Contenedor::insertaProducto(Producto producto)
{
	lista_productos.push_back(producto);
}

std::ostream & operator <<(std::ostream & os, Contenedor & contenedor)
{
	os << "Empresa: " << contenedor.numero << std::endl;
	os << "---------------------------------------" << std::endl;
	for (auto i : contenedor.lista_productos)
	{
		os << i << std::endl;
	}
	os << "Total del Contenedor: " << contenedor.getTotal() << std::endl;

	return os;
}