#include <iostream>

//template <class T> class Nodo;
//template <class T>
//std::ostream & operator <<(std::ostream &, Nodo<T> &);

template <class T>
class Nodo {
private:
	T info;
	Nodo<T> * siguiente;
	Nodo<T> * anterior;

public:
	Nodo();
	Nodo(T info);

	T getInfo();
	void setInfo(T value);

	Nodo<T> * getSiguiente();
	void setSiguiente(Nodo<T> * value);
	Nodo<T> * getAnterior();
	void setAnterior(Nodo<T> * value);

	template <class Tn>
	friend std::ostream & operator <<(std::ostream &, Nodo<Tn> &);

	/* Probando los iteradores */
	Nodo<T> & operator ++(int);

};

template <class T>
Nodo<T>::Nodo()
{
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

template <class T>
Nodo<T>::Nodo(T info)
{
	this->info = info;
	this->siguiente = nullptr;
	this->anterior = nullptr;

}

template <class T>
T Nodo<T>::getInfo()
{
	return info;
}

template <class T>
void Nodo<T>::setInfo(T value)
{
	info = value;
}

template <class T>
Nodo<T> * Nodo<T>::getSiguiente()
{
	return siguiente;
}

template <class T>
void Nodo<T>::setSiguiente(Nodo<T> * value)
{
	siguiente = value;
}

template <class T>
Nodo<T>* Nodo<T>::getAnterior()
{
	return anterior;
}

template <class T>
void Nodo<T>::setAnterior(Nodo<T> * value)
{
	anterior = value;
}

template <class T>
std::ostream & operator <<(std::ostream & os, Nodo<T> & nodo)
{
	os << nodo.info;

	return os;
}

template <class T>
Nodo<T> & Nodo<T>::operator ++(int i)
{
	return siguiente;
}