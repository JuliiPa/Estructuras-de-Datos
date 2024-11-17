#include "Vertice.h"
#include <cmath>

// Constructor
Vertice::Vertice(float x, float y, float z,int nuevoIndice)
{
    coord[0] = x;
    coord[1] = y;
    coord[2] = z;
    indice=nuevoIndice;
}

// Métodos para obtener las coordenadas
float Vertice::getX() const
{
    return coord[0];
}

float Vertice::getY() const
{
    return coord[1];
}

float Vertice::getZ() const
{
    return coord[2];
}
int Vertice::getIndice() const
{
    return indice;
}

// Métodos para establecer las coordenadas
void Vertice::setX(float x)
{
    coord[0] = x;
}

void Vertice::setY(float y)
{
    coord[1] = y;
}

void Vertice::setZ(float z)
{
    coord[2] = z;
}

bool Vertice::sonIguales(const Vertice &otro) const
{
    if (coord[0] == otro.getX() && coord[1] == otro.getY() && coord[2] == otro.getZ())
    {
        return true;
    }
    return false;
}
double Vertice::DistanciaEuclidiana(float x, float y, float z) const
{
    return sqrt(pow(x - coord[0], 2) + pow(y - coord[1], 2) + pow(z - coord[2], 2));
}
