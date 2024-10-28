/************************************
 Fecha: 16/10/2024
 Nombre:JULIANA PACHECO AMAYA
 Tema: Implementacion Basica de Grafos
 ************************************/

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include "Vertice.h"
#include "Arista.h"

using namespace std;

template <typename T, typename W>
class Grafo {
private:
    vector<Vertice<T>*> vertices;
    vector<vector<Arista<W>*>> matrizAdyacencia;
    int numVertices;
    int numAristas;
    bool esDirigido;  // Variable para saber si es dirigido
    bool esPonderado; // Variable para saber si es ponderado

public:
    Grafo(bool dirigido = false, bool ponderado = true);  // Constructor con parámetros
    ~Grafo();

    void agregarVertice(T dato);
    void agregarArista(int indice1, int indice2, W peso);
    void imprimirGrafo();

    // Nuevas funciones
    int obtenerCantidadVertices() const;
    int obtenerCantidadAristas() const;
    Vertice<T>* buscarVertice(T dato) const;
    Arista<W>* buscarArista(int indice1, int indice2) const;

    // Funciones para saber si es dirigido o ponderado
    bool esGrafoDirigido() const;
    bool esGrafoPonderado() const;
};

#include "Grafo.hxx"
#endif // GRAFO_H
