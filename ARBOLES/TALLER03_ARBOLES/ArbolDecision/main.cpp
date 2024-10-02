/************************************
 Nombres: JULIANA PACHECO, DANIEL GONZALES, NICOLAS ALGARA
 TEMA: TALLER ARBOLES
 FECHA: 24/09/2024
 ***********************************/
#include <iostream>
#include <string>

using namespace std;

// Definición de la estructura para un nodo del árbol de decisión
struct Nodo {
    string pregunta; // Pregunta o condición en el nodo
    Nodo* si;       // Subárbol si la respuesta es "sí"
    Nodo* no;       // Subárbol si la respuesta es "no"
};

// TAD Árbol de Decisión
class ArbolDecision {
private:
    Nodo* raiz; // Raíz del árbol

    // Función recursiva para liberar la memoria del árbol
    void liberarArbol(Nodo* nodo) {
        if (nodo != nullptr) {
            liberarArbol(nodo->si);
            liberarArbol(nodo->no);
            delete nodo;
        }
    }

    // Función recursiva para realizar el árbol de decisión
    void decision(Nodo* nodo) {
        if (nodo->si == nullptr && nodo->no == nullptr) {
            cout << "Decisión final: " << nodo->pregunta << endl; // Imprimir la decisión final
            return;
        }

        string respuesta;
        cout << nodo->pregunta << " (si/no): ";
        cin >> respuesta;

        if (respuesta == "si") {
            decision(nodo->si);
        } else {
            decision(nodo->no);
        }
    }

public:
    // Constructor
    ArbolDecision() {
        raiz = nullptr;
    }

    // Destructor
    ~ArbolDecision() {
        liberarArbol(raiz);
    }

    // Método para crear un nodo
    Nodo* crearNodo(string pregunta) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->pregunta = pregunta;
        nuevoNodo->si = nullptr;
        nuevoNodo->no = nullptr;
        return nuevoNodo;
    }

    // Método para establecer la raíz del árbol
    void establecerRaiz(Nodo* nodo) {
        raiz = nodo;
    }

    // Método para iniciar la toma de decisiones
    void iniciarDecision() {
        if (raiz != nullptr) {
            decision(raiz);
        } else {
            cout << "El árbol está vacío." << endl;
        }
    }
};

// Función para construir un ejemplo de árbol de decisión
void construirArbolEjemplo(ArbolDecision &arbol) {
    Nodo* raiz = arbol.crearNodo("¿Es un animal?");
    Nodo* nodoSi = arbol.crearNodo("¿Es un mamífero?");
    Nodo* nodoNo = arbol.crearNodo("¿Es una planta?");
    Nodo* nodoSiMamifero = arbol.crearNodo("Es un perro.");
    Nodo* nodoNoMamifero = arbol.crearNodo("Es un pez.");
    Nodo* nodoSiPlanta = arbol.crearNodo("Es un roble.");
    Nodo* nodoNoPlanta = arbol.crearNodo("Es un mineral.");

    raiz->si = nodoSi;
    raiz->no = nodoNo;
    nodoSi->si = nodoSiMamifero;
    nodoSi->no = nodoNoMamifero;
    nodoNo->si = nodoSiPlanta;
    nodoNo->no = nodoNoPlanta;

    arbol.establecerRaiz(raiz);
}

int main() {
    ArbolDecision arbol;
    construirArbolEjemplo(arbol); // Construir un ejemplo de árbol
    arbol.iniciarDecision(); // Iniciar la toma de decisiones
    return 0;
}

