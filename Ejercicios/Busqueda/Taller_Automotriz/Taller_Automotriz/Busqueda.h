#include <iostream>
#include <string>

template <typename T, typename H>
class Busqueda
{
public:
	static int busquedaSecuencialPosicion(T[], H, int, bool(*)(T, H));
	static int* busquedaSecuencial(T[], H, int, int*, int&, H, bool(*)(T, H, H));
	static int busquedaSecuencialPos(T[], H, int longitud, bool(*) (T, H), int (*)(T));

};

template <typename T, typename H>
int Busqueda<T, H>::busquedaSecuencialPosicion(T v[], H valor, int longitud, bool checa(T, H))
{
	int indice = 0;
	int existe = -1;


	if (longitud <= 0) return existe;

	while (existe == -1 && indice < longitud) {
		if (checa(v[indice++], valor)) {
			existe = indice;
		}
		
	}

	return existe;
}

template <typename T, typename H>
int* Busqueda<T, H>::busquedaSecuencial(T v[], H valor, int longitud, int* arreglo, int &posEncontrado, H value, bool checa(T, H, H))
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

template <typename T, typename H>
int Busqueda<T, H>::busquedaSecuencialPos(T v[], H valor, int longitud, bool checa(T, H), int consigue(T))
{
	int indice = 0;
	int existe = -1;
	


	if (longitud <= 0) return existe;

	while (indice < longitud) {
		if (checa(v[indice], valor)) {
			existe = indice;
			valor = consigue(v[indice]);
		}
		indice++;
	}

	return existe;
}