#include <iostream>

int MCD(int, int);

int main()
{
	int a;
	int b;
	int maximo;
	std::cout << "introduzca el primer digito" << std::endl;
	std::cin >> a;
	std::cout << "Introduzca el segundo digito" << std::endl;
	std::cin >> b;
	maximo = MCD(a, b);
	std::cout << "El MCD es: " << maximo << std::endl;
}

int MCD(int m, int n)
{
	int r;
		r = m % n;

	if (r == 0)
	{
		return n;
	}
	else
	{
		return MCD(n, r);
	}
}

