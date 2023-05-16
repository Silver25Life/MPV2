#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>   // nuevas librerias necesarias para las operaciones en cuestion relacionados con la matriz
//#include <Eigen/Dense> // nueva libreria necesaria para los quaterniones
#include <cstdlib> // librerira para las curvas pixeladas

using namespace std;
//using namespace Eigen; //parte de la nueva libreria <Eigen/Dense>

vector<vector<int>> matrix;

void bresenham(int x1, int y1, int x2, int y2);

void enterMatrix() {  // para crear una nueva matriz [ exclusivamente solo para 4x4 ]
    int size = 4;

    matrix.resize(size, vector<int>(size));

    cout << "Ingrese los elementos de la matriz:" << endl;  // se ingresa los numeros para la matriz en cuestion
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matriz ingresada:" << endl; // se muestra la matriz en su ubicacion correspondiente gracias a la libreria de vector y algoritmo
    for (auto row : matrix) {
        for (auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

void translateMatrix() {
    if (matrix.empty()) { //aqui se hace la traslacion
        cout << "No se ha ingresado una matriz." << endl;
        return;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    int x, y, z;
    cout << "Ingrese los valores de traslacion (x y z): "; //se ingresa los numeros por separado para evitar confuciones
    cout << "Ingrese x ";
    cin >> x;
    cout << "Ingrese y ";
    cin >> y;
    cout << "Ingrese z ";
    cin >> z;

    vector<vector<int>> translated(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            translated[i][j] = matrix[i][j]; // el j representa el numero en columnas
            if (j ==3) {
                if (i == 0) {                // el i representa el numero en filas
                    translated[i][j] += x;   // si las 2 variables concuerdan, se hace la tecnica rapida de solo sumar dicho numero con la coordenada
                }
            }
            if (j == 3) {
                if (i == 1) {
                    translated[i][j] += y;
                }
            }
            if (j == 3) {
                if (i == 2) {
                    translated[i][j] += z;
                }
            }
        }
    }

    cout << "Matriz trasladada:" << endl;
    for (auto row : translated) {
        for (auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    matrix = translated;
}
void ScaleMatrix() {
    if (matrix.empty()) {
        cout << "No se ha ingresado una matriz." << endl;    //codigo similar a la traslacion, esto se debe a que realizan funciones similares
        return;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    int x, y, z;
    cout << "Ingrese los valores de Escalacion (x y z): ";
    cout << "Ingrese x ";
    cin >> x;
    cout << "Ingrese y ";
    cin >> y;
    cout << "Ingrese z ";
    cin >> z;

    vector<vector<int>> scaled(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scaled[i][j] = matrix[i][j];
            if (j == 3) {
                if (i == 0) {
                    scaled[i][j] *= x;      //la diferencia con el otro codigo es que se multiplica en vez de sumar
                }
            }
            if (j == 3) {
                if (i == 1) {
                    scaled[i][j] *= y;
                }
            }
            if (j == 3) {
                if (i == 2) {
                    scaled[i][j] *= z;
                }
            }
        }
    }

    cout << "Matriz Escalado:" << endl;
    for (auto row : scaled) {
        for (auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    matrix = scaled;
}
void Quart() { // para generar quaterniones [ aun en beta y en investigacion ]
    double qw, qx, qy, qz;
    cout << "Ingrese los valores del cuaternion (w x y z): ";
    cin >> qw >> qx >> qy >> qz;
    Quaterniond q(qw, qx, qy, qz);

    double vx, vy, vz;
    cout << "Ingrese los valores del vector (x y z): ";
    cin >> vx >> vy >> vz;
    Vector3d v(vx, vy, vz);

    cout << "Cuaternion q: " << q.coeffs().transpose() << endl;
    cout << "Vector v: " << v.transpose() << endl;

    Vector3d v_new = q * v;

    cout << "Nuevas coordenadas v': " << v_new.transpose() << endl;
}
void Bresen() {
    int x1, y1, x2, y2;

    cout << "Ingrese el primer punto (x, y): ";
    cin >> x1 >> y1;

    cout << "Ingrese el segundo punto (x, y): ";
    cin >> x2 >> y2;

    bresenham(x1, y1, x2, y2);

}

void bresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;
    int e2;

    while (true) {
        cout << "(" << x1 << ", " << y1 << ")" << endl;
        if (x1 == x2 && y1 == y2) {
            break;
        }
        e2 = 2 * err;
        if (e2 > -dy) {
            err = err - dy;
            x1 = x1 + sx;
        }
        if (e2 < dx) {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
}

int main() { //el menu principal
    int choice;

    while (true) {
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Ingresar una matriz 4x4 [requisito para usar las otras opciones de x y z]" << endl; //para generar una matriz
        cout << "2. Realizar una traslacion en x y z" << endl; 
        cout << "3. Realizar un Escalamiento en x y z" << endl;
        cout << "4. quaterniones" << endl;
        cout << "5. Trazos de curvas a traves de Bresenham" << endl;
        cout << "6. Salir de la Aplicacion" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            enterMatrix();
            break;
        case 2:
            translateMatrix();
            break;
        case 3:
            ScaleMatrix();
        case 4:
            Quart();
        case 5:
            Bresen();
        case 6:
            return 0;
        default:
            cout << "Opción invalida." << endl;
        }
    }
}