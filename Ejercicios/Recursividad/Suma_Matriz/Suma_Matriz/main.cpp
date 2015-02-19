#include <iostream>
#define a 3
int SumaMatriz(int, int[a][a], int);

int main()
{
	int matriz[a][a];
	int suma;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			matriz[i][j] = rand() % 10;
			std::cout << matriz[i][j] << " ";
		}
		std::cout << std::endl;
	}

	suma = SumaMatriz(0, matriz, 0);
	std::cout << "Tu suma es: " << suma << std::endl;

}

int SumaMatriz(int c, int j[a][a], int r)
{
	if (c == a -1)
	{
		if (r == a - 1)
		{
			return j[c][r];
		}
		else
		{
			return j[c][r] + SumaMatriz(0, j, r + 1);
		}
	}
	else
	{
		return j[c][r] + SumaMatriz((c + 1), j, r);
	}
}
