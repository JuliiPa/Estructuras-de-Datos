#include "Coordenada.h"

//Constructor que asigna el x y y pasado por parametro con sus correspondientes pares
Coordenada::Coordenada(int _x, int _y)
{
    x = _x;
    y = _y;
}
// Constructor que asigna automaticamente la coodenada 0 0
Coordenada::Coordenada()
{
    x = 0;
    y = 0;
}