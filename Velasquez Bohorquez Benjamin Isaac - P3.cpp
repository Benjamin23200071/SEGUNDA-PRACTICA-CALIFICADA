/*.Desarrollar un programa en C++ que permita ingresar y almacenar el código, el nombre,  
nota  1,  nota  2  y  nota  3  de  un  curso.  Mostrar  el  promedio  de  cada  estudiante 
y la cantidad de estudiantes desaprobados. Finalmente, ordene los datos en base de los promedios. 
Muestre los datos ordenados.*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Alumno {
    int codigo;
    string nombre;
    double nota1;
    double nota2;
    double nota3;
    double promedio;
};

double calcularPromedio(double nota1, double nota2, double nota3) {
    return (nota1 + nota2 + nota3) / 3;
}

bool compararPromedios(const Alumno &a, const Alumno &b) {
    return a.promedio > b.promedio;
}

int main() {
    int numAlumnos;
    cout << "Ingrese el numero de alumnos: ";
    cin >> numAlumnos;

    vector<Alumno> alumnos(numAlumnos);
    int cantidadDesaprobados = 0;

    for (int i = 0; i < numAlumnos; ++i) {
        cout << "Ingrese el codigo del alumno " << i + 1 << ": ";
        cin >> alumnos[i].codigo;
        cin.ignore();
        cout << "Ingrese el nombre del alumno " << i + 1 << ": ";
        getline(cin, alumnos[i].nombre);
        cout << "Ingrese la nota 1 del alumno " << i + 1 << ": ";
        cin >> alumnos[i].nota1;
        cout << "Ingrese la nota 2 del alumno " << i + 1 << ": ";
        cin >> alumnos[i].nota2;
        cout << "Ingrese la nota 3 del alumno " << i + 1 << ": ";
        cin >> alumnos[i].nota3;
        alumnos[i].promedio = calcularPromedio(alumnos[i].nota1, alumnos[i].nota2, alumnos[i].nota3);

        if (alumnos[i].promedio < 10.5) {
            ++cantidadDesaprobados;
        }
    }

    cout << "\nPromedio de cada estudiante:\n";
    for (int i = 0; i < numAlumnos; ++i) {
        cout << "Codigo: " << alumnos[i].codigo << ", Nombre: " << alumnos[i].nombre << ", Promedio: " << alumnos[i].promedio << endl;
    }

    cout << "\nCantidad de estudiantes desaprobados: " << cantidadDesaprobados << endl;

    sort(alumnos.begin(), alumnos.end(), compararPromedios);

    cout << "\nDatos ordenados por promedio:\n";
    for (int i = 0; i < numAlumnos; ++i) {
        cout << "Codigo: " << alumnos[i].codigo << ", Nombre: " << alumnos[i].nombre << ", Nota 1: " << alumnos[i].nota1
             << ", Nota 2: " << alumnos[i].nota2 << ", Nota 3: " << alumnos[i].nota3 << ", Promedio: " << alumnos[i].promedio << endl;
    }

    return 0;
}



