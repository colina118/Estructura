#include <iostream>
#include "BinaryTree.h"
#include "FamilyMember.h"

using namespace mike;

int main(int argc, const char * argv[]) {


	/* Crear un árbol binario */
	BinaryTree<FamilyMember> familia;
	BinaryTree<int> suma;

	/* Insertar nodos */
	
	FamilyMember abue("Miguel de la Colina", true);
	FamilyMember papa("Hermenegildo", true);
	FamilyMember nieto("Chicharito", false);
	FamilyMember nieta("Chicharito", false);

	BNode<FamilyMember> * abuelo = new BNode<FamilyMember>(abue);
	BNode<FamilyMember> * pa = new BNode<FamilyMember>(papa);
	BNode<FamilyMember> * nie = new BNode<FamilyMember>(nieto);
	BNode<FamilyMember> * ni = new BNode<FamilyMember>(nieta);

	familia.insert(nullptr, abuelo);
	familia.insert(abuelo, papa);
	familia.insert(pa, nie);
	familia.insert(pa, ni);


	//BNode<int> * prueba = new BNode<int>(3);
	bool prueba;

	prueba = familia.hermanos(nie, ni);
	if (prueba)
	{
		std::cout << "los valores son hermanos" << std::endl;
	}
	else
	{
		std::cout << "los valores no son hermanos" << std::endl;
	}
	

	/* Mostrar el árbol en preOrder */
	std::cout << " ---- preOrder ----" << std::endl;
	familia.preOrder();
	std::cout << std::endl;

	//visualizar descendientes
	familia.preOrder(pa);

	BNode<FamilyMember> * node = nieto;
	std::cout << " ---- Ancestros de " << *node << " ----" << std::endl;
	familia.ancestors(node);
	std::cout << std::endl;

}