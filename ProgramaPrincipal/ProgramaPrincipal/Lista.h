#pragma once
#include "string"
#include <stdio.h>

using namespace std;

template <class T>

class Lista
{
private:
	struct Nodo {
		T elemento;
		struct Nodo * siguiente;
		Nodo(T x) :elemento{ x }, siguiente{ 0 } {}
		Nodo(T x, struct Nodo* sig)
			:elemento{ x }, siguiente{ sig } {}
	};
	typedef struct Nodo * link;
	link primero; // Puntero al primer elemento de la lista
	int tam; // Cantidad de elementos de la lista
	string nombreLista; // Nombre de la lista
	int x; //almacenamiento del numero X. Metodo pop(T &x);
	string imprimaDeInstanciacion();

public:
	Lista(string nombre);
	int len();
	void push_front(T x);
	void push_back(T x);
	void insertar(T x, int pos);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& x);
	bool get_front(T& x);
	bool get_back(T& x);
	void print();
	~Lista();
};

template<class T>
inline string Lista<T>::imprimaDeInstanciacion()
{
	return nombreLista;
}

template<class T>
inline Lista<T>::Lista(string nombre)
{
	nombreLista = nombre;
	primero = NULL;
	tam = 0;
}

template<class T>
inline int Lista<T>::len()
{
	return tam;
}

template<class T>
inline void Lista<T>::push_front(T x)
{
	if (!primero) {
		primero = new Nodo(x);
	}
	else {
		link q = new Nodo(x,primero);
		primero = q;
	}
	tam++;
}

template<class T>
inline void Lista<T>::push_back(T x)
{
	if (!primero) {
		primero = new Nodo(x);
	}
	else {
		link q = primero;
		for (; q->siguiente; q = q->siguiente);
		q->siguiente = new Nodo(x, q->siguiente);
	}
	tam++;
}

template<class T>
inline void Lista<T>::insertar(T x, int pos)
{
	if (!primero) {
		primero = new Nodo(x);
	}
	else {
		if (pos == 0) {
			primero = new Nodo(x, primero);
		}
		else {
			link p = primero;
			while (p->siguiente && pos > 1) {
				p = p->siguiente;
				pos--;
			}
			p->siguiente = new Nodo(x, p->siguiente);
		}
	}
	tam++;

}

template<class T>
inline bool Lista<T>::remove(int pos, T & x)
{
	if (pos >= this->len() ) {
		return false;
	}
	else
	{
		link q = primero;
		pos--;
		while (pos!=0) {
			pos--;
			q = q->siguiente;

		}
		x = q->siguiente->elemento;
		q->siguiente = q->siguiente->siguiente;
		return true;
	}

}

template<class T>
inline bool Lista<T>::pop(T& x)
{	
	if (!primero) {
		return false;
	}
	else {
		tam--;
		x = primero->elemento;
		primero = primero->siguiente;
		return true;
	}
}

template<class T>
inline bool Lista<T>::pop_back(T & x)
{
	if (!primero) {
		return false;
	}
	else if (!primero->siguiente) {
		x = primero->elemento;
		primero = primero->siguiente;
		tam--;
		return true;
	}
	else {
		tam--;
		link q = primero;
		while (q->siguiente->siguiente) {
			q = q->siguiente;
		}
		x = q->siguiente->elemento;
		q->siguiente = NULL;
		return true;
	}
}

template<class T>
inline bool Lista<T>::get(int pos, T& x)
{
	if (!primero && pos>=tam) {
		return false;
	}
	else {
		link q = primero;
		while (q->siguiente && pos > 0) {
			q = q->siguiente;
			pos--;
		}
		x = q->elemento;
		return true;
	}
}

template<class T>
inline bool Lista<T>::get_front(T & x)
{
	if (!primero) {
		return false;
	}
	else {
		x = primero->elemento;
		return true;
	}
}

template<class T>
inline bool Lista<T>::get_back(T & x)
{
	if (!primero) {
		return false;
	}
	else if (!primero->siguiente) {
		x = primero->elemento;
		return true;
	}
	else {
		link q = primero;
		while (q->siguiente->siguiente) {
			q = q->siguiente;
		}
		x = q->siguiente->elemento;
		return true;
	}
}

template<class T>
inline void Lista<T>::print()
{
	cout << "[ ";
	if (primero) {
		link q = primero;
		cout << q->elemento;
		for (q = q->siguiente; q;q=q->siguiente) cout << ", " << q->elemento;
	}
	cout << " ]";
}

template<class T>
inline Lista<T>::~Lista()
{
	link p;
	while (primero) {
		p = primero->siguiente;
		delete primero;
		primero = p;
	}
	tam = 0;
}
