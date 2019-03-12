
#include "pch.h"
#include <iostream>
#include "Lista.h"
#include "ListaB.h"

using namespace std;

/*
	Tarea Corta #2
	En este archivo se harán los include de las clases Lista y ListaB
*/

void encabezado();
void reportePrueba(bool);

int main()
{
	ListaB<int, 5> lista{"pruebaB"};
	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(3);
	lista.push_back(4);
	lista.push_back(5);
	/*pruebalista.push_back(1);
	pruebalista.push_back(2);
	pruebalista.push_back(3);
	pruebalista.push_back(4);
	pruebalista.push_back(5);
	pruebalista.push_back(6);
	pruebalista.push_back(7);
	pruebalista.push_back(8);
	pruebalista.push_back(9);
	pruebalista.push_back(10);
	pruebalista.print();
	pruebalista.push_front(0);
	pruebalista.print();
	pruebalista.push_front(100);
	pruebalista.print();
	pruebalista.push_front(101);
	pruebalista.print();
	pruebalista.push_front(102);
	pruebalista.print();*/
	//int x;
	//pruebalista.get_back(x);
	//cout << x;
	//pruebalista.push_back(1);
	//encabezado();
	system("Pause()");
}

void reportePrueba(bool b) {
	cout << (b ? "\n\tPrueba: [Ok]" : "\n\tPrueba: [Fallida]") << "\n";
}
void encabezado(){
	bool resultado = false;
	cout<<"--------------TAREA CORTA #2--------------"<<endl;
	cout << "Estudiantes:\n\tDanny Piedra\n\tGerald Calvo"<<endl;
	cout << "** Reporte de Pruebas para Clase Lista** " << endl<<endl;
	string ar[13]{ "Lista(string nombre)","int len()","void push_front(T x)",
	"push_back(T x)","insertar(T x, int pos)","remove(int pos, T& x)","pop(T x)",
	"pop_back(T& x)","set(int pos, T x)","get_front(T& x)","get_back(T& x)","print()","~Lista()" };
	int largo = 10;
	Lista<int> lista{ "Lista 2" };
	for (int i = largo; i > 0; i--) {
		lista.insertar(i, 0);
	}
	for (int i = 0; i < 13; i++) {
		cout << "Metodo: " << ar[i]<<":"<<endl;
		switch (i) {
		case 0: {
			Lista<int> lista2{ "Lista 1" };
			reportePrueba(true);
			break;
		}
		case 1: {
			cout << "\tSe va a calcular el largo de la lista\n\t";
			lista.print();
			(lista.len() == largo) ? resultado = true : resultado = false;
			cout << "\n\tEl largo es: " << lista.len()<<"\n\t";
			reportePrueba(resultado);
			cout << endl;
			break;
		}
		case 2: {
			cout << "\t";
			cout << "No se ha hecho";
			cout << endl;
			break;
		}
		case 3: {
			cout << "\n\tSe va a insertar un elemento al final. Se usara el 6\n\t";
			Lista<int> lista2{ "Lista 2" };
			for (int i = largo; i > 0; i--) {
				lista2.insertar(i, 0);
			}
			lista2.print();
			lista2.push_back(6);
			cout << "\n\t";
			lista2.print();
			(lista2.len()!=largo) ? resultado = true : resultado = false;
			reportePrueba(resultado);
			cout << endl;
			break;
		}
		case 4: {
			cout << "\n\tSe va a insertar un 24 en la posicion 2\n\t";
			Lista<int> lista{ "Lista " };
			for (int i = largo; i > 0; i--) {
				lista.insertar(i, 0);
			}
			lista.print();
			lista.insertar(24, 2);
			cout << "\n\t";
			lista.print();
			(lista.len() != largo) ? resultado = true : resultado = false;
			reportePrueba(resultado);
			cout << endl;
			break;
		}
		case 5: {
			cout << "\n\tNo se ha hecho\n\n";
			break;
		}
		case 6: {
			cout << "\n\tRemueve el elemento al inicio de la lista y lo deja en posicion x. Se usara la posicion 4\n\t";
			Lista<int> lista{ "Lista " };
			for (int i = largo; i > 0; i--) {
				lista.insertar(i, 0);
			}
			lista.print();
			int x;
			lista.pop(x);
			cout << "\n\t";
			lista.print();
			(lista.len() != largo)? resultado = true : resultado = false;
			reportePrueba(resultado);
			cout << endl;
			break;
		}
		case 7: {
			cout << "\n\tNo se ha hecho\n";
			break;
		}
	    case 8:{
			cout << "\tDeja en x el elemento en posicion pos de la lista.Retorna true si la operacion se realizo de forma exitosa\n\tSe usara el 49 de ejemplo.\n";
			Lista<int> lista{ "Lista " };
			for (int i = largo; i > 0; i--) {
				lista.insertar(i, 0);
			}
			cout << "\n\t";
			lista.print();
			//lista.set(3, 49);
			cout << "\n\t";
			lista.print();
			(lista.len() == largo) ? resultado = true : resultado = false;
			reportePrueba(resultado);
			cout << endl;
			break;
		}
		case 9: {
			cout << "\n\tNo se ha hecho\n";
			break;
		}
		case 10: {
			cout << "\n\tNo se ha hecho\n";
			break;
		}
		case 11: {
			Lista<int> lista{ "Lista " };
			for (int i = largo; i > 0; i--) {
				lista.insertar(i, 0);
			}
			cout << "\n\tSe hara una impresion de una lista\n\t";
			lista.print();
			reportePrueba(true);
			break;
		}
		case 12: {
			cout << "\n\tNo se ha hecho\n";
			break;
		}
		default:{};

		}//Switch
	}

	system("PAUSE()");
}

