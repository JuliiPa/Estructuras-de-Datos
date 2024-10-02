#include "ArbolBinario.h"
#include <iostream>

using namespace std;

int main(){
    ArbolBinario arbol(4);

    arbol.getRaiz()->nodoDerecha = new nodo(5);
    arbol.getRaiz()->nodoIzquierda = new nodo(6);
    arbol.getRaiz()->nodoDerecha->nodoIzquierda = new nodo(8);
    arbol.getRaiz()->nodoDerecha->nodoDerecha = new nodo(2);
    arbol.getRaiz()->nodoIzquierda->nodoDerecha = new nodo(3);

    cout << "InOrder\n";
    arbol.busquedaInOrder();
    cout << "PreOrder\n";
    arbol.busquedaPreOrder();
    cout << "PostOrder\n";
    arbol.busquedaPostOrder();

    arbol.getRaiz()->nodoDerecha->dato = 10;
    cout << "InOrder al modificar un nodo\n";
    arbol.busquedaInOrder();

    arbol.getRaiz()->nodoDerecha->nodoDerecha = nullptr;
    cout << "InOrder al eliminar un nodo\n";
    arbol.busquedaInOrder();
}