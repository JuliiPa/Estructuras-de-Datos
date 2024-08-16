#ifndef OBJETO3D_H
#define OBJETO3D_H

#include <vector>
#include "Punto.h"

//Definir un tipo de objeto, se limita con valores, en este caso completa, parcial y nula, se usa para pocos valores
//Enum + nombre de variable
enum IndicadorVisualizacion {
    COMPLETA,  // El objeto está completamente dentro de los límites
    PARCIAL,   // El objeto está parcialmente dentro de los límites
    NULA       // El objeto está completamente fuera de los límites
};

// Definición de la clase Objeto3D que representa un objeto tridimensional
class Objeto3D {
public:
    // Vector que almacena los puntos que componen el objeto 3D
    std::vector<Punto> puntos;

    // Punto que representa el centroide del objeto
    Punto centroide;

    // Indicador que muestra el estado de visualización del objeto
    IndicadorVisualizacion indicador_visualizacion;

    // Constructor de la clase Objeto3D, inicializa el indicador de visualización a NULA
    Objeto3D();

    // Método para calcular el centroide del objeto basado en sus puntos
    void calcularCentroide();

    // Método para actualizar el estado de visualización del objeto basándose en los límites de la escena
    void actualizarIndicadorVisualizacion(const Punto& limites_min, const Punto& limites_max);
};

#endif
