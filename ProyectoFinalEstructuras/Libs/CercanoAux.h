#ifndef CERCANOAUX_H
#define CERCANOAUX_H
#include "Vertice.h"
#include <string>

class CercanoAux {
private:
    Vertice* vertice;
    double distancia;
    int indice;
    std::string objeto;

public:
    // Constructor
    CercanoAux(Vertice& Nuevovertice,double Nuevadistancia,int Nuevoindice,std::string nuevoObjeto);

    int getX() const;
    int getY() const;
    int getZ() const;
    std::string getObjeto() const;
    double getDistancia()const;
    int getIndice()const;
    Vertice* getVertice()const;
};

#endif