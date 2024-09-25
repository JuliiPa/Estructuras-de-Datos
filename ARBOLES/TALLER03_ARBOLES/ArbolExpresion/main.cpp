#include <iostream>
#include "ArbolExpresion.h"
#include "NodoExpresion.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "EJERCICIO 1" << endl;
    cout << endl;
    cout << "1. Construir Arbol Expresion (Prefija): " << endl;
    cout << "+12" << endl;  // Expresión prefija simple
    ArbolExpresion* arbexp = new ArbolExpresion();
    string exp = "+12";
    arbexp->llenarDesdePrefija(exp);

    cout << "2. Imprimir Version Posfija = " << endl;
    arbexp->obtenerPosfija(arbexp->getRaiz());
    cout << endl;
    cout << "3. Imprimir Resultado = " << endl;
    cout << arbexp->evaluar(arbexp->getRaiz()) << endl;
    cout << endl;

    cout << "EJERCICIO 2" << endl;
    cout << endl;
    cout << "1. Construir Arbol Expresion (Posfija): " << endl;
    cout << "12+" << endl;  // Expresión posfija simple
    ArbolExpresion* arbexp2 = new ArbolExpresion();
    string exp2 = "12+";
    arbexp2->llenarDesdePosfija(exp2);

    cout << "2. Imprimir Version Prefija = " << endl;
    arbexp2->obtenerPrefija(arbexp2->getRaiz());
    cout << endl;
    cout << "3. Imprimir Resultado = " << endl;
    cout << arbexp2->evaluar(arbexp2->getRaiz()) << endl;
    cout << endl;

    return 0;
}
