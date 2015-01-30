#include <iostream>

int posibles(int, int , int, int);
int main(int argc, char **argv)
{
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
	
	std::cout << "El numero de caminos es: " << posibles(0, 0, reng, colu);
	
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

int posibles(int ren, int col, int renA, int colA)
{
	if(ren >= renA || col >= colA)
	{
		return 0;
	}
	else if(ren == renA -1 && col == colA - 1)
	{
		return 1;
	}
	else
	{
		return posibles(ren + 2, col, renA, colA) + posibles(ren, col + 3, renA, colA);
	}
}