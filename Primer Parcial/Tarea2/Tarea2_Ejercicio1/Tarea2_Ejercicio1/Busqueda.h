#include <iostream>
#include <string>

template <typename T, typename H>
class Busqueda
{
public:
	static int* busquedaSecuencialPosicion(T[], H, int, int*, int&, bool(*)(T, H));
	static int* busquedaSecuencial(T[], H, int, int*, int&, H, bool(*)(T, H, H));

};

template <typename T, typename H>
int* Busqueda<T, H>::busquedaSecuencialPosicion(T v[], H valor, int longitud, int* arreglo, int &posEncontrado, bool checa(T, H))
{
	int indice = 0;
	

	if (longitud <= 0) return arreglo;

	while (indice < longitud) {
		if (checa(v[indice], valor)) {
			 *(arreglo + posEncontrado) = indice;
			 posEncontrado++;
		}
		indice++;
	}

	return arreglo;
}

template <typename T, typename H>
int* Busqueda<T, H>::busquedaSecuencial(T v[], H valor, int longitud, int* arreglo, int &posEncontrado, H value,  bool checa(T, H, H))
{
	int indice = 0;


	if (longitud <= 0) return arreglo;

	while (indice < longitud) {
		if (checa(v[indice], valor, value)) {
			*(arreglo + posEncontrado) = indice;
			posEncontrado++;
		}
		indice++;
	}

	return arreglo;
}