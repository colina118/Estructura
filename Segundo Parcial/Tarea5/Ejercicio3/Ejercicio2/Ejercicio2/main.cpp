#include <iostream>

#include "BinaryTree.h"



using namespace mike;


int main(int argc, const char * argv[]) {


	
	/* Crear nodos diferentes */
	BNode<int> entero(1);
	std::cout << entero << std::endl;

	BNode<float> flotante(3.14);
	std::cout << flotante << std::endl;

	BNode<char> letra('A');
	std::cout << letra << std::endl;

	/* Crear un árbol binario */
	BinaryTree<int> numeros;
	BinaryTree<int> suma;

	/* Insertar nodos */

	BNode<int> * uno = new BNode<int>(1);
	numeros.insert(nullptr, uno);

	BNode<int> * dos = new BNode<int>(2);
	numeros.insert(uno, dos);

	numeros.insert(nullptr, 0);

	BNode<int> * tres = new BNode<int>(3);
	numeros.insert(uno, tres);

	BNode<int> * cuatro = new BNode<int>(4);
	numeros.insert(dos, cuatro);

	BNode<int> * cinco = new BNode<int>(5);
	numeros.insert(numeros.getRoot(), cinco);

	numeros.insert(numeros.getRoot(), 100);

	//BNode<int> * prueba = new BNode<int>(3);
	bool prueba;

	prueba = numeros.hermanos(dos, cinco);
	if (prueba)
	{
		std::cout << "los valores son hermanos" << std::endl;
	}
	else
	{
		std::cout << "los valores no son hermanos" << std::endl;
	}
	std::cout << *uno << std::endl;

	/* Mostrar el árbol en preOrder */
	std::cout << " ---- preOrder ----" << std::endl;
	numeros.preOrder();
	std::cout << std::endl;

	/* Mostrar el árbol en inOrder */
	std::cout << " ---- inOrder ----" << std::endl;
	numeros.inOrder();
	std::cout << std::endl;

	/* Mostrar el árbol en postOrder */
	std::cout << " ---- postOrder ----" << std::endl;
	numeros.postOrder();
	std::cout << std::endl;

	/* Mostrar los nodos hojas */
	std::cout << " ---- Hojas del árbol ----" << std::endl;
	numeros.isLeaf();
	std::cout << std::endl;

	/* Mostrar los ancestros de un nodo */
	BNode<int> * node = tres;
	std::cout << " ---- Ancestros de " << *node << " ----" << std::endl;
	numeros.ancestors(node);
	std::cout << std::endl;

	numeros.reflexion(numeros.getRoot());

	/* Mostrar el árbol en preOrder */
	std::cout << " ---- preOrder ----" << std::endl;
	numeros.preOrder();
	std::cout << std::endl;



	return 0;
}