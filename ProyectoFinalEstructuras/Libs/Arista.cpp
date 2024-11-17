#include "Arista.h"

// Constructor
Arista::Arista(const Vertice& VerticeA, const Vertice& VerticeB)
    : VerticeInicial(VerticeA), VerticeFinal(VerticeB) {}

// Métodos para obtener los Vértices
const Vertice& Arista::getVerticeInicial() const {
    return VerticeInicial;
}

const Vertice& Arista::getVerticeFinal() const {
    return VerticeFinal;
}

// Métodos para establecer los Vértices
void Arista::setVerticeInicial(const Vertice& VerticeA) {
    VerticeInicial = VerticeA;
}

void Arista::setVerticeFinal(const Vertice& VerticeB) {
    VerticeFinal = VerticeB;
}

// Método para comparar si dos aristas son iguales
bool Arista::sonIguales(const Arista& otraArista) const {
    return (VerticeInicial.sonIguales(otraArista.getVerticeInicial()) && 
            VerticeFinal.sonIguales(otraArista.getVerticeFinal())) || 
           (VerticeInicial.sonIguales(otraArista.getVerticeFinal()) && 
            VerticeFinal.sonIguales(otraArista.getVerticeInicial()));
}
