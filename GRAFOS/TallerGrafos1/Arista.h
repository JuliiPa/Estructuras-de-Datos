/************************************
 Fecha: 16/10/2024
 Nombre:JULIANA PACHECO AMAYA
 Tema: Implementacion Basica de Grafos
 ************************************/

#ifndef ARISTA_H
#define ARISTA_H

template <typename W>
class Arista {
public:
    W peso;
    
    Arista(W peso);
};

#include "Arista.hxx"
#endif // ARISTA_H