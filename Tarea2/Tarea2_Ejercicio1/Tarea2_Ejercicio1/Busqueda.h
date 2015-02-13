#include <iostream>
#include <string>

template <typename T>
class Busqueda
{
public:
	static int* busquedaSecuencialPosicion(T[], T, int, int a[]);

};

template <typename T>
int* Busqueda<T>::busquedaSecuencialPosicion(T v[], T valor, int longitud, int a[])
{
	int existe = -1;
	int indice = 0;
	int cont = 0;

	if (longitud <= 0) return a;

	while (indice < longitud) {
		if (v[indice++] == valor) {
			a[cont] = indice;
			cont++;
		}

	}

	return a;
}