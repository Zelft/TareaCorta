#include "pch.h"
#include <string>
#include "ListaSimple.h"

using namespace std;

template<class T>
inline ListaSimple<T>::ListaSimple(string nombre)
{
}

template<class T>
inline int ListaSimple<T>::len()
{
	return 0;
}

template<class T>
inline void ListaSimple<T>::push_front(T x)
{
}

template<class T>
inline void ListaSimple<T>::push_back(T x)
{
}

template<class T>
inline void ListaSimple<T>::insertar(T x, int pos)
{
}

template<class T>
inline bool ListaSimple<T>::remove(int pos, T & x)
{
	return false;
}

template<class T>
inline bool ListaSimple<T>::pop(T & x)
{
	return false;
}

template<class T>
inline bool ListaSimple<T>::pop_back(T & x)
{
	return false;
}

template<class T>
inline bool ListaSimple<T>::get(int pos, T & x)
{
	return false;
}

template<class T>
inline bool ListaSimple<T>::get_front(T & x)
{
	return false;
}

template<class T>
inline bool ListaSimple<T>::get_back(T & x)
{
	return false;
}

template<class T>
inline void ListaSimple<T>::print()
{
}

template<class T>
ListaSimple<T>::~ListaSimple()
{
}
