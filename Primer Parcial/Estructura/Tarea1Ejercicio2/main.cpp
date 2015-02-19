#include <iostream>
#include <cstdlib>
#include <Time.h>

template <typename T>
void imprimeArreglo(T **, int, int);
bool segunda(int **, int, int, int, int);
int main(int argc, char **argv)
{
	srand(time(NULL));
	
	int reng;
	int colu;
	int ** matriz;
    
	
	std::cout << "Mete el numero de renglones" << std::endl;
	std::cin >> reng;
	std::cout << "Mete el numero de columnas" << std::endl;
	std::cin>> colu;
    
    matriz = new int*[reng];
	 for(int i = 0; i < reng; i++)
    {
        matriz[i] = new int[colu];
    }
	
	for (int i = 0; i < reng; ++i)
		for(int j = 0; j < colu; j++)
		{
			{
				matriz[i][j] = rand() % 2;
			}
		}
	imprimeArreglo<int>(matriz, reng, colu);
	bool siSaliste = segunda (matriz, 0, 0, reng, colu);
	
	if(siSaliste)
		std::cout << "llegaste a la salida";
	else
		std::cout << "No hay solucion"; 
	
	return 0;
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

bool segunda(int **matriz, int ren, int col, int renA, int colA)
{
	int valor = matriz[ren][col];
	if(valor == 1 && ren == renA - 1 && col == colA - 1)		
		return true;
	else if(matriz[ren + 1][col] == 1)
		{
			std::cout << "Avanze una casilla hacia abajo" << std::endl;
			if(ren == renA)
				return segunda(matriz, ren, col + 1, renA, colA);
			else
				return segunda(matriz, ren + 1, col, renA, colA);
		}
	else if(matriz[ren][col + 1] == 1)
		{
			std::cout << "Avanze una casilla a la derecha " << std::endl;
			if ( col == colA)
				return segunda(matriz, ren, col, renA, colA);
			else
				return segunda(matriz, ren, col + 1, renA, colA);
		}
		else 
		{
			return false;
		}
}

