/*Desarrollar un programa en C++ que gestione los datos de empleados, diferenciando entre empleados 
contratados y nombrados. El programa debe solicitar al usuario el nombre, tipo de empleado 
(C-contratado o N-nombrado) y sueldo básico de cada empleado, calcular sus deducciones de 
AFP (8%) y seguro (5%) del sueldo, aplicar una bonificación según el tipo de empleado 
(C=8% O N= 12% al sueldo básico), y determinar el sueldo neto. Finalmente, debe mostrar 
los detalles de cada empleado y proporcionar un resumen consolidado de la cantidad de empleados 
y el total acumulado de sueldos netos para ambos tipos de empleados.*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int max_emple = 100;

    string nombres[max_emple];
    char tipos[max_emple];
    double sbasico[max_emple];
    double AFP[max_emple];
    double seguro[max_emple];
    double boni[max_emple];
    double sneto[max_emple];

    int ccontratados = 0, cnombrados = 0;
    double totalsueldocontra = 0.0, totalsueldonombra = 0.0;

    int nempleados;
    cout << "Ingrese el número de empleados: ";
    cin >> nempleados;

    for (int i = 0; i < nempleados; ++i) {
        cout << "Empleado #" << i + 1 << ":\n";
        cout << "Nombre: ";
        cin >> nombres[i];
        cout << "Tipo de empleado (C-contratado, N-nombrado): ";
        cin >> tipos[i];
        cout << "Sueldo basico: ";
        cin >> sbasico[i];

        AFP[i] = sbasico[i] * 0.08;
        seguro[i] = sbasico[i] * 0.05;

        if (tipos[i] == 'C' || tipos[i] == 'c') {
            boni[i] = sbasico[i] * 0.08;
            sneto[i] = sbasico[i] - AFP[i] - seguro[i] + boni[i];
            ++ccontratados;
            totalsueldocontra += sneto[i];
        } else if (tipos[i] == 'N' || tipos[i] == 'n') {
            boni[i] = sbasico[i] * 0.12;
            sneto[i] = sbasico[i] - AFP[i] - seguro[i] + boni[i];
            ++cnombrados;
            totalsueldonombra += sneto[i];
        } else {
            cout << "Tipo de empleado no valido.\n";
            --i; 
        }
    }

    cout << "\nDetalles de los empleados:\n";
    for (int i = 0; i < nempleados; ++i) {
        cout << "Empleado #" << i + 1 << ":\n";
        cout << "Nombre: " << nombres[i] << "\n";
        cout << "Tipo: " << tipos[i] << "\n";
        cout << "Sueldo basico: " << sbasico[i] << "\n";
        cout << "AFP: " << AFP[i] << "\n";
        cout << "Seguro: " << seguro[i] << "\n";
        cout << "Bonificacion: " << boni[i] << "\n";
        cout << "Sueldo Neto: " << sneto[i] << "\n\n";
    }

    cout << "Resumen consolidado:\n";
    cout << "Cantidad de empleados contratados: " << ccontratados << "\n";
    cout << "Total sueldos netos de empleados contratados: " << totalsueldocontra << "\n";
    cout << "Cantidad de empleados nombrados: " << cnombrados << "\n";
    cout << "Total sueldos netos de empleados nombrados: " << totalsueldonombra << "\n";

    return 0;
}

