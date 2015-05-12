#include <iostream>
#include <vector>
#include <string>
#include "BinaryTree.h"



using namespace vcn;

BinaryTree<char> armaArbol(std::string, std::string);

int main(int argc, const char * argv[]) {

	BinaryTree<char> venga;
	std::string a = "GEAIBMCLDFKJH";
	venga = armaArbol(a, "IABEGLDCFMKHJ");

	venga.preOrder();
	return 0;
}

BinaryTree<char> armaArbol(std::string preOrden, std::string enOrden)
{
	BinaryTree<char> nuevo;
	int pos;
	BNode<char> * root = new BNode<char>(preOrden[0]);

	nuevo.insert(0, root);
	for (int j = 0; j < preOrden.size(); j++)
	{
		for (int i = 0; i < enOrden.size(); i++)
		{
			if (enOrden[i] == preOrden[j])
			{
				pos = i;
			}
			BNode<char> * sig = new BNode<char>(preOrden[j + 1]);
			BNode<char> * sigi = new BNode<char>(preOrden[i + 1]);
			nuevo.insert(root, sig);
			nuevo.insert(root, sigi);
			BNode<char> * root = new BNode<char>(preOrden[j + 1]);
		}
	}
	return nuevo;
}