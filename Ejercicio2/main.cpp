#include <iostream>
#include <cstdlib>
#include "Ej2.h"

template <typename T>
void imprimeArreglo(T **, int, int);

int main(int argc, const char * argv[])
{
    int ren;
	int col;
	int ** matriz;
    //srand( (unsigned int) time(nullptr));
	
	std::cout << "Mete el numero de renglones" << std::endl;
	std::cin >> ren;
	std::cout << "Mete el numero de columnas" << std::endl;
	std::cin>> col;
    
    matriz = new int*[ren];
	 for(int i = 0; i < ren; i++)
    {
        matriz[i] = new int[col];
    }
	
	for (int i = 0; i < ren; ++i)
		for(int j = 0; j < col; j++)
		{
			{
				matriz[i][j] = rand() % 100;
			}
		}
    
    imprimeArreglo<int>(matriz, ren, col);
    
    std::cout << "introduce el valor a buscar";
    
    int valor;
    
    std:: cin >> valor;
    
    
    int *arr = BusquedaGenerica<int>::busquedaSecuencial(matriz, valor, ren, col);
    std::cout << arr[1] << std::endl;
	int a = arr[0];
	int b = arr[1];
    //int existe = BusquedaGenerica<int>::busquedaBinaria(enteros, valor, 0, longitud);

    if (arr[0] != -1)
    {
        std::cout << matriz[a][b] << std::endl;
    }
    else
    {
        std::cout << "El valor no existe dentro del arreglo"  << std::endl;
    }
}  

template <typename T>
void imprimeArreglo(T **v, int ren, int col)
{
    for(int i = 0; i < ren; ++i)
	{
		for(int j = 0; j < col; ++j)
			{
				std::cout << v[i][j] << " ";
			}
			std::cout << std::endl;
		}
}