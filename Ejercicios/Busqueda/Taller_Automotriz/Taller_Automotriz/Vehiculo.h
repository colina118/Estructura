#include <iostream>

class Vehiculo
{
private:
	int placa;
	int servicios[5];
	int costo = 0;
	int contServicio = 0;
public:
	Vehiculo() : Vehiculo(0, 0, 0){}
	Vehiculo(int p, int c, int cont) : placa( p), costo(c), contServicio(cont) {}
	int getPlaca(){ return placa; }
	//int getServicio(){ return servicos[]; }
	int getCosto(){ return costo; }
	int getContServicio(){ return contServicio; }

	void agregaServicio(int);

	friend std::ostream & operator <<(std::ostream &, Vehiculo &);

};