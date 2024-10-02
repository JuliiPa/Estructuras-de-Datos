/***********************
* Archivo: Quadtree.h
* Autor: Nicolas Algarra Polanco
*
* Descripción: Se encontrara la clase Quadtree, la cual sera un arbol quadtree
* y tendra las siguientes operaciones:
*
* - Quadtree(NO, SE), Constructor que asigna los límites del cuadrante en base a los datos dados por parámetro 
* - Quadtree(), Constructor predeterminado que no asigna un límite al cuadrante 
* - Insertar(nodo), inserta un nodo dado por parámetro en el árbol 
* - Buscar(coordenada), busca el nodo que esta está en la coordenada dada por parámetro 
* - Contiene(coordenada), retorna si la coordenada se encuentra dentro de los límites del cuadrante 
*
* Diccionario de palabras:
* Teniendo en cuenta que este codigo hace uso de abreviaciones, a continuación
* se encontrara el significado de cada una de ellas:
*
* - NO -> Noreste (Hace referencia al cuadrante o coordenada de arriba a la derecha)
* - NE -> Noroeste (Hace referencia al cuadrante o coordenada de arriba a la izquierda)
* - SO -> Suroeste (Hace referencia al cuadrante o coordenada de abajo a la derecha)
* - SE -> Sureste (Hace referencia al cuadrante o coordenada de abajo a la izquierda)
*
************************/

#include <cmath>
#include <iostream>
#include "Coordenada.h"

using namespace std;

// Estructura para cada uno de los nodos
struct Nodo {
    Coordenada pos;
    int dato;
    Nodo(Coordenada _pos, int _dato): pos(_pos), dato(_dato) {} // Constructor especifico
    Nodo(): dato(0) {} // Constructor predeterminado
};

// Clase principal de quadtree
class Quadtree {
    private:
    //Coordenadas que muestran el limite del Quadtree
    Coordenada limiteNO;
    Coordenada limiteSE;
 
    //La direccion del nodo que contiene el Quadtree
    Nodo* nodo;
 
    // Hijos del Quadtree
    Quadtree* arbolNO;
    Quadtree* arbolNE;
    Quadtree* arbolSO;
    Quadtree* arbolSE;
 
    public:
    // Constructores
    Quadtree();
    Quadtree(Coordenada NO, Coordenada SE);

    // Operaciones
    void insertar(Nodo* nodo);
    Nodo* buscar(Coordenada coordenada);
    bool contiene(Coordenada coordenada);
};