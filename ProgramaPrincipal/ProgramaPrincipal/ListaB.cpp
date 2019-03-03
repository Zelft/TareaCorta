#include "pch.h"
#include "ListaB.h"
#include <string>

using namespace std;



template<class T, int N>
ListaB<T, N>::ListaB(string nombre, int)
{
}

template<class T, int N>
int ListaB<T, N>::len()
{
	return 0;
}

template<class T, int N>
void ListaB<T, N>::push_front(T x)
{
}

template<class T, int N>
void ListaB<T, N>::push_back(T x)
{
}

template<class T, int N>
void ListaB<T, N>::insertar(T x, int pos)
{
}

template<class T, int N>
bool ListaB<T, N>::remove(int pos, T & x)
{
	return false;
}

template<class T, int N>
bool ListaB<T, N>::pop(T & x)
{
	return false;
}

template<class T, int N>
bool ListaB<T, N>::pop_back(T & x)
{
	return false;
}

template<class T, int N>
bool ListaB<T, N>::get(int pos, T & element)
{
	return false;
}

template<class T, int N>
bool ListaB<T, N>::get_front(T & element)
{
	return false;
}

template<class T, int N>
bool ListaB<T, N>::get_back(T & element)
{
	return false;
}

template<class T, int N>
void ListaB<T, N>::print()
{
}

template<class T, int N>
ListaB<T, N>::~List()
{
}
