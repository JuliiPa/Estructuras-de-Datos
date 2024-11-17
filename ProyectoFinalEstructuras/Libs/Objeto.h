#ifndef OBJETO_H
#define OBJETO_H

#include "Cara.h"
#include <list>
#include <string>

class Objeto
{
private:
    std::string nombre;
    std::list<Cara> caras;
    std::list<Vertice> vertices;
    std::list<Arista> aristas;

public:
    // Constructor
    Objeto(std::string &nombre);

    // Métodos get y set para nombre
    std::string getNombre();
    void setNombre(std::string &nuevoNombre);

    // Métodos para agregar, eliminar y obtener caras
    void agregarCara(Cara &cara);

    std::list<Cara> &getCaras();
    std::list<Vertice> &getVertices();
    void setVertices(std::list<Vertice> &nuevosVertices);
    std::list<Arista> &getAristas();
    void setAristas(std::list<Arista> &nuevosAristas);

    void agregarVertice(Vertice vertice);
    void agregarArista(Arista arista);
};

#endif