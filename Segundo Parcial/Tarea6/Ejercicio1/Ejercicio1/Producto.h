#include <iostream>
#include <string>

class Producto
{
private:
	std::string nombre;
	int precio;
	int cantidad;
public:
	~Producto() {}
	Producto(): Producto("", 0, 0) {}
	Producto(std::string _nombre, int _precio, int _cantidad) : nombre(_nombre), precio(_precio), cantidad(_cantidad) {}

	void setNombre(std::string _nombre) { nombre = _nombre; }
	void setPrecio(int _precio) { precio = _precio; }
	void setCantidad(int _cantidad) { cantidad = _cantidad; }

	std::string getNombre(){ return nombre; }
	int getPrecio(){ return precio; }
	int getCantidad(){ return cantidad; }
	int getTotal(){ return precio * cantidad; }

	friend std::ostream & operator <<(std::ostream & os, Producto &);
};

std::ostream & operator <<(std::ostream & os, Producto & producto)
{
	os << producto.nombre << "  " << producto.cantidad << "  " << producto.precio << "  " << std::endl;
	return os;
}	