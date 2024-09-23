#ifndef NODOBINARIOAVL_HXX
#define NODOBINARIOAVL_HXX

#include "NodoBinarioAVL.h" // Incluye la definición de la clase NodoBinarioAVL

// Constructor por defecto: inicializa los hijos como nulos
template <class T>
NodoBinarioAVL<T>::NodoBinarioAVL() : hijoIzq(nullptr), hijoDer(nullptr) {}

// Destructor: libera recursos (aquí no se hace nada explícito)
template <class T>
NodoBinarioAVL<T>::~NodoBinarioAVL() {}

// Devuelve el dato almacenado en el nodo
template <class T>
T& NodoBinarioAVL<T>::getDato() {
    return dato;
}

// Establece el dato almacenado en el nodo
template <class T>
void NodoBinarioAVL<T>::setDato(T& val) {
    dato = val;
}

// Devuelve el puntero al hijo izquierdo del nodo
template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq() {
    return hijoIzq;
}

// Establece el puntero al hijo izquierdo del nodo
template <class T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL<T>* izq) {
    hijoIzq = izq;
}

// Devuelve el puntero al hijo derecho del nodo
template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer() {
    return hijoDer;
}

// Establece el puntero al hijo derecho del nodo
template <class T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL<T>* der) {
    hijoDer = der;
}

#endif
