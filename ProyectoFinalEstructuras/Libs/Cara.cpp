#include "Cara.h"

// Constructor
Cara::Cara() {
}

// Método para añadir una arista
void Cara::anadirArista(Arista& arista) {
    aristas.push_back(arista);
}

// Método para obtener las aristas
const std::list<Arista>& Cara::getAristas() const{
    return aristas;
}
