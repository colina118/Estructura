#include "C:\Users\Miguel\Documents\tec\Cuarto Semestre\Estructura de Datos\Estructura\Segundo Parcial\Tema_6_Estructuras no lineales\Stack\Stack\Stack.h"

int main(int argc, const char * argv[]) {

	/* Usar el namespace */
	using namespace mike;

	/* Definir una pila */
	Stack<int> * pila = new Stack<int>();
	Stack<int> * stack = new Stack<int>();

	/* Insertar elementos en la pila */
	pila->push(1);
	pila->push(2);
	pila->push(3);
	pila->push(4);

	/* Mostrar el contenido de la pila */
	std::cout << *pila << std::endl;

	/* Obtener el elemento que está en top */
	Node<int> * node;

	for (int i = 0; i < 4; i++)
	{
		node = pila->pop();
		stack->push(node);
	}

	std::cout << *stack << std::endl;

	delete pila;

	return 0;
}

