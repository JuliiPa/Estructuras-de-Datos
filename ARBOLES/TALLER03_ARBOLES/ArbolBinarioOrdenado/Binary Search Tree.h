#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo* nodoIzquierda;
    nodo* nodoDerecha;

    nodo(int valor) : dato(valor), nodoIzquierda(nullptr), nodoDerecha(nullptr) {} // constructor estructura
};

class BST{
    private:
        nodo *raiz;

        void busquedaInOrder(nodo *nodo);
        void busquedaPostOrder(nodo *nodo);
        void busquedaPreOrder(nodo *nodo);

        bool buscarNumero(int numero, nodo *nodo);
        void agregarNodo(nodo *nuevoNodo, nodo* nodoActual);
        bool eliminarNumero(int numero, nodo* nodo);
        
    public:
        BST(int numero);

        void busquedaInOrder();
        void busquedaPostOrder();
        void busquedaPreOrder();

        bool buscarNumero(int numero);
        void agregarNumero(int numero);
        void eliminarNumero(int numero);
};