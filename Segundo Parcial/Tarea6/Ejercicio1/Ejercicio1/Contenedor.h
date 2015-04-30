#include "Producto.h"
#include <vector>

class Contenedor
{
private:
	int numero;
	std::vector<Producto *> lista_productos;
	int precio = 0;

public:
	~Contenedor();
	//Contenedor(){ 0, lista_productos, 0; }
	Contenedor(int _numero, std::vector<Producto*> _lista_productos) : numero(_numero), lista_productos(_lista_productos) {}

	void setNumero(int _numero) { numero = _numero; }
	void setLista(std::vector<Producto*> _lista_productos) { lista_productos = _lista_productos; }

	int getNumero(){ return numero; }
	std::vector<Producto*> getProducto() { return lista_productos; }

	void insertaProducto(Producto*);


};

Contenedor::~Contenedor()
{
	lista_productos.clear();
}

void Contenedor::insertaProducto(Producto* producto)
{
	lista_productos.push_back(producto);
	precio += (producto->getCantidad() * producto->getPrecio());
}