#include<iostream>
#include<wchar.h>
#include<locale.h>
#include<string>
#include<conio.h>
#include<fstream>
#include<math.h>
using namespace std;

struct matriz {
	double mat[10][10] = { 0 };
	int col = 0, fila = 0, n = 0;
	matriz* sig;
};
string operacion[3] = { "sumar","restar","multiplicar" };
matriz* op1 = new matriz, * op2 = new matriz, * res = new matriz;
matriz* inicio = NULL , * aux = NULL;
int x = 0, op = 0;
bool v = true, val = true;
//Guardar como otra matriz el resultado de las primeras dos
void load() {
	ifstream leer;
	leer.open("matrices.txt");
	if (leer.fail()) {
		leer.close();
		ofstream guardar;
		guardar.open("matrices.txt");
		guardar.close();
		ifstream leer;
		leer.open("matrices.txt");
	}
	string linea;
	if (!getline(leer, linea).eof() && linea != ""){
		if (inicio == NULL) {
		inicio = new matriz;
		aux = inicio;
		aux->sig = NULL;
	}
		x = stoi(linea);
		while (!getline(leer,linea).eof()) {
			aux->n = stoi(linea);
			getline(leer, linea);
			aux->fila = stoi(linea);
			getline(leer, linea);
			aux->col = stoi(linea);
			for (int i = 0; i < aux->fila; i++) {
				for (int j = 0; j < aux->col; j++) {
					getline(leer, linea);
					if (linea == "") {
						aux->mat[i][j] = 0;
					}
					else {
						aux->mat[i][j] = stod(linea);
					}
				}
			}
			aux->sig = new matriz;
			aux = aux->sig;
			aux->sig = NULL;
		}
	aux = inicio;
	while (aux->sig->col != 0) {
		aux = aux->sig;
	}
	delete aux->sig->sig;
	aux->sig = NULL;
	}
	leer.close();
}

void save() {
	aux = inicio;
	ofstream guardar;
	guardar.open("matrices.txt");
	guardar << x << endl;
	while (aux != NULL) {
		guardar << aux->n << endl;
		guardar << aux->fila << endl;
		guardar << aux->col << endl;
		for (int i = 0; i < aux->fila; i++) {
			for (int j = 0; j < aux->col; j++) {
				char buffer[50] = { 0 };
				if (aux->mat[i][j] != '\0') {
					sprintf_s(buffer, "%.15g", aux->mat[i][j]);
				}
				guardar << buffer << endl;
			}
		}
		aux = aux->sig;
	}
	guardar.close();
}

void mostrar() {
	int opc;
	aux = inicio;
	for (int y = 0; y < x; y++) {
		cout << "\n\t\t" << aux->n << endl;
		for (int i = 0; i < aux->fila; i++) {
			cout << "\n";
			for (int j = 0; j < aux->col; j++) {
				cout << "\t" << aux->mat[i][j];
			}
		}
		aux = aux->sig;
	}
	cout << "\n\n\t\t Cual es la primera matriz a " << operacion[op-2] << "? :";
	cin >> opc;
	aux = inicio;

	while (aux != NULL) {
		if (aux->n == opc) {
			op1 = aux;
		}
		aux = aux->sig;
	}
	cout << "\n\n\t\t Cual es la segunda matriz a " << operacion[op-2] << "? :";
	cin >> opc;
	aux = inicio;

	while (aux != NULL) {
		if (aux->n == opc) {
			op2 = aux;
		}
		aux = aux->sig;
	}
}

void agregar() {
	if (inicio == NULL) {
		inicio = new matriz;
		aux = inicio;
		aux->sig = NULL;
	}
	else {
		aux = inicio;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = new matriz;
		aux = aux->sig;
		aux->sig = NULL;
	}
	while (val) {
		cout << "\n\t\t\t Ingrese el numero de filas para la matriz " << x + 1 << " : ";
		cin >> aux->fila;
		cout << "\n\t\t\t Ingrese el numero de columnas para la matriz " << x + 1 << " : ";
		cin >> aux->col;
		for (int i = 0; i < aux->fila; i++) {
			for (int j = 0; j < aux->col; j++) {
				cout << "\n\t\t\t Ingrese el numero de la columna " << j + 1 << " y la fila " << i + 1 << " : ";
				cin >> aux->mat[i][j];
			}
		}
		val = false;
	}
	x++;
	aux->n = x;
}

void suma() {
	mostrar();
	if (op1->fila != op2->fila || op1->col != op2->col) {
		cout << "No se pueden sumar, son de diferentes tamaños \n\n\n\t";
	}
	else {
		aux = inicio;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = new matriz;
		aux = aux->sig;
		aux->sig = NULL;
		aux->col = op1->col;
		aux->fila = op1->fila;
		x++;
		aux->n = x;
		for (int i = 0; i < op1->fila; i++) {
			for (int j = 0; j < op1->col; j++) {
				aux->mat[i][j] = op1->mat[i][j] + op2->mat[i][j];
			}
		}
	}
}

void resta() {
	mostrar();
	if (op1->fila != op2->fila || op1->col != op2->col) {
		cout << "No se pueden restar, son de diferentes tamaños \n\n\n\t";
	}
	else {
		aux = inicio;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = new matriz;
		aux = aux->sig;
		aux->sig = NULL;
		aux->col = op1->col;
		aux->fila = op1->fila;
		x++;
		aux->n = x;
		for (int i = 0; i < op1->fila; i++) {
			for (int j = 0; j < op1->col; j++) {
				aux->mat[i][j] = op1->mat[i][j] - op2->mat[i][j];
			}
		}
	}
}

void mult() {
	mostrar();
	if (op1->col != op2->fila) {
		cout << "\n\t\t No se pueden multiplicar \n\t\t La columna de la matriz 1 es diferente a la fila de la matriz 2" << endl;
	}
	else {
		aux = inicio;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = new matriz;
		aux = aux->sig;
		aux->sig = NULL;
		aux->fila = op1->fila;
		aux->col = op2->col;
		x++;
		aux->n = x;
		for (int i = 0; i < op1->fila; i++) {
			for (int k = 0; k < op2->col; k++) {
				for (int j = 0; j < op2->fila; j++) {
					aux->mat[i][k] = aux->mat[i][k] + (op1->mat[i][j] * op2->mat[j][k]);
				}
			}
		}
	}
}

void main() {
	setlocale(LC_ALL, "");
	load();
	while (val) {
		cout << "\n\t\t Que desea hacer? \n\t 1.Agregar matriz \n\t 2.Sumar \n\t 3.Restar \n\t 4.Multiplicar \n\t 5.Salir.\n\t\t|||";
		cin >> op;
		switch (op) {
		case 1:
			agregar();
			break;
		case 2:
			suma();
			break;
		case 3:
			resta();
			break;
		case 4:
			mult();
			break;
		case 5:
			val = false;
			v = false;
			break;
		}
		if (v) {
			system("cls");
			val = true;
			for (int i = 0; i < aux->fila; i++) {
				for (int j = 0; j < aux->col; j++) {
					cout << "\t" << aux->mat[i][j];
				}
				cout << "\n";
			}
				cout << "\n\n\t";
		}
	}
	save();
}