#include <iostream>
#include "Escena.h"

using namespace std;

// Función principal del programa
int main() {
    // Definir límites de la escena en las coordenadas x, y, z
    // limites_min define el punto mínimo (-100, -100, -100)
    // limites_max define el punto máximo (100, 100, 100)
    Punto limites_min(-100, -100, -100);
    Punto limites_max(100, 100, 100);

    // Crear una escena con los límites definidos
    Escena escena(limites_min, limites_max);

    // Crear el primer objeto (objeto1)
    Objeto3D objeto1;

    // Añadir puntos al objeto1 con coordenadas y colores específicos
    objeto1.puntos.push_back(Punto(10, 10, 10, 255, 0, 0));  // Punto rojo en (10, 10, 10)
    objeto1.puntos.push_back(Punto(20, 20, 20, 0, 255, 0));  // Punto verde en (20, 20, 20)

    // Calcular el centroide del objeto1, que es el promedio de los puntos
    objeto1.calcularCentroide();

    // Actualizar el indicador de visualización de objeto1 basado en los límites de la escena
    objeto1.actualizarIndicadorVisualizacion(limites_min, limites_max);



    // Crear el segundo objeto (objeto2)
    Objeto3D objeto2;

    // Añadir puntos al objeto2 con coordenadas y colores específicos
    objeto2.puntos.push_back(Punto(-10, -10, -10, 0, 0, 255));  // Punto azul en (-10, -10, -10)
    objeto2.puntos.push_back(Punto(-20, -20, -20, 255, 255, 0)); // Punto amarillo en (-20, -20, -20)

    // Calcular el centroide del objeto2
    objeto2.calcularCentroide();

    // Actualizar el indicador de visualización de objeto2 basado en los límites de la escena
    objeto2.actualizarIndicadorVisualizacion(limites_min, limites_max);

    // Agregar ambos objetos a la escena
    escena.agregarObjeto(objeto1);
    escena.agregarObjeto(objeto2);

    // Ordenar los objetos en la escena según su distancia al observador (en el eje z)
    escena.ordenarPorDistancia();

    // Mostrar información de los objetos en la escena
    for (const auto& objeto : escena.objetos) {
        cout << "Centroide: (" << objeto.centroide.x << ", " << objeto.centroide.y << ", " << objeto.centroide.z << ")\n";
        // Dependiendo del valor del indicador_visualizacion, se muestra "Completa", "Parcial" o "Nula"
        cout << "Indicador de visualización: " << (objeto.indicador_visualizacion == COMPLETA ? "Completa" :
            objeto.indicador_visualizacion == PARCIAL ? "Parcial" : "Nula") << "\n";
    }

    // Ahora añadimos un tercer objeto que tenga visualización parcial
    Objeto3D objeto3;

    // Añadir puntos, uno dentro de los límites y otro fuera
    objeto3.puntos.push_back(Punto(50, 50, 50, 100, 100, 100));  // Punto gris en (50, 50, 50)
    objeto3.puntos.push_back(Punto(150, 150, 150, 200, 200, 200)); // Punto gris claro fuera de los límites

    // Calcular centroide y actualizar visualización
    objeto3.calcularCentroide();
    objeto3.actualizarIndicadorVisualizacion(limites_min, limites_max);
    escena.agregarObjeto(objeto3);


    // Añadimos un cuarto objeto que tenga visualización nula
    Objeto3D objeto4;

    // Añadir puntos todos fuera de los límites
    objeto4.puntos.push_back(Punto(200, 200, 200, 50, 50, 50));  // Punto gris oscuro fuera de los límites
    objeto4.puntos.push_back(Punto(250, 250, 250, 80, 80, 80));  // Otro punto gris fuera de los límites

    // Calcular centroide y actualizar visualización
    objeto4.calcularCentroide();
    objeto4.actualizarIndicadorVisualizacion(limites_min, limites_max);
    escena.agregarObjeto(objeto4);

    // Reordenar los objetos después de agregar los nuevos
    escena.ordenarPorDistancia();

    // Mostrar información actualizada de todos los objetos en la escena
    for (const auto& objeto : escena.objetos) {
        cout << "Centroide: (" << objeto.centroide.x << ", " << objeto.centroide.y << ", " << objeto.centroide.z << ")\n";
        cout << "Indicador de visualización: " << (objeto.indicador_visualizacion == COMPLETA ? "Completa" :
            objeto.indicador_visualizacion == PARCIAL ? "Parcial" : "Nula") << "\n";
    }

    return 0;
}
