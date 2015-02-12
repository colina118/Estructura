#include <iostream>
#include "OrdenamientoGenerico.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <ostream>
#include "Persona.h"

typedef bool(*t_orden) (int, int);
typedef void(*t_algoritmo) (int[], int, t_orden);

int main(int argc, const char * argv[]) {

	const int n = 10;

	/* Declarar el arreglo */
	int enteros[n];

	/* Establecer la semilla del generador de números aleatorios */
	srand((unsigned int) time(nullptr));

	/* Inicializar el arreglo con números aleatorios */
	std::generate(enteros, enteros + n, [](){return rand() % 100; });

	/* Mostrar números por pantalla */
	std::copy(enteros, enteros + n, std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;

	/* Ordenar los elementos del arreglo utilizanod un método de la clase */
	// Ordenamiento<int>::insercion(enteros, n, Ordenamiento<int>::desc);
	
	//El usuario selecciona el algoritmo de ordenamiento

	std::cout << "Algoritmo de ordenamiento" << std::endl;
	std::cout << "1-Burbuja \n2-Seleccion \n3-Insercion" << std::endl;
	std::cout << "seleccione el algoritmo" << std::endl;

	int algoritmo;

	std::cin >> algoritmo;

	std::cout << "Orden: " << std::endl;
	std::cout << "1-Ascendente\n2-Descendente\n" << std::endl;
	std::cout << "seleccione el orden";

	int orden;

	std::cin >> orden;

	//Definir arreglo de funciones

	t_orden ordenes[2];
	ordenes[0] = Ordenamiento<int>::asc;
	ordenes[1] = Ordenamiento<int>::desc;

	t_algoritmo algoritmos[3];
	algoritmos[0] = Ordenamiento<int>::burbuja;
	algoritmos[1] = Ordenamiento<int>::seleccion;
	algoritmos[2] = Ordenamiento<int>::insercion;


		
	/* Ordenar los elementos del arreglo utilizando una función lambda */
	//Ordenamiento<int>::insercion(enteros, n, [](int a, int b){ return a > b; });
	algoritmos[algoritmo - 1](enteros, n, ordenes[orden - 1]);

	/* Mostrar números ordenados por pantalla */
	std::copy(enteros, enteros + n, std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;

	/* Ordenar personas */

	const int n_personas = 3;

	/* Declarar e incializar el arreglo de personas */
	Persona personas[n_personas];

	personas[0] = Persona("Maria", "Perez", 21);
	personas[1] = Persona("Juana", "Bacallao", 18);
	personas[2] = Persona("Luisa", "Perez", 28);

	/* Mostrar personas por pantalla utilizando */
	for (auto p : personas)
	{
		std::cout << p;
	}

	/* Ordenar el arreglo de personas utilizando la clase genérica */
	Ordenamiento<Persona>::seleccion(personas, n_personas, Ordenamiento<Persona>::desc);

	/* Mostrar personas por pantalla utilizando */
	for (auto p : personas)
	{
		std::cout << p;
	}

	return 0;
}