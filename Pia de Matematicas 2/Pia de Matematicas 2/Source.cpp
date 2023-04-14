//#include<iostream>
//#include<string>
//#include<conio.h>
//#include<math.h>
//#include<fstream>
//using namespace std;
//
//struct matriz {
//	double numeros[10][10] = { 0 };
//	int col = 0, fila = 0, nmatr = 0;
//	matriz* sig;
//};
//
//matriz* opc1, * opc2, * resultado = new matriz;
//matriz* inicio, * aux = NULL;
//int x = 0, opc = 0;	//Es el que guarda cuantas matrices hay
//bool val = false;
//
//
//
//void agregar() {
//	if (inicio == NULL) {
//		inicio = new matriz;
//		aux = inicio;
//		aux->sig = NULL;
//		while (val == false) {
//			cout << "\n\t\t\tIngrese el numero de filas para la matriz 1: ";
//			cin >> inicio->fila;
//			cout << "\n\t\t\tIngrese el numero de columnas: ";
//			cin >> inicio->col;
//			for (int i = 0; i < inicio->fila; i++) {
//				for (int j = 0; j < inicio->col; j++) {
//					cout << "\n\t\t\tIngrese el numero de la columna " << j + 1 << " y la fila " << i + 1 << " : ";
//					cin >> inicio->numeros[i][j];
//				}
//			}
//			val = true;
//		}
//		val = false;
//		x++;
//		inicio->nmatr = x;
//		for (int i = 0; i < inicio->fila; i++) {
//			cout << "\n\t";
//			for (int j = 0; j < inicio->col; j++) {
//				cout << inicio->numeros[i][j] << "\t";
//			}
//		}
//	}
//	else {
//		aux = inicio;
//		while (aux->sig != NULL) {
//			aux = aux->sig;
//		}
//		aux->sig = new matriz;
//		aux = aux->sig;
//		aux->sig = NULL;
//		while (val == false) {
//			cout << "\n\t\t\tIngrese el numero de filas para la matriz " << x << " : ";
//			cin >> aux->fila;
//			cout << "\n\t\t\tIngrese el numero de columnas " << x << " : ";
//			cin >> aux->col;
//			for (int i = 0; i < aux->fila; i++) {	//Fila
//				for (int j = 0; j < aux->col; j++) {	//Columna
//					cout << "\n\t\t\tIngrese el numero de la columna " << j + 1 << " y la fila " << i + 1 << " : ";
//					cin >> aux->numeros[i][j];
//				}
//			}
//			val = true;
//		}
//		x++;
//		aux->nmatr = x;
//		for (int i = 0; i < aux->fila; i++) {
//			cout << "\n\t";
//			for (int j = 0; j < aux->col; j++) {
//				cout << aux->numeros[i][j] << "\t";
//			}
//		}
//	}
//	cout << "\n\n\t";
//}
//
//void suma() {	//aux.numeros[0][1]: [0] es x, [1] es y
//	aux = inicio;
//	for (int y = 0; y < x; y++) {	//va de matriz en matriz
//		cout << "\n\t\t" << aux->nmatr << endl;
//		for (int i = 0; i < aux->fila; i++) {
//			cout << "\n";
//			for (int j = 0; j < aux->col; j++) {
//				cout << "\t" << aux->numeros[i][j];
//			}
//		}
//		aux = aux->sig;
//	}
//	cout << "¿Cual es la primera matriz a sumar?  " << endl;
//	cout << "\n\t";
//	cin >> opc;
//	aux = inicio;
//
//	while (aux != NULL) {
//		if (aux->nmatr == opc) {
//			opc1 = aux;
//		}
//		aux = aux->sig;
//	}
//
//	cout << "¿Cual es la segunda matriz a sumar?  " << endl;
//	cin >> opc;
//	aux = inicio;
//	while (aux != NULL) {
//		if (aux->nmatr == opc) {
//			opc2 = aux;
//		}
//		aux = aux->sig;
//	}
//
//	for (int j = 0; j < opc1->fila; j++) {
//		for (int i = 0; i < opc2->col; i++) {
//			resultado->numeros[i][j] = opc1->numeros[i][j] + opc2->numeros[i][j];
//			cout << "\t" << resultado->numeros[i][j];
//		}
//		cout << "\n";
//	}
//	cout << "\n\n\t";
//	system("pause");
//	cout << "\n\n\t";
//}
//
//void resta() {
//	aux = inicio;
//	for (int y = 0; y < x; y++) {	//va de matriz en matriz
//		cout << "\n\t\t" << aux->nmatr << endl;
//		for (int i = 0; i < aux->fila; i++) {
//			cout << "\n";
//			for (int j = 0; j < aux->col; j++) {
//				cout << "\t" << aux->numeros[i][j];
//			}
//		}
//		aux = aux->sig;
//	}
//	cout << "¿Cual es la primera matriz a restar?  " << endl;
//	cout << "\n\t";
//	cin >> opc;
//	aux = inicio;
//
//	while (aux != NULL) {
//		if (aux->nmatr == opc) {
//			opc1 = aux;
//		}
//		aux = aux->sig;
//	}
//
//	cout << "¿Cual es la segunda matriz a restar?  " << endl;
//	cin >> opc;
//	aux = inicio;
//	while (aux != NULL) {
//		if (aux->nmatr == opc) {
//			opc2 = aux;
//		}
//		aux = aux->sig;
//	}
//
//	for (int j = 0; j < aux->fila; j++) {
//		for (int i = 0; i < aux->col; i++) {
//			resultado->numeros[i][j] = opc1->numeros[i][j] - opc2->numeros[i][j];
//			cout << "\t" << resultado->numeros[i][j];
//		}
//		cout << "\n";
//	}
//	cout << "\n\n\t";
//	system("pause");
//	cout << "\n\n\t";
//}
//
//void mult() {
//	cout << "¿Cual es la primera matriz a multiplicar?  "<< endl;
//	aux = inicio;
//	for (int y = 0; y < x; y++) {	//va de matriz en matriz
//		cout << "\n\t\t" << aux->nmatr << endl;
//		for (int i = 0; i < aux->fila; i++) {
//			cout << "\n";
//			for (int j = 0; j < aux->col; j++) {
//				cout << "\t" << aux->numeros[i][j];
//			}
//		}
//		aux = aux->sig;
//	}
//	cout << "\n\t";
//	cin >> opc;
//	aux = inicio;
//	
//	while (aux != NULL) {
//		if (aux->nmatr == opc) {
//			opc1 = aux;
//		}
//		aux = aux->sig;
//	}
//
//	cout << "¿Cual es la segunda matriz a multiplicar?  " << endl;
//	cin >> opc;
//	aux = inicio;
//	while (aux != NULL) {
//		if (aux->nmatr == opc) {
//			opc2 = aux;
//		}
//		aux = aux->sig;
//	}
//	
//	
//	resultado->fila = opc1->fila;
//	resultado->col = opc2->col;
//	if (opc1->col != opc2->fila) {
//		cout << "\n\t\t La columna de la matriz 1 es diferente a la fila de la matriz 2" << endl;
//	}
//	else {
//		for (int i = 0; i < opc1->fila; i++) {
//			for (int k = 0; k < opc2->col; k++) {
//				for (int j = 0; j < opc2->fila; j++) {
//					resultado->numeros[i][k] = resultado->numeros[i][k] + (opc1->numeros[i][j] * opc2->numeros[j][k]);
//				}
//			}
//		}
//	}
//	for (int i = 0; i < opc1->fila; i++) {
//		for (int j = 0; j < opc2->col; j++) {
//			cout << "\t" << resultado->numeros[i][j];
//		}
//		cout << "\n";
//	}
//
//}
//
///*/void load() {
//	string linea;
//	ifstream leer;
//	leer.open("matrices.txt");
//	while (!getline(leer,linea).eof()) {
//		inicio = new matriz;
//		inicio->col = stoi(linea);
//		inicio->fila = stoi(linea);
//		for (int i = 0; i < inicio->fila; i++) {
//			for (int j = 0; j < inicio->col; j++) {
//				inicio->numeros[i][j] = stoi(linea);
//			}
//		}
//		aux = aux->sig;
//		aux = new matriz;
//
//	}
//
//
//	leer.close();
//}
//*/
//
///*void guardar() {
//	aux = inicio;
//	ofstream escribir;
//	escribir.open("matrices.txt");
//
//	if (escribir.is_open()) {
//		while (aux != NULL) {
//			escribir << aux->col << endl;
//			escribir << aux->fila << endl;
//			for (int i = 0; i < aux->fila; i++) {
//				for (int j = 0; j < aux->col; j++) {
//					escribir << aux->numeros[i][j] << endl;
//				}
//			}
//			aux = aux->sig;
//		}
//		escribir.close();
//	}
//}
//*/
//
//void main() {
//	//load();
//	while (val == false) {
//		cout << "¿Que desea hacer? \n\t1.Agregar Matriz \n\t2.Sumar \n\t3.Resta \n\t4.Multi \n\t5.Salir \n\t";
//		cin >> opc;
//		switch (opc) {
//		case 1:
//			agregar();
//			val = false;
//			break;
//		case 2:
//			suma();
//			val = false;
//			break;
//		case 3:
//			resta();
//			val = false;
//			break;
//		case 4:
//			mult();
//			val = false;
//			break;
//		case 5:
//			val = true;
//			break;
//		}
//	}
//	cout << "\n";
//	
//}
