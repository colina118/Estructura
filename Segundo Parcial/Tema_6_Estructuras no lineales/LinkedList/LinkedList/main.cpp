#include <iostream>
#include <string>
#include "Computadora.h"
#include "LinkedList.h"

int main(int argc, const char * argv[]) {

	using namespace mike;
	
	/*using mike::LinkedList;
	using mike::Computadora;
	using mike::Node;*/

	Node<int> first(1);

	Node<float> second(3.45f);

	Node<std::string> cad("Esto es una cadena");

	Computadora laptop;

	Node<Computadora> pc(laptop);

	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << cad << std::endl;

	std::cout << pc << std::endl;

	LinkedList<int> * numeros = new LinkedList<int>();

	std::cout << "First = " << numeros->first() << std::endl;

	std::cout << "Size = " << numeros->size() << std::endl;
	
	std::cout << "Empty = " << (numeros->empty() ? "true" : "false") << std::endl;

	numeros->insert(1, 0);
	numeros->insert(-1, -2);
	numeros->insert(2, 0);

	Node<int> * newnode = new Node<int>(30);

	numeros->insertBack(newnode);
	


	std::cout << *numeros << std::endl;

	int pos = numeros->size() - 1;
	std::cout << "At(" << pos << ") = " << *(numeros->at(pos)) << std::endl;

	Node<int> * node = numeros->at(0);

	std::cout << "Node esta en posicion " << numeros->at(node) << std::endl;

	Node<int> * removenode = numeros->remove(1);

	std::cout << "Nodo a borrar = " << *removenode << std::endl;
	delete removenode;

	std::cout << *numeros << std::endl;

	delete numeros;
	

	return 0;
}