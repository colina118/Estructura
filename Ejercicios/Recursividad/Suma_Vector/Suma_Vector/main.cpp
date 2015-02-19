#include <iostream>
#include <stdlib.h>

int Suma(int, int [], int);

int main()
{
	static const int a = 3;
	int b[a];
	int suma;
	for (int i = 0; i < a; i++)
	{
		b[i] = rand() % 10;
	}
	for (int c = 0; c < a; c++)
	{
		std::cout << b[c] << std::endl;
	}
	suma = Suma(0, b, a);
	std::cout << "Tu suma es: " << suma << std::endl;

}

int Suma(int b, int a[], int size)
{
	if (b == size -1)
	{
		return a[b];
	}
	else
	{
		return a[b] + Suma((b + 1), a, size);
	}
}