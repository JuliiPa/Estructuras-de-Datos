#ifndef CARA_H
#define CARA_H

#include <list>
#include "Arista.h" // Asegúrate de que la definición de Arista esté en este archivo

class Cara {
private:
    std::list<Arista> aristas; // Lista de aristas

public:
    // Constructor
    Cara();

    // Método para añadir una arista
    void anadirArista(Arista& arista);

    // Método para obtener las aristas (opcional)
    const std::list<Arista>& getAristas() const;
};

#endif
