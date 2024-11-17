#include "Objeto.h"

// Constructor
Objeto::Objeto(std::string &nombre) : nombre(nombre) {}

// Métodos get y set para nombre
std::string Objeto::getNombre()
{
    return nombre;
}

void Objeto::setNombre(std::string &nuevoNombre)
{
    nombre = nuevoNombre;
}

// Métodos para agregar y obtener caras
void Objeto::agregarCara(Cara &cara)
{
    caras.push_back(cara);
}

std::list<Cara> &Objeto::getCaras()
{
    return caras;
}

std::list<Vertice> &Objeto::getVertices()
{
    return vertices;
}

void Objeto::setVertices(std::list<Vertice> &nuevosVertices)
{
    vertices = nuevosVertices;
}
std::list<Arista>& Objeto::getAristas()
{
    return aristas;
}
void Objeto::setAristas(std::list<Arista> &nuevosAristas)
{
    aristas=nuevosAristas;
}
void Objeto::agregarArista(Arista arista)
{
    aristas.push_back(arista);
}
void Objeto::agregarVertice(Vertice vertice)
{
    vertices.push_back(vertice);
}
