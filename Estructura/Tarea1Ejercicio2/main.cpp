#include <iostream>

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
