#include <iostream>

int invertir(int);

int main()
{
	int num;
	int inverti;
	std::cout << "Escribe el numero que deseas invertir " << std::endl;
	std::cin >> num;
	inverti = invertir(num);
	std::cout << inverti << std::endl;
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