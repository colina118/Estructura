#include <iostream>

int convertir(int);
int invertir(int);
int letras(int);

int main()
{
	int conv;
	int fin;
	conv = convertir(65029);
	fin = invertir(conv);
	std::cout << fin << std::endl;

	return 0;
}

int convertir(int num)
{
	int t = 1;
	while (num / (t * 10))
	{
		t *= 10;
	}

	if (num < 16)
	{
		return num;
	}
	else
	{
		if (num > 10)
		return ((num % 16) * t) + convertir(num / 16);
	}
}



int invertir(int a)
{
	int t = 1;
	while (a / (t * 10))
	{
		t *= 10;
	}

	if (a < 10)
	{
		return a;
	}
	else
	{
		return ((a % 10) * t) + invertir(a / 10);
	}
}