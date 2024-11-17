#ifndef ARISTA_H
#define ARISTA_H

#include "Vertice.h"

class Arista {
private:
    Vertice VerticeInicial;
    Vertice VerticeFinal;

public:
    // Constructor
    Arista(const Vertice& VerticeA, const Vertice& VerticeB);

    // Métodos para obtener los Vértices
    const Vertice& getVerticeInicial() const;
    const Vertice& getVerticeFinal() const;

    // Métodos para establecer los Vértices
    void setVerticeInicial(const Vertice& VerticeA);
    void setVerticeFinal(const Vertice& VerticeB);

    // Método para comparar si dos aristas son iguales
    bool sonIguales(const Arista& otraArista) const;
};

#endif
