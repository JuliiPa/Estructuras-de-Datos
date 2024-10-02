#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo* nodoIzquierda;
    nodo* nodoDerecha;

    nodo(int numero) : dato(numero), nodoIzquierda(nullptr), nodoDerecha(nullptr) {} //Constructor de nodo
};

class ArbolBinario{
    private:
    nodo* raiz;

    // funciones auxiliares para las diferentes visualizaciones del arbol
    void busquedaInOrder(nodo *nodo);
    void busquedaPostOrder(nodo *nodo);
    void busquedaPreOrder(nodo *nodo);

    public:
    ArbolBinario(int numero);

    void busquedaInOrder();
    void busquedaPostOrder();
    void busquedaPreOrder();

    nodo* getRaiz();
};