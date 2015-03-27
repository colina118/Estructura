#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "ListaDEC.h"

std::string temp;


void menu();
std::string abrir();
void loadFile(std::fstream &file, ListaDEC<ListaDEC<std::string> *> &texto);
void inserta();
void insertaPala();
void borraLinea();
void borraPal();
void guarda(std::string);
void irAlPrincipio();
void irAlFinal();

ListaDEC<std::string>* getLines(std::string ruta, int line);
ListaDEC<std::string> * insertaPal(std::string linea);
void imprimir(ListaDEC<ListaDEC<std::string> *> & texto);

ListaDEC<ListaDEC<std::string>*>  archivo;

int lineas;
std::fstream doc;
std::string nombre = "No hay nombre";
std::string abre;
int x = 0;
int y = 0;
int main(int argc, const char * argv[]) {


	menu();

	/*ListaDEC<ListaDEC<std::string>*> archivos;
	ListaDEC<std::string> * palabras = new ListaDEC<std::string>();

	palabras->insertAt("Hola", 0);
	palabras->insertAt("Santi", 0);

	archivos.insertAt(palabras, 0);

	for (int i = 0; i < 1; i++)
	{
	std::cout << *archivos.At(i) << std::endl;
	}
	//std::cout << *archivos << std::endl;
	//std::cout << *palabras << std::endl;

	delete palabras;*/



	return 0;
}


void menu()
{
	int opcion = -10;
	while (opcion != 0)
	{
		std::cout << "Bienvenido" << std::endl;
		std::cout << "Elija una opción" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Abrir algun archivo o escribir el nombre del archivo nuevo" << std::endl;
		std::cout << "2. Añadir una linea" << std::endl;
		std::cout << "3. Añadir una palabra" << std::endl;
		std::cout << "4. Borrar la ultima linea" << std::endl;
		std::cout << "5. Borrar la ultima palabra" << std::endl;
		std::cout << "6. Ir al inicio de una linea" << std::endl;
		std::cout << "7. Ir al final de una linea" << std::endl;
		std::cout << "8. Imprimir lo que hay en el documento" << std::endl;
		std::cout << "9. Guardar Cambios" << std::endl;
		std::cout << "0. Salir" << std::endl;
		std::cin >> opcion;
		std::cout << std::endl;
		switch (opcion)
		{
		case 1:abre = abrir();
			break;
		case 2:inserta();
			break;
		case 3:insertaPala();
			break;
		case 4:borraLinea();
			break;
		case 5:borraPal();
			break;
		case 6:irAlPrincipio();
			break;
		case 7:irAlFinal();
			break;
		case 8:imprimir(archivo);
			break;
		case 9:guarda(abre);
			break;
		case 0:
			opcion = 0;
			break;
		default:
			break;
		}
	}

}


void cargar(std::fstream &archivo, ListaDEC<ListaDEC<std::string> * > &texto)
{
	std::string temp;
	while (getline(archivo, temp))
	{

	}
}
void loadFile(std::fstream &file, ListaDEC<ListaDEC<std::string> *> &texto)
{
	std::string temp;

	while (getline(file, temp))
	{

		ListaDEC<std::string> * linea = new ListaDEC<std::string>;
		linea = insertaPal(temp);
		archivo.insertBack(linea);
	}
}

ListaDEC<std::string> * insertaPal(std::string oracion)
{
	int i = 0;
	char aux = oracion[i];
	ListaDEC<std::string> * palabras = new ListaDEC < std::string >;
	std::string temp;

	while (aux)
	{
		if (aux == ' ')
		{
			palabras->insertBack(temp);
			temp = "";
		}
		else
		{
			temp += aux;
		}
		aux = oracion[++i];
	}

	palabras->insertBack(temp);
	return palabras;

}


std::string abrir()
{
	std::cout << "El archivo que usaremos se llama prueba.txt introduzca ese nombre para abrirlo" << std::endl;
	std::string nombre;
	std::cout << "Dame la dirección y el nombre del archivo para abrir" << std::endl;
	std::cin >> nombre;
	std::fstream doc;
	doc.open(nombre, std::fstream::in | std::fstream::out | std::fstream::app);

	if (doc.is_open())
	{
		loadFile(doc, archivo);
		std::cout << "El archivo se cargo correctamenta" << std::endl;
	}
	else
	{
		std::cout << "El archivo no se pudo abrir" << std::endl;
	}
	doc.close();
	return nombre;
}

void imprimir(ListaDEC<ListaDEC<std::string> *> & texto)
{
	for (int i = 0; i < texto.size(); i++)
	{
		std::cout << *archivo.At(i) << std::endl;
	}

}

void inserta()
{
	std::string line;
	std::cout << "Escriba la linea que quiere anadir" << std::endl;

	std::cin.ignore();
	std::getline(std::cin, line);

	archivo.insertAt(insertaPal(line), y);


}


void insertaPala()
{
	int posA;
	int posB;
	std::string palabra;

	std::cout << "Escribe la palabra que deseas insertar" << std::endl;
	std::cin >> palabra;

	archivo.At(y)->getInfo()->insertAt(palabra, x);
}


void borraLinea()
{
	archivo.deleteAt(x);
}


void borraPal()
{
	archivo.At(y)->getInfo()->deleteAt(x);
}

void guarda(std::string nombre)
{
	std::fstream doc;
	doc.open(nombre);
	for (int i = 0; i<archivo.size(); i++)
	{
		for (int z = 0; z<(archivo.At(i)->getInfo()->size()); z++)
		{
			doc << archivo.At(i)->getInfo()->At(z)->getInfo() << " ";
		}
		doc << std::endl;
	}
	doc.close();
}

void irAlPrincipio()
{
	int pos = -1;
	while (pos > archivo.size() + 1 || pos < 1)
	{
		std::cout << "Al principio de que renglon quieres ir tu?" << std::endl;
		std::cin >> pos;
	}

	y = pos - 1;
	x = 0;
	std::cout << "Ya estas posicionado en el renglon" << pos << "ahora puede agregar palabras a este renglon" << std::endl;
}

void irAlFinal()
{
	int pos = -1;
	int numpal;
	while (pos> archivo.size() || pos < 1)
	{
		std::cout << "A que renglon quieres ir?" << std::endl;
		std::cin >> pos;
	}
	numpal = archivo.At(pos - 1)->getInfo()->size();
	y = pos - 1;
	x = numpal;
}