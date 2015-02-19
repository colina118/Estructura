#include <iostream>
#include <string>
#include "Libro.h"
#include "Ordenamiento.h"

template <typename T>
void imprimeArreglo(T[], int);

int main()
{
	static const int nLibros = 5;
	Libro biblioteca[nLibros];

	biblioteca[0] = Libro("Harry Potter", "Jk Rowling", 234, 1994, "Bailando", "Cuarta");
	biblioteca[1] = Libro("Harry P ", "JK rowling", 989, 1998, "Editorial Editores", "quinta");
	biblioteca[2] = Libro("camara ", "camarilla", 854, 2015, "Editorial", "Segunda");
	biblioteca[3] = Libro("Har ", "JK ", 9, 2000, "Editorial Editores", "Tercero");
	biblioteca[4] = Libro("Crepus P ", "Alguien mas", 1254, 1986, "l Editores", "Sexta");

	imprimeArreglo<Libro>(biblioteca, nLibros);

	int opc = 0;

	while (opc != 5)
	{
		std::cout << "1-Ordena por titulo \n2-Ordena por año \n3-Ordena por edicion \n4-Imprime el arreglo \n5-Salir" << std::endl;
		std::cin >> opc;
		
		switch (opc)
		{
		case 1:
		
			opc = 0;
			while (opc != 7)
			{
				std::cout << "1. Ordenar ascendentemente con bubble sort" << std::endl;
				std::cout << "2. Ordenar ascendentemente con insertion sort" << std::endl;
				std::cout << "3. Ordenar ascendentemente con selection sort" << std::endl;
				std::cout << "4. Ordenar descendentemente con bubble sort" << std::endl;
				std::cout << "5. Ordenar descendentemente con insertion sort" << std::endl;
				std::cout << "6. Ordenar descendentemente con selection sort" << std::endl;
				std::cout << "7. Salir del programa" << std::endl;
			std::cin >> opc;
			switch (opc)
			{
			case 1:
			
				Ordenamiento<Libro>::burbuja(biblioteca, nLibros, [](Libro a, Libro b){ return a.getTitulo() > b.getTitulo(); });
				std::cout << "se ha arreglado el arreglo" << std::endl;
				opc = 7;
			
				break;
			case 2:
			
				Ordenamiento<Libro>::burbuja(biblioteca, nLibros, [](Libro a, Libro b){ return a.getTitulo() < b.getTitulo(); });
				std::cout << "se ha arreglado el arreglo" << std::endl;
				opc = 7;
			
				break;
			case 3:
			
				Ordenamiento<Libro>::seleccion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getTitulo() > b.getTitulo(); });
				std::cout << "se ha arreglado el arreglo" << std::endl;
				opc = 7;
			
				break;
			case 4:
			
				Ordenamiento<Libro>::seleccion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getTitulo() < b.getTitulo(); });
				std::cout << "se ha arreglado el arreglo" << std::endl;
				opc = 7;
			
				break;
			case 5:
			
				Ordenamiento<Libro>::insercion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getTitulo() > b.getTitulo(); });
				std::cout << "se ha arreglado el arreglo" << std::endl;
				opc = 7;
			
				break;
			case 6:
				Ordenamiento<Libro>::insercion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getTitulo() < b.getTitulo(); });
				std::cout << "se ha arreglado el arreglo" << std::endl;
				opc = 7;
			case 7:
			

			
				break;
			}
			

		}
			opc = 0; 
			break;
		case 2:
			opc = 0;
			while (opc != 7)
			{
				std::cout << "1. Ordenar ascendentemente con bubble sort" << std::endl;
				std::cout << "2. Ordenar ascendentemente con insertion sort" << std::endl;
				std::cout << "3. Ordenar ascendentemente con selection sort" << std::endl;
				std::cout << "4. Ordenar descendentemente con bubble sort" << std::endl;
				std::cout << "5. Ordenar descendentemente con insertion sort" << std::endl;
				std::cout << "6. Ordenar descendentemente con selection sort" << std::endl;
				std::cout << "7. Salir del programa" << std::endl;
				std::cin >> opc;
				switch (opc)
				{
				case 1:

					Ordenamiento<Libro>::burbuja(biblioteca, nLibros, [](Libro a, Libro b){ return a.getAño() > b.getAño(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;

					break;
				case 2:

					Ordenamiento<Libro>::burbuja(biblioteca, nLibros, [](Libro a, Libro b){ return a.getAño() < b.getAño(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;

					break;
				case 3:

					Ordenamiento<Libro>::seleccion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getAño() > b.getAño(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;

					break;
				case 4:

					Ordenamiento<Libro>::seleccion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getAño() < b.getAño(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;

					break;
				case 5:

					Ordenamiento<Libro>::insercion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getAño() > b.getAño(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;

					break;
				case 6:
					Ordenamiento<Libro>::insercion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getAño() < b.getAño(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;
				case 7:



					break;
				}
			}
			opc = 0;
			break;
		case 3:
			opc = 0;
			while (opc != 7)
			{
				std::cout << "1. Ordenar ascendentemente con bubble sort" << std::endl;
				std::cout << "2. Ordenar ascendentemente con insertion sort" << std::endl;
				std::cout << "3. Ordenar ascendentemente con selection sort" << std::endl;
				std::cout << "4. Ordenar descendentemente con bubble sort" << std::endl;
				std::cout << "5. Ordenar descendentemente con insertion sort" << std::endl;
				std::cout << "6. Ordenar descendentemente con selection sort" << std::endl;
				std::cout << "7. Salir del programa" << std::endl;
				std::cin >> opc;
				switch (opc)
				{
				case 1:

					Ordenamiento<Libro>::burbuja(biblioteca, nLibros, [](Libro a, Libro b){ return a.getEdicion() > b.getEdicion(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;

					break;
				case 2:

					Ordenamiento<Libro>::burbuja(biblioteca, nLibros, [](Libro a, Libro b){ return a.getEdicion() < b.getEdicion(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;

					break;
				case 3:

					Ordenamiento<Libro>::seleccion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getEdicion() > b.getEdicion(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;

					break;
				case 4:

					Ordenamiento<Libro>::seleccion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getEdicion() < b.getEdicion(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;

					break;
				case 5:

					Ordenamiento<Libro>::insercion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getEdicion() > b.getEdicion(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;

					break;
				case 6:
					Ordenamiento<Libro>::insercion(biblioteca, nLibros, [](Libro a, Libro b){ return a.getEdicion() < b.getEdicion(); });
					std::cout << "se ha arreglado el arreglo" << std::endl;
					opc = 7;
				case 7:



					break;
				}
			}
			opc = 0;
			break;
		case 4:
			imprimeArreglo(biblioteca, nLibros);

		}
		
	}

	return 0;
}

template <typename T>
void imprimeArreglo(T v[], int longitud)
{
	for (int i = 0; i < longitud; ++i) {
		std::cout << v[i] << " ";
	}

	std::cout << std::endl;
}