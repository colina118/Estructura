#include <iostream>

template <class T>
class BusquedaGenerica
{
    public:
        static int* busquedaSecuencial(T **, T, int, int);
        static int busquedaBinaria(T[], T, int, int);
};

template <class T>
int* BusquedaGenerica<T>::busquedaSecuencial(T **v, T valor, int ren, int col)
{
    int *arr = new int[2];
	arr[0] = -1;
	int existe = -1;
    int indice = 0;
	int ind = 0;
    
    if (ren == 0 && col == 0) return arr;
    
    while (existe == -1 && ind < ren && indice < col)
    {
        if(v[ind][indice] == valor)
        {
            existe = ind;
			arr[0] = indice;
			arr[1] = ind;
		}
		while(existe == -1 && ind < ren)
		{
		if (v[ind][indice] == valor)
			{
				existe = ind;
				arr[0]= indice;
				arr[1]= ind;
			}
			++ind;
		}
        ++indice;
		ind = 0;
    }
    return arr;
}

template <class T>
int BusquedaGenerica<T>::busquedaBinaria(T v[], T valor, int inferior, int superior)
{
    if (inferior >= superior)
    {
        return -1;
    }
    else
    {
        int mitad = (inferior + superior) / 2;
        if (v[mitad] == valor)
        {
            return mitad;
        }
        else if(valor < v[mitad])
        {
            return busquedaBinaria(v, valor, inferior, mitad);
        }
        else
        {
            return busquedaBinaria(v, valor, mitad + 1 , superior);
        }
    }
}