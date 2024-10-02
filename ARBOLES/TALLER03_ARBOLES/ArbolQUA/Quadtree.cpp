/***********************
* Archivo: Quadtree.cpp
* Autor: Nicolas Algarra Polanco
*
* Descripción: Se encontrara las definiciones de las funciones de la clase Quadtree, 
* la cual sera un arbol quadtree y tendra las siguientes operaciones:
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
#include "Quadtree.h"

// Constructor predeterminado que no asigna un límite al cuadrante 
Quadtree::Quadtree()
{
    limiteNO = Coordenada(0, 0);
    limiteSE = Coordenada(0, 0);
    nodo = NULL;
    arbolNO = NULL;
    arbolNE = NULL;
    arbolSO = NULL;
    arbolSE = NULL;
}
// Constructor que asigna los límites del cuadrante en base a los datos dados por parámetro
Quadtree::Quadtree(Coordenada NO, Coordenada SE)
{
    nodo = NULL;
    arbolNE = NULL;
    arbolNO = NULL;
    arbolSE = NULL;
    arbolSO = NULL;
    limiteNO = NO;
    limiteSE = SE;
}
// inserta un nodo dado por parámetro en el árbol 
void Quadtree::insertar(Nodo* nodo)
{
    // Abortar si el apuntador no apunta a nada
    if (nodo == NULL)
        return;
 
    // Abortar si la posicion del nodo no esta en el cuadrante
    if (!contiene(nodo->pos))
        return;
 
    // En caso de no poder dividir mas los cuadrantes abortar y agregar nodo si posible
    if (abs(limiteNO.x - limiteSE.x) <= 1
        && abs(limiteNO.y - limiteSE.y) <= 1) {
        if (this->nodo == NULL)
            this->nodo = nodo;
        return;
    }
 
    if ((limiteNO.x + limiteSE.x) / 2 >= nodo->pos.x) {

        // insertar en el arbolNO
        if ((limiteNO.y + limiteSE.y) / 2 >= nodo->pos.y) {
            if (arbolNO == NULL) // Si el cuadrante NO no existe
                arbolNO = new Quadtree(
                    Coordenada(limiteNO.x, limiteNO.y),
                    Coordenada((limiteNO.x + limiteSE.x) / 2, (limiteNO.y + limiteSE.y) / 2)
                    );

            arbolNO->insertar(nodo);
        }
 
        // insertar en el arbolSO
        else {
            if (arbolSO == NULL) // Si el cuadrante SO no existe
                arbolSO = new Quadtree(
                    Coordenada(limiteNO.x, (limiteNO.y + limiteSE.y) / 2),
                    Coordenada((limiteNO.x + limiteSE.x) / 2, limiteSE.y)
                    );

            arbolSO->insertar(nodo);
        }
    }
    else {
        // insertar en el arbolNE 
        if ((limiteNO.y + limiteSE.y) / 2 >= nodo->pos.y) {
            if (arbolNE == NULL) // Si el cuadrante NE no existe
                arbolNE = new Quadtree(
                    Coordenada((limiteNO.x + limiteSE.x) / 2, limiteNO.y),
                    Coordenada(limiteSE.x, (limiteNO.y + limiteSE.y) / 2)
                    );

            arbolNE->insertar(nodo);
        }
 
        // insertar en el arbolSE 
        else {
            if (arbolSE == NULL) // Si el cuadrante SE no existe
                arbolSE = new Quadtree(
                    Coordenada((limiteNO.x + limiteSE.x) / 2, (limiteNO.y + limiteSE.y) / 2),
                    Coordenada(limiteSE.x, limiteSE.y)
                    );

            arbolSE->insertar(nodo);
        }
    }
}
 
// busca el nodo que esta está en la coordenada dada por parámetro
Nodo* Quadtree::buscar(Coordenada coordenada)
{
    // Abortar si el cuadrante no contiene la coordenada
    if (!contiene(coordenada))
        return NULL;
 
    // En caso de encontrar el nodo, retornarlo
    if (nodo != NULL)
        return nodo;
 
    if ((limiteNO.x + limiteSE.x) / 2 >= coordenada.x) {
        // Buscar en arbolNO
        if ((limiteNO.y + limiteSE.y) / 2 >= coordenada.y) {
            if (arbolNO == NULL)
                return NULL;
            return arbolNO->buscar(coordenada);
        }
 
        // Buscar en arbolSO
        else {
            if (arbolSO == NULL)
                return NULL;
            return arbolSO->buscar(coordenada);
        }
    }
    else {
        // Buscar en arbolNE
        if ((limiteNO.y + limiteSE.y) / 2 >= coordenada.y) {
            if (arbolNE == NULL)
                return NULL;
            return arbolNE->buscar(coordenada);
        }
 
        // Buscar en arbolSE
        else {
            if (arbolSE == NULL)
                return NULL;
            return arbolSE->buscar(coordenada);
        }
    }
};
 
// retorna si la coordenada se encuentra dentro de los límites del cuadrante
bool Quadtree::contiene(Coordenada coordenada)
{
    return (coordenada.x >= limiteNO.x && coordenada.x <= limiteSE.x
            && coordenada.y >= limiteNO.y && coordenada.y <= limiteSE.y);
}