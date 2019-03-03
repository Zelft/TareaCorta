#pragma once
#include "string"
#include <stdio.h>

template <class T>

class ListaSimple
{
public:
	ListaSimple(string nombre);
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
	~ListaSimple();
};
