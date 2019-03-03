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


public:
	Lista(string nombre);
	int len();
	void push_front(T x);
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
inline Lista<T>::Lista(string nombre)
{
}

template<class T>
inline int Lista<T>::len()
{
	return 0;
}

template<class T>
inline void Lista<T>::push_front(T x)
{
}

template<class T>
inline void Lista<T>::push_back(T x)
{
}

template<class T>
inline void Lista<T>::insertar(T x, int pos)
{
}

template<class T>
inline bool Lista<T>::remove(int pos, T & x)
{
	return false;
}

template<class T>
inline bool Lista<T>::pop(T & x)
{
	return false;
}

template<class T>
inline bool Lista<T>::pop_back(T & x)
{
	return false;
}

template<class T>
inline bool Lista<T>::get(int pos, T & x)
{
	return false;
}

template<class T>
inline bool Lista<T>::get_front(T & x)
{
	return false;
}

template<class T>
inline bool Lista<T>::get_back(T & x)
{
	return false;
}

template<class T>
inline void Lista<T>::print()
{
}

template<class T>
inline Lista<T>::~Lista()
{
}
