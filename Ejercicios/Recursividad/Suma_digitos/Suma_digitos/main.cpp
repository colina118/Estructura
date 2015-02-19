#include <iostream>

int sumaDigito(int);

int main()
{
	int num;
	int suma;
	std::cout << "introduzca el numero que se sumara" << std::endl;
	std::cin >> num;

	suma = sumaDigito(num);
	std::cout << "Tu resultado es: " << suma << std::endl;

	return 0;
}

int sumaDigito(int a)
{
	if (a < 10)
	{
		return a;
	}
	else
	{
		return (a % 10) + sumaDigito(a / 10);
	}
}