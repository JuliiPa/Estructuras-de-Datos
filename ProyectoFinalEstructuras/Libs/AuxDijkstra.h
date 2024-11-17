#ifndef AUXDIJKSTRA_H
#define AUXDIJKSTRA_H

#include <list>
#include <string>
#include "Vertice.h"

class AuxDijkstra {
private:
    Vertice* Elemento;
    int Camino;
    double costo;
    bool visitado;
    std::list<int> Destino;

public:
    // Constructor
    AuxDijkstra(Vertice* ReferenciaElemento);

    // Getters
    Vertice* getElemento() const;
    int getCamino() const;
    double getCosto() const;
    const std::list<int>& getDestinos() const;
    bool isVisitado() const;

    // Setters
    void setCamino(int camino);
    void setCosto(double costo);
    void setVisitado(bool visitado);

    void addDestino(int destino);
};

#endif
