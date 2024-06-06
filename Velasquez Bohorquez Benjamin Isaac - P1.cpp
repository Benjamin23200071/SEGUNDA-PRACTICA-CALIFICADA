/*Hacer un programa que alimente solo con números entre 1 y 10 dos matrices una de 2 x 3 y la otra de 3 x 2, 
buscar aquellos números de la primera matriz que sean mayores a 5 y convertirlos a 1, y buscar aquellos 
números que sean menores a 6 de  la  segunda  matriz  y  convertirlos  a  0. (imprimir  la  primera  matriz  
y  la  modificada)*/

#include <iostream>

const int FILAS1 = 2;
const int COLUMNAS1 = 3;
const int FILAS2 = 3;
const int COLUMNAS2 = 2;

void imprimirMatriz(int matriz[][COLUMNAS1], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << matriz[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void imprimirMatriz(int matriz[][COLUMNAS2], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << matriz[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    int matriz1[FILAS1][COLUMNAS1];
    int matriz2[FILAS2][COLUMNAS2];

    std::cout << "Ingrese los numeros para la primera matriz (2x3), entre 1 y 10:\n";
    for (int i = 0; i < FILAS1; ++i) {
        for (int j = 0; j < COLUMNAS1; ++j) {
            int numero;
            do {
                std::cout << "Ingrese el numero para la posicion (" << i << ", " << j << "): ";
                std::cin >> numero;
                if (numero < 1 || numero > 10) {
                    std::cout << "Numero invalido. Debe estar entre 1 y 10.\n";
                }
            } while (numero < 1 || numero > 10);
            matriz1[i][j] = numero;
        }
    }

    std::cout << "Ingrese los numeros para la segunda matriz (3x2), entre 1 y 10:\n";
    for (int i = 0; i < FILAS2; ++i) {
        for (int j = 0; j < COLUMNAS2; ++j) {
            int numero;
            do {
                std::cout << "Ingrese el numero para la posicion (" << i << ", " << j << "): ";
                std::cin >> numero;
                if (numero < 1 || numero > 10) {
                    std::cout << "Numero invalido. Debe estar entre 1 y 10.\n";
                }
            } while (numero < 1 || numero > 10);
            matriz2[i][j] = numero;
        }
    }

    std::cout << "Primera matriz original:\n";
    imprimirMatriz(matriz1, FILAS1, COLUMNAS1);

    std::cout << "Segunda matriz original:\n";
    imprimirMatriz(matriz2, FILAS2, COLUMNAS2);

    for (int i = 0; i < FILAS1; ++i) {
        for (int j = 0; j < COLUMNAS1; ++j) {
            if (matriz1[i][j] > 5) {
                matriz1[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < FILAS2; ++i) {
        for (int j = 0; j < COLUMNAS2; ++j) {
            if (matriz2[i][j] < 6) {
                matriz2[i][j] = 0;
            }
        }
    }

    std::cout << "Primera matriz modificada:\n";
    imprimirMatriz(matriz1, FILAS1, COLUMNAS1);

    std::cout << "Segunda matriz modificada:\n";
    imprimirMatriz(matriz2, FILAS2, COLUMNAS2);

    return 0;
}

