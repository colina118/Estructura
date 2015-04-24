#include "BNode.h"
#include "C:\Users\Miguel\Documents\tec\Cuarto Semestre\Estructura de Datos\Estructura\Segundo Parcial\Tema_6_Estructuras lineales\LinkedList\LinkedList\LinkedList.h"

namespace mike {

	template <class T>
	class BinaryTree {
	private:
		BNode<T> * root = nullptr;
		int acum;


	public:
		BinaryTree() {}
		virtual ~BinaryTree();

		bool empty();

		void clear();
		void clear(BNode<T> * node);

		BNode<T> * getRoot() const;
		void setRoot(BNode<T> * node);

		bool insert(BNode<T> * parent, T value);
		bool insert(BNode<T> * parent, BNode<T> * value);

		void preOrder() const;
		void preOrder(BNode<T> * node) const;

		void inOrder() const;
		void inOrder(BNode<T> * node) const;

		void postOrder() const;
		void postOrder(BNode<T> * node) const;

		void isLeaf() const;
		void isLeaf(BNode<T> * node) const;

		void ancestors(BNode<T> * node) const;

		bool hermanos(BNode<T> * nodeB, BNode<T> * nodeA);

		void primos(BNode<T> * node);

		LinkedList<T>* agregaPre(BNode<T> * node, LinkedList<T> * a);
		LinkedList<T>* agregaPre2(BNode<T> * node, LinkedList<T> * a);
		bool simetria(BNode<T> * node);



	};

	template <class T>
	BinaryTree<T>::~BinaryTree()
	{
		clear();
	}

	template <class T>
	bool BinaryTree<T>::empty()
	{
		return root == nullptr;
	}

	template <class T>
	void BinaryTree<T>::clear()
	{
		clear(root);
	}

	template <class T>
	void BinaryTree<T>::clear(BNode<T> * node)
	{
		if (node) {
			clear(node->getLeft());
			clear(node->getRight());

			delete node;
		}
	}

	template <class T>
	BNode<T> * BinaryTree<T>::getRoot() const
	{
		return root;
	}

	template <class T>
	void BinaryTree<T>::setRoot(BNode<T> * node)
	{
		if (!empty()) {
			node->setLeft(root);
			root->setParent(node);
			root = node;
		}
		else {
			root = node;
		}
	}

	template <class T>
	bool BinaryTree<T>::insert(BNode<T> * parent, T value)
	{
		BNode<T> * node = new BNode<T>(value);
		bool inserted = insert(parent, node);

		if (!inserted) delete node;

		return inserted;
	}

	template <class T>
	bool BinaryTree<T>::insert(BNode<T> * parent, BNode<T> * value)
	{
		bool inserted = false;

		if (empty() || !parent) {
			setRoot(value);
			inserted = true;
		}
		else {
			if (!parent->getLeft()) {
				parent->setLeft(value);
				value->setParent(parent);
				inserted = true;
			}
			else if (!parent->getRight()) {
				parent->setRight(value);
				value->setParent(parent);
				inserted = true;
			}
		}

		return inserted;
	}

	template <class T>
	void BinaryTree<T>::preOrder() const
	{
		preOrder(root);
	}

	template <class T>
	void BinaryTree<T>::preOrder(BNode<T> * node) const
	{
		if (node) {
			/* Procesar el nodo */
			std::cout << *node << std::endl;

			/* Invocar a los hijos */
			preOrder(node->getLeft());
			preOrder(node->getRight());
			

		}
	}

	template <class T>
	void BinaryTree<T>::inOrder() const
	{
		inOrder(root);
	}

	template <class T>
	void BinaryTree<T>::inOrder(BNode<T> * node) const
	{
		if (node) {

			/* Invocar al hijo izquierdo */
			inOrder(node->getLeft());

			/* Procesar el nodo */
			std::cout << *node << std::endl;

			/* Invocar al hijo derecho */
			inOrder(node->getRight());
		}
	}

	template <class T>
	void BinaryTree<T>::postOrder() const
	{
		postOrder(root);
	}

	template <class T>
	void BinaryTree<T>::postOrder(BNode<T> * node) const
	{
		if (node) {
			/* Invocar a los hijos */
			postOrder(node->getLeft());
			postOrder(node->getRight());

			/* Procesar el nodo */
			std::cout << *node << std::endl;
		}
	}

	template <class T>
	void BinaryTree<T>::isLeaf() const
	{
		isLeaf(root);
	}

	template <class T>
	void BinaryTree<T>::isLeaf(BNode<T> * node) const
	{
		if (node) {
			if (!node->getLeft() && !node->getRight()) {
				std::cout << *node << std::endl;
			}
			else {
				isLeaf(node->getLeft());
				isLeaf(node->getRight());
			}
		}
	}

	template <class T>
	void BinaryTree<T>::ancestors(BNode<T> * node) const
	{
		if (node) {
			std::cout << *node << " -> ";
			ancestors(node->getParent());
		}
	}

	template <class T>
	bool BinaryTree<T>::hermanos(BNode<T> * nodeB, BNode<T> * nodeA)
	{
		BNode<T> * guarda;
		BNode<T> * guard;
		guarda = nodeB->getParent();
		guard = nodeA->getParent();
		if (guarda == guard)
		{
			return true;
		}
		return false;
	}

	template <class T>
	void BinaryTree<T>::primos(BNode<T> * node)
	{
		if (node->getParent()->getParent())
		{

		}
	}

	template <class T>
	LinkedList<T>* BinaryTree<T>::agregaPre(BNode<T> * node, LinkedList<T> * a)
	{
		if (node) {
			/* Procesar el nodo */
			a->insert(node->getInfo(), 0);

			/* Invocar a los hijos */
			agregaPre(node->getLeft(), a);
			agregaPre(node->getRight(), a);
		}
		return a;
	}

	template <class T>
	LinkedList<T>* BinaryTree<T>::agregaPre2(BNode<T> * node, LinkedList<T> * a)
	{
		if (node) {
			/* Procesar el nodo */
			a->insert(node->getInfo(), 0);

			/* Invocar a los hijos */
			agregaPre2(node->getRight(), a);
			agregaPre2(node->getLeft(), a);
		}
		return a;
	}

	template <class T>
	bool BinaryTree<T>::simetria(BNode<T> * node)
	{
		int j;
		LinkedList<int> * a = new LinkedList<int>;
		LinkedList<int> * b = new LinkedList<int>;

		a = agregaPre(node->getLeft(), a);
		b = agregaPre2(node->getRight(), b);

		std::cout << *a << std::endl;
		std::cout << *b << std::endl;

		if (a->size() == b->size())
		{
			for (int i = 0; i < a->size(); i++)
			{
				if (a->at(i)->getInfo() == b->at(i)->getInfo())
				{
					j = 0;
				}
				else
				{
					j = -1;
					i = a->size();
				}
			}
		}
		else
		{
			return false;
		}
		if (j == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


}