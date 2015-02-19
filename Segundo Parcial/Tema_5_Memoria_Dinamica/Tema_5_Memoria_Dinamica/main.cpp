#include <iostream>


class Int
{
	int number;
	Int * next = nullptr;

public:
	Int(int n) : number(n){} 
	void setNext(Int * value) { next = value; }
	Int* getNext(){ return next; }

};
int main()
{
	int n = 5;

	int * ptr = &n;

	*ptr = 25;

	std::cout << " n = " << n << std::endl;
	std::cout << "&n = " << &n << std::endl;
	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "&ptr = " << &ptr << std::endl;
	std::cout << "*ptr = " << *ptr << std::endl;

	std::cout << "Entre el numero de elementos" << std::endl;

	int x;

	std::cin >> x;

	int * numeros = new int[x];

	/* (aritmetica de apuntadores)
	int i;
	for (int * p = numeros; p < (numeros + x); ++p)
	{
		*p = i++; 
	}
	*/
	for (int i = 0; i < x; ++i)
	{
		numeros[i] = i; //equivalente a *(numeros + i) = i;
	}

	for (int i = 0; i < x; ++i)
	{
		std::cout << *(numeros + i) << std::endl;
	}
	

	std::cout << "Entre el nuevo numero de elementos" << std::endl;

	std::cin >> x;
	
	numeros = (int *)realloc(numeros, x * sizeof(int));

	for (int i = 0; i < x; ++i)
	{
		std::cout << *(numeros + i) << std::endl;
	}

	delete[] numeros;

	/* Ejemplo de enlazar numeros*/

	Int a(1);
	Int b(2);

	a.setNext(&b);

		 
	return 0;
}