
#include "pch.h"
#include <iostream>
#include "Lista.h"
#include "ListaB.h"

using namespace std;

/*
	Tarea Corta #2
	En este archivo se harán los include de las clases Lista y ListaB
*/

void encabezadoListaB();
void reportePrueba(bool);

int main()
{
	encabezadoListaB();

	cout << "\n\n\n";
	system("Pause()");
}

void reportePrueba(bool b) {
	cout << (b ? "\n\tResultado de Prueba: [Ok]" : "\n\tResultado de Prueba: [Fallida]") << "\n";
}
void encabezadoListaB(){
	bool resultado = false;
	int p[]{0,1,2,3,4,5,6,7,8,9,10,11,12};
	cout<<"--------------TAREA CORTA #2--------------"<<endl;
	cout << "Estudiantes:\n\tDanny Piedra\n\tGerald Calvo"<<endl;
	cout << "** Reporte de Pruebas para Clase ListaB** " << endl<<endl;
	string ar[13]{ "Lista(string nombre)","int len()","void push_front(T x)",
	"push_back(T x)","insertar(T x, int pos)","remove(int pos, T& x)","pop(T &x)",
	"pop_back(T& x)","get(int pos, T& element)","get_front(T& x)","get_back(T& x)","print()","~Lista()" };
	int largo = 12;
	ListaB<int,4> lista{ "Lista" };
	for (int i = largo; i > 0; i--) {
		lista.push_front(i);
	}
	for (int np : p) {
		cout << "Metodo: " << ar[np]<<":"<<endl;
		switch (np) {
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
			cout << "\t Se utilizara el metodo Push Front para insertar el numero 12\n\t";
			int n = 12, y;
			lista.print();
			cout << "\n\t";
			lista.push_front(n);
			lista.get(1, y);
			( y==n ? resultado = true : resultado = false);
			lista.print();
			cout << endl;
			reportePrueba(resultado);
			cout << endl;
			break;
		}
		case 3: {
			cout << "\n\tSe va a insertar un elemento al final. Se usara el numero 11\n\t";
			lista.print();
			cout << "\n\t";
			lista.push_back(11);
			lista.print();
			int y;
			lista.get_back(y);
			(y==11 ? resultado = true : resultado = false);
			reportePrueba(resultado);
			cout << endl;
			break;
		}
		case 4: {
			int y;
			cout << "\n\tSe va a insertar un 24 en la posicion 2\n\t";
			lista.print();
			cout << "\n\t";
			lista.insertar(24, 2);
			lista.print();
			lista.get(3,y);
			(y == 24 ? resultado = true : resultado = false);
			reportePrueba(resultado);
			cout << endl;
			break;
		}
		case 5: {
			int y,x;
			cout << "\tSe va a eliminar el elemento en posicion 3. Se colocara en la variable y.\n\n\t";
			lista.print();
			lista.get(4,x);
			lista.remove(3, y);
			cout << "\t";
			lista.print();
			(y == x ? resultado = true : resultado = false);
			reportePrueba(resultado);
			break;
		}
		case 6: {
			int x,y;
			cout << "\n\tRemueve el elemento al inicio de la lista y lo deja en la variable x\n\t";
			lista.print();
			cout << "\n\t";
			lista.get_front(y);
			lista.pop(x);
			lista.print();
			(x == y ? resultado = true : resultado = false);
			reportePrueba(resultado);
			cout << "\n\tVariable x = " << x;
			reportePrueba(resultado);
			cout << endl;
			break;
		}
		case 7: {
			int x,y;
			cout << "Se eliminara el elemento en la ultima posicion y se almacenara en la variable x\n\t";
			lista.print();
			lista.get(lista.len(),y);
			cout << "\n\t";
			lista.pop_back(x);
			lista.print();
			(x == y ? resultado = true : resultado = false);
			reportePrueba(resultado);
			break;
		}
	    case 8:{
			int x;
			cout << "\tObtiene el elemento en la posicion indicada y lo almacena en la variable x\n\t";
			lista.print();
			lista.get(5,x);
			(x == 5 ? resultado = true : resultado = false);
			cout << "\tVariable x: " << x;
			reportePrueba(resultado);
			cout << endl;
			break;
		}
		case 9: {
			int x,y;
			cout << "\tSe obtendra el primer elemento de la lista y lo almacena en x.\n\t";
			lista.get_front(x);
			lista.print();
			lista.get(1, y);
			(x == y ? resultado = true : resultado = false);
			cout << "\tVariable x: " << x;
			reportePrueba(resultado);
			break;
		}
		case 10: {
			int x,y;
			cout << "\n\tSe almacenara el elemento de la ultima posicion de la lista en x.\n\t";
			lista.print();
			lista.get_back(x);
			lista.get(lista.len(),y);
			cout << "\tVariable x: " << x;
			(x == y ? resultado = true : resultado = false);
			reportePrueba(resultado);
			break;
		}
		case 11: {
			cout << "\n\tSe hara una impresion de una lista\n\t";
			lista.print();
			reportePrueba(true);
			break;
		}
		case 12: {
			cout << "\n\tSe hara una prueba para el funcionamiento del metodo destructor\n\t";
			lista.print();
			lista.~ListaB();
			cout << "\t";
			lista.print();
			(lista.len()==0 ? resultado = true: resultado = false);
			reportePrueba(resultado);
			break;
		}
		default:{};

		}//Switch
	}

	system("PAUSE()");
}

