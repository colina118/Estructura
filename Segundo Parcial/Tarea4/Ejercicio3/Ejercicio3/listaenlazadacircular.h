#include <iostream>
#include "ListaEnlazada.h"


template <class T>
class ListaEnlazadaCircular : public ListaEnlazada<T> {
protected:
	Nodo<T> * ultimo = nullptr;

public:

	ListaEnlazadaCircular() : ListaEnlazada<T>()
	{
		//ultimo = nullptr;
	}

	~ListaEnlazadaCircular();

	void insertAt(T value, int pos) override;
	Nodo<T> * deleteAt(int pos) override;
	void clear() override;

	Nodo<T> * search(T value) override;
	Nodo<T> * searchPrev(T value) override;

	template <class Tn>
	friend std::ostream & operator <<(std::ostream &, ListaEnlazadaCircular<Tn> &);

};

template <class T>
ListaEnlazadaCircular<T>::~ListaEnlazadaCircular()
{
	clear();
}

template <class T>
void ListaEnlazadaCircular<T>::insertAt(T value, int pos)
{
	ListaEnlazada<T>::insertAt(value, pos);

	if (pos == 0) {
		/* Adicionado con respecto a la ListaEnlazada */
		if (this->tamano == 1) {
			ultimo = this->inicio;
		}

		ultimo->setSiguiente(this->inicio);
	}
	else if (pos == (this->tamano - 1)) {
		ultimo = ultimo->getSiguiente();

	}
}

template <class T>
Nodo<T> * ListaEnlazadaCircular<T>::deleteAt(int pos)
{
	if (pos < 0 || pos >= this->tamano) {
		return nullptr;
	}

	Nodo<T> * borrado = nullptr;

	/* Borra al inicio */
	if (pos == 0) {
		borrado = this->inicio;

		if (this->tamano == 1) {
			this->inicio = ultimo = nullptr;
		}
		else {
			this->inicio = this->inicio->getSiguiente();
			ultimo->setSiguiente(this->inicio);
		}
	}
	else { /* Borrar en cualquier otra posición */
		Nodo<T> * prev = this->AtPrev(pos);

		if (prev->getSiguiente() == ultimo) {
			ultimo = prev;
		}

		borrado = prev->getSiguiente();
		prev->setSiguiente(borrado->getSiguiente());
	}

	borrado->setSiguiente(nullptr);

	--this->tamano;

	return borrado;
}


template <class T>
void ListaEnlazadaCircular<T>::clear()
{
	Nodo<T> * aux;

	while (this->inicio != ultimo) {
		aux = this->inicio;
		this->inicio = this->inicio->getSiguiente();
		aux->setSiguiente(nullptr);
		delete aux;
	}

	if (ultimo)
	{
		ultimo->setSiguiente(nullptr);
		delete ultimo;
	}

	this->inicio = ultimo = nullptr;

	this->tamano = 0;
}

template <class T>
Nodo<T> * ListaEnlazadaCircular<T>::search(T value)
{
	Nodo<T> * aux = this->inicio;
	//    
	//    while (aux != ultimo && (aux->getInfo() != value) ) {
	//        aux = aux->getSiguiente();
	//    }
	//    
	//    if (aux == ultimo && aux && aux->getInfo() != value) {
	//        return nullptr;
	//    }

	return aux;
}

template <class T>
Nodo<T> * ListaEnlazadaCircular<T>::searchPrev(T value)
{
	Nodo<T> * aux = this->inicio;
	Nodo<T> * prev = aux;
	//    
	//    while (prev != ultimo && (aux->getInfo() != value) ) {
	//        prev = aux;
	//        aux = aux->getSiguiente();
	//    }

	return prev;
}

template <class T>
std::ostream & operator <<(std::ostream & os, ListaEnlazadaCircular<T> & lista)
{
	//    Nodo<T> * aux = lista.inicio;
	//    
	//    while (aux && aux != lista.ultimo) {
	//        os << *aux << std::endl;
	//        aux = aux->getSiguiente();
	//    }
	//    
	//    if (aux) {
	//        os << *aux << std::endl;
	//    }

	for (auto p : lista)
	{
		os << p << " ";
	}

	return os;
}