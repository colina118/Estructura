#include "Stack.h"
#include <iostream>

int main()
{
	using namespace mike;
	Stack<int> * pila = new Stack<int>();

	pila->push(1);
	pila->push(2);
	pila->push(3);
	pila->push(4);

	std::cout << *pila << std::endl;

	delete pila;

	return 0;
}