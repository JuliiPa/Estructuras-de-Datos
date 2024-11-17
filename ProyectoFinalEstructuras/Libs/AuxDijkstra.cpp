#include "AuxDijkstra.h"
#include <limits>
#include <string>

AuxDijkstra::AuxDijkstra(Vertice *ReferenciaElemento)
{
    Elemento = ReferenciaElemento;
    Camino = -1;
    costo = std::numeric_limits<double>::infinity();
    visitado = false;
}

// Getters
Vertice *AuxDijkstra::getElemento() const
{
    return Elemento;
}

int AuxDijkstra::getCamino() const
{
    return Camino;
}

double AuxDijkstra::getCosto() const
{
    return costo;
}

bool AuxDijkstra::isVisitado() const
{
    return visitado;
}
const std::list<int>& AuxDijkstra::getDestinos() const
{
    return Destino;
}

// Setters

void AuxDijkstra::setCamino(int camino)
{
    Camino = camino;
}

void AuxDijkstra::setCosto(double nuevoCosto)
{
    costo = nuevoCosto;
}

void AuxDijkstra::setVisitado(bool nuevoVisitado)
{
    visitado = nuevoVisitado;
}

void AuxDijkstra::addDestino(int destino)
{
    Destino.push_back(destino);
}