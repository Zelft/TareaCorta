#pragma once
#include "string"
#include <stdio.h>
#include "Lista.h"
#include <queue>

using namespace std;

template <class T, int N = 20>
class ListaB {
private:
	struct Nodo {
		bool lleno;
		T elemento[N];
		struct Nodo * siguiente; // Puntero al siguiente nodo
		// Constructores
		Nodo() :lleno{ false }, siguiente{ 0 } {}
		Nodo(struct Nodo * sig) :lleno{ false }, siguiente{ sig } {}
	};
	typedef struct Nodo* link;

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
	std::queue<T> ListaElementos;
	ListaElementos.push(x);
	for (int i = 1; i <= tam; i++) {
		T a;
		this->get(i, a);
		ListaElementos.push(a);
	}
	tam = 0;
	link p = primero;
	while (p) {
		link siguiente = p->siguiente;
		delete p;
		p = siguiente;
	}
	primero = NULL;
	while (!ListaElementos.empty()) {
		this->push_back(ListaElementos.front());
		ListaElementos.pop();
	}
}

template<class T, int N>
inline void ListaB<T, N>::push_back(T x)
{
	if (!primero) {
		primero = new Nodo();
		primero->elemento[0] = x;
		tam++;
	}
	else {
		if (tam >= N) {
			int mod = tam / N;
			int pos = tam % N;
			link p = primero;
			while (mod > 1 && p->siguiente) {
				p = p->siguiente;
				mod--;
			}
			if (pos != 0 && p->siguiente) {
				p = p->siguiente;
				p->elemento[pos] = x;
			}
			else {
				if (pos != 0) {
					p->elemento[pos] = x;
				}
				else {
					p->siguiente = new Nodo();
					p = p->siguiente;
					p->elemento[0] = x;
				}
			}
		}
		else
		{
			primero->elemento[tam] = x;
		}
		tam++;
	}
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
	if (!primero && pos>tam) {
		return false;
	}
	else
	{
		pos--;
		link p = primero;
		while (pos>=N) {
			p = p->siguiente;
			pos -= N;
		}
		element = p->elemento[pos];
		return true;
	}
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
		int pos = tam;
		link q = primero;
		while (q->siguiente)
		{
			q = q->siguiente;
			pos -= N;
		}
		element = q->elemento[pos-1];
		return true;
	}
}

template<class T, int N>
inline void ListaB<T, N>::print()
{
	cout << "[";
	if (primero) {
		link p = primero;
		int nodos = tam / N;
		int posFinal = tam % N;
		while (nodos > 0) {
			cout << "[";
			for (int i = 0; i < N - 1; i++) {
				cout << p->elemento[i] << ",";
			}
			if (p->siguiente)
				cout << p->elemento[N - 1] << "],";
			else
				cout << p->elemento[N - 1] << "]";
			p = p->siguiente;
			nodos--;
		}

		if (posFinal != 0) {
			cout << "[";
			for (int i = 0; i < posFinal - 1; i++) {
				cout << p->elemento[i] << ",";
			}
			cout << p->elemento[posFinal - 1] << "]";
		}
		/*else {
			for (int i = 0; i < N - 1; i++) {
				cout << p->elemento[i] << ",";
			}
			cout << p->elemento[N-1] << "]";
		}*/
	}
	cout << "]\n";
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
