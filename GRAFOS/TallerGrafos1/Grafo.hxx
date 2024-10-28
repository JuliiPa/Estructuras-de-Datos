/************************************
 Fecha: 16/10/2024
 Nombre:JULIANA PACHECO AMAYA
 Tema: Implementacion Basica de Grafos
 ************************************/

#include "Grafo.h"
#ifndef GRAFO_HXX
#define GRAFO_HXX

#include <iomanip>

using namespace std;

template <typename T, typename W>
Grafo<T, W>::Grafo(bool dirigido, bool ponderado)
    : numVertices(0), numAristas(0), esDirigido(dirigido), esPonderado(ponderado) {}

template <typename T, typename W>
Grafo<T, W>::~Grafo() {
    for (auto vertice : vertices) {
        delete vertice;
    }
    for (auto& fila : matrizAdyacencia) {
        for (auto arista : fila) {
            delete arista;
        }
    }
}

template <typename T, typename W>
void Grafo<T, W>::agregarVertice(T dato) {
    Vertice<T>* nuevoVertice = new Vertice<T>(dato, numVertices);
    vertices.push_back(nuevoVertice);

    matrizAdyacencia.push_back(vector<Arista<W>*>(numVertices + 1, nullptr));
    for (auto& fila : matrizAdyacencia) {
        fila.resize(numVertices + 1, nullptr);
    }

    numVertices++;
}

template <typename T, typename W>
void Grafo<T, W>::agregarArista(int indice1, int indice2, W peso) {
    if (indice1 >= numVertices || indice2 >= numVertices) {
        cerr << "Índices fuera de rango." << std::endl;
        return;
    }

    Arista<W>* nuevaArista = new Arista<W>(peso);
    matrizAdyacencia[indice1][indice2] = nuevaArista;

    if (!esDirigido) { // Solo agrega la arista inversa si no es dirigido
        matrizAdyacencia[indice2][indice1] = nuevaArista;
    }

    numAristas++;
}

template <typename T, typename W>
void Grafo<T, W>::imprimirGrafo() {
    cout << "Matriz de adyacencia: " << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (matrizAdyacencia[i][j] != nullptr) {
                cout << setw(4) << matrizAdyacencia[i][j]->peso << " ";
            } else {
                cout << setw(4) << "-" << " ";
            }
        }
        cout << endl;
    }

    cout << "\nVertices:" << std::endl;
    for (auto vertice : vertices) {
        cout << "Vertice " << vertice->indice << ": " << vertice->dato << std::endl;
    }
}

// Obtener la cantidad de vértices
template <typename T, typename W>
int Grafo<T, W>::obtenerCantidadVertices() const {
    return numVertices;
}

// Obtener la cantidad de aristas
template <typename T, typename W>
int Grafo<T, W>::obtenerCantidadAristas() const {
    return numAristas;
}

// Buscar un vértice por su dato
template <typename T, typename W>
Vertice<T>* Grafo<T, W>::buscarVertice(T dato) const {
    for (auto vertice : vertices) {
        if (vertice->dato == dato) {
            return vertice;
        }
    }
    return nullptr; // No se encontró el vértice
}

// Buscar una arista entre dos vértices
template <typename T, typename W>
Arista<W>* Grafo<T, W>::buscarArista(int indice1, int indice2) const {
    if (indice1 >= numVertices || indice2 >= numVertices) {
        return nullptr; // Índices fuera de rango
    }

    return matrizAdyacencia[indice1][indice2]; // Retorna la arista o nullptr si no existe
}

// Retorna si el grafo es dirigido
template <typename T, typename W>
bool Grafo<T, W>::esGrafoDirigido() const {
    return esDirigido;
}

// Retorna si el grafo es ponderado
template <typename T, typename W>
bool Grafo<T, W>::esGrafoPonderado() const {
    return esPonderado;
}

#endif // GRAFO_HXX

