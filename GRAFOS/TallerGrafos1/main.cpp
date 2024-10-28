/************************************
 Fecha: 16/10/2024
 Nombre:JULIANA PACHECO AMAYA
 Tema: Implementacion Basica de Grafos
 ************************************/

#include "Grafo.h"

int main() {
    // Crear un grafo no dirigido y ponderado
    Grafo<string, int> g1(false, true); // No dirigido y ponderado
    g1.agregarVertice("A");
    g1.agregarVertice("B");
    g1.agregarArista(0, 1, 10);

    g1.imprimirGrafo();
    cout << "Es dirigido: " << (g1.esGrafoDirigido() ? "Sí" : "No") << endl;
    cout << "Es ponderado: " << (g1.esGrafoPonderado() ? "Sí" : "No") << endl;

    return 0;
}
