#include <iostream>
#include <string>
#include <vector>


void cuadrado(int dimension, int iteraciones, std::vector<std::vector<int>> vec);

int main()
{

	
	
	return 0;
}

void cuadrado(int dimension, int iteraciones, std::vector<std::vector<int>> vec)
{
	if (iteraciones != 0)
	{

		vec[dimension][dimension];
		int centro = dimension / 3;
		vec[centro][centro] = 1;

		cuadrado(dimension * 3, iteraciones - 1, vec);
	}
	for (auto i : vec)
	{
		std::cout << i << std::endl;
	}
}