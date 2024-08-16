#ifndef ESCENA_H
#define ESCENA_H

#include <vector>
#include "Objeto3D.h"

// Definición de la clase Escena
class Escena {
public:
    // Variables que definen los límites de la escena en las coordenadas x, y, z
    Punto limites_min;  // Límites mínimos de la escena (x_min, y_min, z_min)
    Punto limites_max;  // Límites máximos de la escena (x_max, y_max, z_max)

    // Vector que almacena los objetos 3D que pertenecen a la escena
    std::vector<Objeto3D> objetos;

    // Constructor de la clase Escena, que recibe los límites mínimo y máximo de la escena
    Escena(Punto limites_min, Punto limites_max);

    // Método para agregar un objeto 3D a la escena
    void agregarObjeto(const Objeto3D& objeto);

    // Método para ordenar los objetos de la escena según su distancia en el eje z
    void ordenarPorDistancia();
};

#endif
