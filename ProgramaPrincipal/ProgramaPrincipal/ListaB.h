#pragma once
#include "string"
#include <stdio.h>

using namespace std;

template <class T, int N = 20>
class ListaB {
private:
	struct Nodo {
		bool lleno;
		T elemento[N];
		struct Nodo * siguiente;
		Nodo(T x) :elemento{ x }, siguiente{ 0 },
			lleno{ false } {}
		Nodo(T x, struct Nodo* sig)
			:elemento{ x }, siguiente{ sig },
			lleno{ false } {}
	};
	typedef struct Nodo * link;
	link primero; // Puntero al primer elemento de la lista
	int tam; // Cantidad de elementos de la lista
	string nombreLista; // Nombre de la lista
	// Métodos privados
	// Acá se incluyen los métodos privados que se requieran.
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
}

template<class T, int N>
inline int ListaB<T, N>::len()
{
	return 0;
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
}

template<class T, int N>
inline bool ListaB<T, N>::remove(int pos, T & x)
{
	return false;
}

template<class T, int N>
inline bool ListaB<T, N>::pop(T & x)
{
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
	return false;
}

template<class T, int N>
inline bool ListaB<T, N>::get_back(T & element)
{
	return false;
}

template<class T, int N>
inline void ListaB<T, N>::print()
{
}

template<class T, int N>
inline ListaB<T, N>::~ListaB()
{
}
