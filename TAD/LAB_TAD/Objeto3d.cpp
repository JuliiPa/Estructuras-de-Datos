#include "Objeto3D.h"
#include <numeric>  // Para operacion acumulativos

// Constructor de la clase Objeto3D, inicializa el indicador de visualización a NULA
Objeto3D::Objeto3D() : indicador_visualizacion(NULA) {}

// Método para calcular el centroide del objeto 3D
void Objeto3D::calcularCentroide() {
  // Si no hay puntos en el objeto, no se puede calcular el centroide, así que se retorna
    if (puntos.empty()) return;

    float sum_x = 0, sum_y = 0, sum_z = 0;

  // Variables para acumular las coordenadas x, y, z de todos los puntos
    for (const auto& punto : puntos) {
        sum_x += punto.x;
        sum_y += punto.y;
        sum_z += punto.z;
    }
    // Sumar las coordenadas de todos los puntos del objeto
    centroide.x = sum_x / puntos.size();
    centroide.y = sum_y / puntos.size();
    centroide.z = sum_z / puntos.size();
}

// Método para actualizar el indicador de visualización basado en los límites de la escena
void Objeto3D::actualizarIndicadorVisualizacion(const Punto& limites_min, const Punto& limites_max) {
    bool todosDentro = true; // Asume inicialmente que todos los puntos están dentro de los límites
    bool algunoDentro = false;  // Asume inicialmente que ningún punto está dentro de los límites

//Recorrer un vector
    for (const auto& punto : puntos) {
        // Comprobar si el punto está dentro de los límites proporcionados
        if (punto.x >= limites_min.x && punto.x <= limites_max.x &&
            punto.y >= limites_min.y && punto.y <= limites_max.y &&
            punto.z >= limites_min.z && punto.z <= limites_max.z) {
            algunoDentro = true; // Al menos un punto está dentro de los límites
        }
        else {
            todosDentro = false; // Al menos un punto está fuera de los límites
        }
    }

  // Actualizar el indicador de visualización según los resultados de la comprobación
    if (todosDentro) {
        indicador_visualizacion = COMPLETA;  // Todos los puntos están dentro
    }
    else if (algunoDentro) {
        indicador_visualizacion = PARCIAL;  // Algunos puntos están dentro, pero no todos
    }
    else {
        indicador_visualizacion = NULA;  // Ningún punto está dentro
    }
}
