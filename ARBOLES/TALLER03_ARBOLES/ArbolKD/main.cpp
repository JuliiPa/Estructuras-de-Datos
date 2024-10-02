/************************************
 Nombres: JULIANA PACHECO, DANIEL GONZALES, NICOLAS ALGARA
 TEMA: TALLER ARBOLES
 FECHA: 24/09/2024
 ***********************************/
#include "Arbol.h"
#include <iostream>
#include <vector>

void printRecorrido(const std::string& recorrido) {
    std::cout << recorrido << std::endl;
}

int main() {
    // Crear un KDTree de 2 dimensiones
    KDTree arbol(2);

    // Agregar algunos puntos al árbol
    arbol.AgregarNodoAlArbol({3.0, 6.0});
    arbol.AgregarNodoAlArbol({2.0, 7.0});
    arbol.AgregarNodoAlArbol({17.0, 15.0});
    arbol.AgregarNodoAlArbol({6.0, 12.0});
    arbol.AgregarNodoAlArbol({9.0, 1.0});
    arbol.AgregarNodoAlArbol({2.0, 4.0});
    arbol.AgregarNodoAlArbol({10.0, 19.0});
    std::cout<<"Hola"<<std::endl;

    // Probar búsqueda de algunos puntos
    std::vector<double> puntoABuscar = {10.0, 19.0};
    std::cout << "Buscando el punto " << puntoABuscar[0] << ", " << puntoABuscar[1] << ": "
              << (arbol.buscarNodo(puntoABuscar) ? "Encontrado" : "No encontrado") << std::endl;

    puntoABuscar = {5.0, 5.0};
    std::cout << "Buscando el punto " << puntoABuscar[0] << ", " << puntoABuscar[1] << ": "
              << (arbol.buscarNodo(puntoABuscar) ? "Encontrado" : "No encontrado") << std::endl;

    // Realizar y mostrar recorridos
    std::cout << "Recorrido en Preorden: ";
    printRecorrido(arbol.preOrder(arbol.getraiz(),""));

    std::cout << "Recorrido en Inorden: ";
    printRecorrido(arbol.inOrder(arbol.getraiz(),""));

    std::cout << "Recorrido en Postorden: ";
    printRecorrido(arbol.postOrder(arbol.getraiz(),""));

    return 0;
}
