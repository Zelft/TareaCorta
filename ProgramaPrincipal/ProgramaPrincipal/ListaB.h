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
	void reinsertarElementos(queue<T>);

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
	//Constructor inicializa los data members en vacio y el nombre con el
	//parametro recibido.
	tam = 0;
	nombreLista = nombre;
	primero = NULL;
}

template<class T, int N>
inline int ListaB<T, N>::len()
{
	//Retorna el tamaño de la lista
	return tam;
}

template<class T, int N>
inline void ListaB<T, N>::push_front(T x)
{
	//La estrategia consiste en utilizar una cola de elementos T
	//para almecenar los elementos de los arreglos para insertarlos
	//nuevamente en la lista posterior al push front.
	//Se vacia la lista y se vuelve a insertar con los elementos de la cola+1
	std::queue<T> ListaElementos;
	ListaElementos.push(x);
	for (int i = 1; i <= tam; i++) {
		T a;
		this->get(i, a);
		ListaElementos.push(a);
	}
	tam = 0;
	this->~ListaB();
	primero = NULL;
	reinsertarElementos(ListaElementos);
}

template<class T, int N>
inline void ListaB<T, N>::push_back(T x)
{
	/*La estrategia se basa en que si no existe primero se crea un nuevo nodo
	y se le asigna en la posicion 0 el elemento y se incrementa el tamaño.
	De lo contrario, se avanza en el nodo y se busca si el nodo esta lleno.
	*/
	if (!primero) {
		primero = new Nodo();
		primero->elemento[0] = x;
		tam++;
	}
	else {
		if (tam >= N) {
			int mod = tam / N; //Nodos que tiene la lista
			int pos = tam % N; //La posicion final del arreglo en determinado nodo
			link p = primero;
			while (mod > 1 && p->siguiente) { //Avanzamos entre los nodos hasta llegar al final
				p = p->siguiente;
				mod--;
			}
			if (pos != 0 && p->siguiente) { //Aun no se ha llegado al final del nodo. Se avanza
				p = p->siguiente;			//al siguiente y se inserta. Este nodo no esta lleno.
				p->elemento[pos] = x;
			}
			else {
				if (pos != 0) { //Se ha llegado al final del Nodo y este no esta lleno.
					p->elemento[pos] = x;
				}
				else {
					//El donde se efectuara la insercion esta lleno, se crea uno nuevo y se inserta
					//en la posicion 0.
					p->lleno = true;
					p->siguiente = new Nodo();
					p = p->siguiente;
					p->elemento[0] = x;
				}
			}
		}
		else //El elemento se insertara en el primer nodo
		{
			primero->elemento[tam] = x;
		}
		tam++;
	}
}

template<class T, int N>
inline void ListaB<T, N>::insertar(T x, int pos)
{
	if (!primero || pos > tam) { //Si la posicion es invalida o si la lista esta vacia se hara
								// un push_back en la lista del elemento.
		this->push_back(x);
	}
	else {//Se usara una cola como estructura de datos intermedia para almacenar los elementos
		//existentes en la lista para posterior re insertarlos adicional al nuevo elemento
		link p = primero;
		queue<T> elementos;
		int t = tam;
		int c = 0;
		T a;
		while (t) {
			if (c != pos) {
				this->pop(a);
				elementos.push(a);
			}
			else {
				elementos.push(x);
				t++;
			}
			c++;
			t--;
		}
		tam = 0;
		p = primero;
		this->~ListaB(); //Se vacia la lista
		reinsertarElementos(elementos); //Se vuelve a llenar con elementos + 1
	}
}

template<class T, int N>
inline bool ListaB<T, N>::remove(int pos, T & x)
{
	/*Se utiliza una cola como estructuras de datos para almacenamiento temporal de los
	elementos, se vacia la lista progresivamente hasta llegar al elemento en la posicion
	solicitada, en este caso se omite la insercion a esta cola temporal. Posteriormente, se
	rellena la lista con los elementos.
	*/
	if (!primero || pos > tam) {
		return false;
	}
	else {
		link p = primero;
		queue<T> elementos;
		int t = tam;
		int c = 0;
		T a;
		while (t) {
			if (c != pos) {
				this->pop(a);
				elementos.push(a);
			}
			else {
				this->pop(x);
			}
			c++;
			t--;
		}
		tam = 0;
		this->~ListaB();
		reinsertarElementos(elementos);
		return true;
	}
}

template<class T, int N>
inline bool ListaB<T, N>::pop(T & x)
{
	/*La estrategia consiste en re insertar los elementos de la lista en una cola temporal
	exceptuando la insercion del primer elemento. Este se guarda en la direccion de memoria
	del parametro de la funcion*/
	if (!primero) {
		return false;
	}
	else {
		x = primero->elemento[0]; //Se guarda en la direccion de la variable el primer elemento
		queue<int> elementos;
		for (int i = 2; i <= tam; i++) {
			T a;
			this->get(i, a);
			elementos.push(a);
		}
		tam = 0;
		this->~ListaB();
		reinsertarElementos(elementos);
		return true;
	}
}

template<class T, int N>
inline bool ListaB<T, N>::pop_back(T & elemento)
{
	/*Se insertan los elementos en una cola hasta llegar al penúltimo elemento.
	Luego, se re insertan en la lista*/
	if (!primero) {
		return false;
	}
	else {
		queue<T>elementos;
		for (int i = 1; i < tam; i++) { //Se recorre de inicio al final-1
			T a;
			this->get(i, a);
			elementos.push(a);
		}
		this->get(tam, elemento); //Se guarda el ultimo elemento de la lista en la variable
		tam = 0;
		this->~ListaB(); //Se vacia la lista
		reinsertarElementos(elementos); //Se vuelve a llenar
		return true;
	}
}

template<class T, int N>
inline bool ListaB<T, N>::get(int pos, T & element)
{
	if (!primero && pos>=tam) {
		return false;
	}
	else
	{
		pos--;
		link p = primero;
		while (pos>=N && p->siguiente	) { //La posicion esta en algun nodo que no sea el primero.
						//Avanzamos y decrementamos la posicion N cantidad
			p = p->siguiente;
			pos -= N;
		}
		element = p->elemento[pos]; //Almacenamos el elemento de la posicion en la direccion de
									//memoria del elemento como parametro.
		return true;
	}
}

template<class T, int N>
inline bool ListaB<T, N>::get_front(T & element)
{
	if (!primero) { //Si no existe, no se puede retornar
		return false;
	}
	else
	{	//Se accede al primer nodo, elemento[0]
		element = primero->elemento[0];
		return true;
	}

}

template<class T, int N>
inline bool ListaB<T, N>::get_back(T & element)
{
	if (!primero) { //Si no hay elementos, no se puede retornar el ultimo.
		return false;
	}
	else
	{
		//Se usa la misma estrategia del metodo get con la posicion.
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
	//Se recorrer todos los elementos de la lista nodo por nodo, al finalizar uno
	//se cierra el parentesis y se abre otro.
	cout <<"[";
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
	}
	cout << "]\n";
}

template<class T, int N>
inline ListaB<T, N>::~ListaB() //Destructor
{
	link p;
	while (primero) {
		p = primero->siguiente;
		delete primero;
		primero = p;
	}
	tam = 0;
}

//Metodos Adicionales de la clase

template<class T, int N>
inline void ListaB<T, N>::reinsertarElementos(queue<T>q)
{
	while (!q.empty()) {
		this->push_back(q.front());
		q.pop();
	}
}