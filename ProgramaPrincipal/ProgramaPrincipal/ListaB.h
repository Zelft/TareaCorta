#pragma once
#include "string"
#include <stdio.h>

using namespace std;

template <class T, int N = 20>
class ListaB {
private:
	struct Node {
		bool lleno;
		T elemento[N];
		struct Node * siguiente; // Puntero al siguiente nodo
		// Constructores
		Node() :lleno{ false }, siguiente{ 0 } {}
		Node(struct Node * sig) :lleno{ false }, siguiente{ sig } {}
	};
	typedef struct Node * link;
	link primero; // Puntero al primer elemento de la lista
	int tam; // Cantidad de elementos de la lista
	string nombreLista; // Nombre de la lista
	// M�todos privados
	// Ac� se incluyen los m�todos privados que se requieran.

public:
	ListaB(string nombre);
	int len();
	void push_front(T x);
	void push_back(T x);
	void insertar(T x, int pos);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& element);
	bool get_front(T& element);
	bool get_back(T& element);
	void print();
	~ListaB();

};

template<class T, int N>
inline ListaB<T, N>::ListaB(string nombre)
{
	tam = 0;
	nombreLista = nombre;
	primero = NULL;
}

template<class T, int N>
inline int ListaB<T, N>::len()
{
	return tam;
}

template<class T, int N>
inline void ListaB<T, N>::push_front(T x)
{
}

template<class T, int N>
inline void ListaB<T, N>::push_back(T x)
{
}

template<class T, int N>
inline void ListaB<T, N>::insertar(T x, int pos)
{
	//En pareja
}

template<class T, int N>
inline bool ListaB<T, N>::remove(int pos, T & x)
{
	//En pareja
	return false;
}

template<class T, int N>
inline bool ListaB<T, N>::pop(T & x)
{
	//En pareja
	return false;
}

template<class T, int N>
inline bool ListaB<T, N>::pop_back(T & x)
{
	return false;
}

template<class T, int N>
inline bool ListaB<T, N>::get(int pos, T & element)
{
	return false;
}

template<class T, int N>
inline bool ListaB<T, N>::get_front(T & element)
{
	if (!primero) {
		return false;
	}
	else
	{
		element = primero->elemento[0];
		return true;
	}

}

template<class T, int N>
inline bool ListaB<T, N>::get_back(T & element)
{
	if (!primero) {
		return false;
	}
	else
	{
		link q = primero;
		while (q->siguiente)
		{
			q = q->siguiente;
		}
		element = q->elemento[N-1];
		return true;
	}
}

template<class T, int N>
inline void ListaB<T, N>::print()
{
}

template<class T, int N>
inline ListaB<T, N>::~ListaB()
{
	link p;
	while (primero) {
		p = primero->siguiente;
		delete primero;
		primero = p;
	}
}
