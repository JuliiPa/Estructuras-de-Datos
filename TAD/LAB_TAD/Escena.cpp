#include "Escena.h"
#include <algorithm>  // Para utilizar std::sort

// Constructor de la clase Escena, inicializa los límites de la escena
Escena::Escena(Punto limites_min, Punto limites_max)
    : limites_min(limites_min), limites_max(limites_max) {}

// Método para agregar un objeto 3D a la lista de objetos en la escena
void Escena::agregarObjeto(const Objeto3D& objeto) {
    objetos.push_back(objeto);   // Añade el objeto al final del vector de objetos
}

// Método para ordenar los objetos de la escena según su distancia en el eje z (profundidad)
void Escena::ordenarPorDistancia() {
    std::sort(objetos.begin(), objetos.end(), [](const Objeto3D& obj1, const Objeto3D& obj2) {
        return obj1.centroide.z < obj2.centroide.z;  // Ordena de más lejos a más cerca
        }); //Es similar a ordenamiento burbuja
}
