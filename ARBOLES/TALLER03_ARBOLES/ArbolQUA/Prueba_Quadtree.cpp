#include "Quadtree.h"

int main(){
    Quadtree mapa(Coordenada(0, 0), Coordenada(8, 8));

    Nodo a(Coordenada(1, 1), 1);
    Nodo b(Coordenada(2, 5), 2);
    Nodo c(Coordenada(7, 6), 3);

    mapa.insertar(&a);
    mapa.insertar(&b);
    mapa.insertar(&c);

    cout << "Nodo a: " << mapa.buscar(Coordenada(1, 1))->dato << "\n";
    cout << "Nodo b: " << mapa.buscar(Coordenada(2, 5))->dato << "\n";
    cout << "Nodo c: " << mapa.buscar(Coordenada(7, 6))->dato << "\n";

    cout << "Nodo no existente: " << mapa.buscar(Coordenada(5, 5)) << "\n";

    mapa.buscar(Coordenada(1,1))->dato = 5;
    cout << "Nodo a despues de modificacion: " << mapa.buscar(Coordenada(1, 1))->dato << "\n";

    return 0;
}