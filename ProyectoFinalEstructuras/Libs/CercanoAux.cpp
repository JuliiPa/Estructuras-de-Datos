#include "CercanoAux.h"

CercanoAux::CercanoAux(Vertice &Nuevovertice,double Nuevadistancia,int Nuevoindice,std::string nuevoObjeto)
{
    vertice=&Nuevovertice;
    distancia=Nuevadistancia;
    indice=Nuevoindice;
    objeto=nuevoObjeto;
}

int CercanoAux::getX() const
{
    return vertice->getX();
}
int CercanoAux::getY() const
{
    return vertice->getY();
}
int CercanoAux::getZ() const
{
    return vertice->getZ();
}
double CercanoAux::getDistancia() const
{
    return distancia;
}
int CercanoAux::getIndice() const
{
    return indice;
}
std::string CercanoAux::getObjeto() const
{
    return objeto;
}
 Vertice* CercanoAux::getVertice()const
{
    return vertice;
}