#include <iostream>
#include "listaEnlazadaCircular.h"

template <class T>
class ListaDEC : public ListaEnlazadaCircular<T> {
public:

	ListaDEC() : ListaEnlazadaCircular<T>()
	{
	}

	~ListaDEC(){
		clear();
	}

	void insertAt(T value, int pos) override;
	Nodo<T> * deleteAt(int pos) override;
	void clear() override;
	//void insertBack(T value) override;

	//    Nodo<T> * search(T value) override;
	//    Nodo<T> * searchPrev(T value) override;

	template <class Tn>
	friend std::ostream & operator <<(std::ostream &, ListaDEC<Tn> *&);


};

//template <class T>
//void ListaDEC<T>::insertBack(T value)
//{
//    insertAt(value,this->tamano);
//}

template <class T>
void ListaDEC<T>::clear()
{
	Nodo<T> * aux;

	while (this->inicio != this->ultimo) {
		aux = this->inicio;
		this->inicio = this->inicio->getSiguiente();
		this->inicio->setAnterior(aux->getAnterior());
		aux->setSiguiente(nullptr);
		aux->setAnterior(nullptr);
		delete aux;
	}

	if (this->ultimo)
	{
		this->ultimo->setSiguiente(nullptr);
		this->ultimo->setAnterior(nullptr);
		delete this->ultimo;
	}

	this->inicio = this->ultimo = nullptr;

	this->tamano = 0;
}

template <class T>
void ListaDEC<T>::insertAt(T value, int pos)
{
	if (pos < 0 || pos > this->tamano) {
		return;
	}

	/* Insertar al inicio de la lista */
	if (pos == 0)
	{
		if (this->tamano == 0)
		{
			Nodo<T> * nuevo = new Nodo<T>(value);
			this->inicio = this->ultimo = nuevo;
			this->inicio->setSiguiente(nuevo);
			this->inicio->setAnterior(nuevo);
		}
		else
		{
			Nodo<T> * nuevo = new Nodo<T>(value);
			nuevo->setSiguiente(this->inicio);
			nuevo->setAnterior(this->ultimo);
			this->inicio->setAnterior(nuevo);
			this->ultimo->setSiguiente(nuevo);
			this->inicio = nuevo;
		}
	}
	else if (pos == (this->tamano - 1)) {

		Nodo<T> * nuevo = new Nodo<T>(value);
		nuevo->setSiguiente(this->ultimo);
		nuevo->setAnterior(this->ultimo->getAnterior());
		this->ultimo->getAnterior()->setSiguiente(nuevo);
		this->ultimo->setAnterior(nuevo);

	}
	else if (pos == this->tamano)
	{
		Nodo<T> * nuevo = new Nodo<T>(value);
		nuevo->setAnterior(this->ultimo);
		nuevo->setSiguiente(this->inicio);
		this->ultimo->setSiguiente(nuevo);
		this->inicio->setAnterior(nuevo);
		this->ultimo = nuevo;
	}
	else
	{ /* Insertar en cualquier otra posición */
		Nodo<T> * anterior = this->At(pos)->getAnterior();
		Nodo<T> * nuevo = new Nodo<T>(value);
		nuevo->setSiguiente(anterior->getSiguiente());
		nuevo->setAnterior(anterior);
		anterior->getSiguiente()->setAnterior(nuevo);
		anterior->setSiguiente(nuevo);
	}

	++this->tamano;
}

template <class T>
Nodo<T> * ListaDEC<T>::deleteAt(int pos)
{
	if (pos < 0 || pos >= this->tamano) {
		return nullptr;
	}

	Nodo<T> * borrado = nullptr;

	/* Borra al inicio */
	if (pos == 0) {
		borrado = this->inicio;

		if (this->tamano == 1) {
			this->inicio->setSiguiente(nullptr);
			this->inicio->setAnterior(nullptr);
			this->inicio = this->ultimo = nullptr;
		}
		else {
			this->inicio = this->inicio->getSiguiente();
			this->ultimo->setSiguiente(this->inicio);
			this->inicio->setAnterior(this->ultimo);
		}
	}
	else { /* Borrar en cualquier otra posición */
		Nodo<T> * prev = this->At(pos)->getAnterior();

		if (prev->getSiguiente() == this->ultimo) {
			this->ultimo = prev;
			borrado = this->ultimo->getSiguiente();
			this->ultimo->setSiguiente(this->inicio);
			this->inicio->setAnterior(this->ultimo);
			borrado->setSiguiente(nullptr);
			borrado->setAnterior(nullptr);
		}
		else
		{
			borrado = prev->getSiguiente();
			borrado->getAnterior()->setSiguiente(borrado->getSiguiente());
			borrado->getSiguiente()->setAnterior(borrado->getAnterior());
			borrado->setSiguiente(nullptr);
			borrado->setAnterior(nullptr);
		}
	}
	--this->tamano;
	return borrado;
}

template <class T>
std::ostream & operator <<(std::ostream & os, ListaDEC<T> *& lista)
{

	for (auto p : *lista)
	{
		os << p << " ";
	}

	return os;
}