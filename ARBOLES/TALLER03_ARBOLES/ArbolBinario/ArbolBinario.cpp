/**************************************
* Archivo: ArbolBinario.cpp
* Autor: Nicolas Algarra Polanco
* Descripcion: Se encontrara la clase ArbolBinario, la cual sera un arbol binario
* y tendra las siguientes operaciones:
* - ArbolBinario(numero), constructor que asigna un valor a la raíz dado por parámetro 
* - busquedaInOrder(), imprime todos los elementos del árbol usando la búsqueda InOrder 
* - busquedaPostOrder(), imprime todos los elementos del árbol usando la búsqueda PostOrder 
* - getRaiz(), devuelve la dirección de memoria de la raíz 
* - busquedaPreOrder(), imprime todos los elementos del árbol usando la búsqueda PreOrder 
**************************************/
#include "ArbolBinario.h"

// Contructor que pide un numero para la raiz del arbol
ArbolBinario::ArbolBinario(int numero){
    raiz = new nodo(numero);
}

// funcion auxiliar que imprime todos los datos dado un nodo raiz por parametro en InOrder
void ArbolBinario::busquedaInOrder(nodo *nodo){
    if(nodo != nullptr){
        busquedaInOrder(nodo->nodoIzquierda);
        cout << " " << nodo->dato;
        busquedaInOrder(nodo->nodoDerecha);
    }
}
// funcion auxiliar que imprime todos los datos dado un nodo raiz por parametro en PostOrder
void ArbolBinario::busquedaPostOrder(nodo *nodo){
    if(nodo != nullptr){
        busquedaPostOrder(nodo->nodoIzquierda);
        busquedaPostOrder(nodo->nodoDerecha);
        cout << " " << nodo->dato;
    }
}
// funcion auxiliar que imprime todos los datos dado un nodo raiz por parametro en PreOrder
void ArbolBinario::busquedaPreOrder(nodo *nodo){
    if(nodo != nullptr){
        cout << " " << nodo->dato;
        busquedaPreOrder(nodo->nodoIzquierda);
        busquedaPreOrder(nodo->nodoDerecha);
    }
}

// funcion que imprime todos los datos del arbol InOrder
void ArbolBinario::busquedaInOrder(){
    busquedaInOrder(raiz);
    cout << endl;
}
// funcion que imprime todos los datos del arbol InOrder
void ArbolBinario::busquedaPostOrder(){
    busquedaPostOrder(raiz);
    cout << endl;
}
// funcion que imprime todos los datos del arbol InOrder
void ArbolBinario::busquedaPreOrder(){
    busquedaPreOrder(raiz);
    cout << endl;
}
// funcion que retorna la direccion en memoria del nodo raiz
nodo* ArbolBinario::getRaiz(){
    return raiz;
}