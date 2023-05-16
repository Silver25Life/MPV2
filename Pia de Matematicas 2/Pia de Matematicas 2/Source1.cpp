#include<iostream>
#include<wchar.h>
#include<locale.h>
#include<string>
#include<conio.h>
#include<fstream>
#include<math.h>
#define PI 3.1415926536
using namespace std;

struct matriz {
	double mat[10][10] = { 0 };
	int col = 0, fila = 0, n = 0;
	matriz* sig;
};

struct compuesta {
	double compu[4][4] = { 0 };
	compuesta* cig;
};

struct traz {
	int num = 0;
	int matt[4][4] = { 0 };
	traz* tig;
};

struct esc {
	int num = 0;
	int mas[4][4] = { 0 };
	esc* ssig;
};

struct zpersp {
	double zprp = 0, zx = 0, zy = 0;
	int num = 0;
	zpersp* zig;
};

struct rota {
	int num = 0;
	float mar[4][4] = { 0 };
	rota* rig;
};

traz* tinicio = NULL, * taux = NULL;
esc* sinicio = NULL, * saux = NULL;
zpersp* zinicio = NULL, * zaux = NULL;

rota* rinicio = NULL, * raux = NULL;
int o = 0;
compuesta* cinicio = NULL, * caux = NULL;
string operacion[3] = { "sumar","restar","multiplicar" };
matriz* op1 = new matriz, * op2 = new matriz, * res = new matriz;
matriz* inicio = NULL , * aux = NULL;
int x = 0, op = 0;
bool v = true, val = true, val2 = true, val3 = true;
int tx = 0, ty = 0, tz = 0;
int sx = 0, sy = 0, sz = 0;
double angulo = 0, seno = 0, coseno = 0, rad = 0;
double  mc1[4][4] = { 0 }, mc2[4][4] = { 0 }, mcr[4][4] = { 0 };
//matrizcomp[4][4] = { 0 }
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






void comp() {
	while (val2) {
		cout << "\n\t\t Que desea hacer? \n\t 1.Trazlacion \n\t 2.Escalacion \n\t 3.Rotacion \n\t 4.Aplicar Z-Perspectiva \n\t 5.Calcular \n\t 6.Salir \n\t\t|||";
		cin >> op;
		switch (op) {
		case 1://trazlacion
			if (tinicio == NULL) {
				tinicio = new traz;
				taux = tinicio;
				taux->tig = NULL;
			}
			else {
				taux = tinicio;
				while (taux->tig != NULL) {
					taux = taux->tig;
				}
				taux->tig = new traz;
				taux = taux->tig;
				taux->tig = NULL;
			}
			cout << "\n\t\t Ingrese el valor de Tx: ";
			cin >> tx;
			cout << "\n\t\t Ingrese el valor de Ty: ";
			cin >> ty;
			cout << "\n\t\t Ingrese el valor de Tz: ";
			cin >> tz;
			taux->matt[0][3] = tx;
			taux->matt[1][3] = ty;
			taux->matt[2][3] = tz;
			for (int i = 0; i < 4; i++) {
				taux->matt[i][i] = 1;
			}
			o++;
			taux->num = o;

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <4; j++) {
					cout << "\t" << taux->matt[i][j];
				}
				cout << "\n";
			}
			cout << "\n\n\t";
			break;
		case 2: //escalacion
			if (sinicio == NULL) {
				sinicio = new esc;
				saux = sinicio;
				saux->ssig = NULL;
			}
			else {
				saux = sinicio;
				while (saux->ssig != NULL) {
					saux = saux->ssig;
				}
				saux->ssig = new esc;
				saux = saux->ssig;
				saux->ssig = NULL;
			}
			cout << "\n\t\t Ingrese el valor de Sx: ";
			cin >> sx;
			cout << "\n\t\t Ingrese el valor de Sy: ";
			cin >> sy;
			cout << "\n\t\t Ingrese el valor de Sz: ";
			cin >> sz;
			saux->mas[0][0] = sx;
			saux->mas[1][1] = sy;
			saux->mas[2][2] = sz;
			saux->mas[3][3] = 1;
			o++;
			saux->num = o;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					cout << "\t" << saux->mas[i][j];
				}
				cout << "\n";
			}
			cout << "\n\n\t";
			break;
		case 3://rotacion
			if (rinicio == NULL) {
				rinicio = new rota;
				raux = rinicio;
				raux->rig = NULL;
			}
			else {
				raux = rinicio;
				while (raux->rig != NULL) {
					raux = raux->rig;
				}
				raux->rig = new rota;
				raux = raux->rig;
				raux->rig = NULL;
			}
			cout << "\n\t\t Intrese el angulo de rotación: ";
			cin >> angulo;
			rad = angulo * PI / 180;
			coseno = cos(rad);
			seno = sin(rad);
			cout << "\n\t\t en que axis rotara? \n\t 1.x-Axis \n\t 2.y-Axis \n\t 3.z-Axis\n\t\t|||";
			cin >> op;
			switch (op) {
			case 1:
				raux->mar[0][0] = 1;
				raux->mar[1][1] = coseno;
				raux->mar[1][2] = 0 - seno;
				raux->mar[2][1] = seno;
				raux->mar[2][2] = coseno;
				raux->mar[3][3] = 1;
				break;
			case 2:
				raux->mar[0][0] = coseno;
				raux->mar[0][2] = seno;
				raux->mar[1][1] = 1;
				raux->mar[2][0] = 0 - seno;
				raux->mar[2][2] = coseno;
				raux->mar[3][3] = 1;
				break;
			case 3:
				raux->mar[0][0] = coseno;
				raux->mar[0][1] = 0 - seno;
				raux->mar[1][0] = seno;
				raux->mar[1][1] = coseno;
				raux->mar[2][2] = 1;
				raux->mar[3][3] = 1;
				break;
			}
			o++;
			raux->num = o;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					cout << "\t" << raux->mar[i][j];
				}
				cout << "\n";
			}
			cout << "\n\n\t";
			break;
		case 4://z-perspect
			break;
		case 5:
			int k = o;	//guarda cuantas indicaciones guardamos
			while (o!=0) {
				if (cinicio == NULL) {
					cinicio = new compuesta;
					caux = cinicio;
					caux->cig = NULL;
				}
				else {
					caux = cinicio;
					while (caux->cig != NULL) {
						caux = caux->cig;
					}
					caux->cig = new compuesta;
					caux = caux->cig;
					caux->cig = NULL;
				}
				//checa cada trazlación hasta encontrar "o"
				taux = tinicio;
				while (taux != NULL && taux->num != o) {
					taux = taux->tig;
				}
				if(taux != NULL && taux->num == o) { //si lo encuentra, lo guarda en una nueva matriz
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							caux->compu[i][j] = taux->matt[i][j];
						}
					}
					o--;
				}
				//checa cada escalación hasta encontrar "o"
				saux = sinicio;
				while (saux != NULL && saux->num != o) {
					saux = saux->ssig;
				}
				if (saux!=NULL && saux->num == o) { //si lo encuentra, lo guarda en una nueva matriz
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							caux->compu[i][j] = saux->mas[i][j];
						}
					}
					o--;
				}
				//checa cada rotacion hasta encontrar "o"
				raux = rinicio;
				while (raux != NULL && raux->num != o) {
					raux = raux->rig;
				}
				if (raux != NULL && raux->num == o) { //si lo encuentra, lo guarda en una nueva marriz
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							caux->compu[i][j] = raux->mar[i][j];
						}
					}
					o--;
				}
			}
			caux = cinicio;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mc1[i][j] = caux->compu[i][j];
				}
			}
			caux = caux->cig;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mc2[i][j] = caux->compu[i][j];
				}
			}
			while (o != k) {
				double matrizcomp[4][4] = { 0 };
				for (int i = 0; i < 4; i++) {
					for (int h = 0; h < 4; h++) {
						for (int j = 0; j < 4; j++) {
							matrizcomp[i][h] = matrizcomp[i][h] + (mc1[i][j] * mc2[j][h]);
						}
					}
				}
				caux = caux->cig;
				o++;
				if (o != k) {
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							mc1[i][j] = matrizcomp[i][j];
							if (caux != NULL) {
								mc2[i][j] = caux->compu[i][j];
							}
							else {
								o = k;
							}
						}
					}
				}
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mcr[i][j] = mc1[i][j];
				}
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					cout << "\t" << mcr[i][j];
				}
				cout << "\n";
			}
			cout << "\n\n\t";
			break;
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
		cout << "\n\t\t Que desea hacer? \n\t 1.Agregar matriz \n\t 2.Sumar \n\t 3.Restar \n\t 4.Multiplicar \n\t 5.Ingresar matriz compuesta \n\t 6.Salir.\n\t\t|||";
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
			comp();
			break;
		case 6:
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