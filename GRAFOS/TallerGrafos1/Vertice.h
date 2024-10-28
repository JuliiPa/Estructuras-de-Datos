/************************************
 Fecha: 16/10/2024
 Nombre:JULIANA PACHECO AMAYA
 Tema: Implementacion Basica de Grafos
 ************************************/
 
#ifndef VERTICE_H
#define VERTICE_H

template <typename T>
class Vertice {
public:
    T dato;
    int indice;

    Vertice(T dato, int indice);
};

#include "Vertice.hxx"
#endif // VERTICE_H