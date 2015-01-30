#include <iostream>
#include <Math.h>

void primera(int **, int, int, int);
template <typename T>
void imprimeArreglo(T **, int, int);


int main(int argc, char **argv)
{
	int reng;
	int colu;
	int ** matriz;
    //srand( (unsigned int) time(nullptr));
	
	std::cout << "Mete el numero de renglones" << std::endl;
	std::cin >> reng;
	std::cout << "Mete el numero de columnas" << std::endl;
	std::cin>> colu;
    
    matriz = new int*[reng];
	 for(int i = 0; i < reng; i++)
    {
        matriz[i] = new int[colu];
    }
	
	primera(matriz, colu, 0, 0);
	
	imprimeArreglo<int>(matriz, reng, colu);
	
	return 0;
}

void primera(int **matriz, int tam, int ren, int col)
{
	if(ren == tam-1 && col == tam-1)
	{
		matriz[ren][col] = pow(2, tam-1);
	}
	else
	{
		if(ren == tam-1)
		{
			matriz[ren][col] = pow(2, col);
			primera(matriz, tam, 0, col + 1);
		}
		else
		{
			if(ren < col)
			{
				matriz[ren][col] = pow(2, ren);
			}
			else
			{
				matriz[ren][col] = pow(2, col);
			}
			primera(matriz, tam, ren+1, col);
		}
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