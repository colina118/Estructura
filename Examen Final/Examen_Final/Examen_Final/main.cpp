#include <iostream>
#include "Graph.h"

int main(int argc, const char * argv[]) {

	Graph<char, int> mapa("Gu�a Roji");

	/* Crear v�rtices */
	Vertex<char, int> * A = new Vertex<char, int>('A');
	Vertex<char, int> * B = new Vertex<char, int>('B');
	Vertex<char, int> * C = new Vertex<char, int>('C');
	Vertex<char, int> * D = new Vertex<char, int>('D');
	Vertex<char, int> * E = new Vertex<char, int>('E');

	/* Adicionar v�rtices al grafo */
	mapa.addVertex(A);
	mapa.addVertex(B);
	mapa.addVertex(C);
	mapa.addVertex(D);
	mapa.addVertex(E);

	/* Adicionar aristas */
	mapa.addEdge(A, B, 30);
	mapa.addEdge(A, E, 100);
	mapa.addEdge(B, A, 50);
	mapa.addEdge(B, D, 75);
	mapa.addEdge(C, D, 20);
	mapa.addEdge(D, B, 60);
	mapa.addEdge(E, C, 15);

	/* Eliminar una arista */;
	mapa.removeEdge(A, B, 30);

	/* Mostrar el grafo */
	std::cout << mapa << std::endl;

	return 0;
}