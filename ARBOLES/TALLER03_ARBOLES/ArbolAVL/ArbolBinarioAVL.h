#ifndef ARBOLBINARIOAVL_H // Evita la inclusión múltiple de este archivo
#define ARBOLBINARIOAVL_H

#include "NodoBinarioAVL.h" // Incluye la definición de la clase NodoBinarioAVL

// Definición de la clase ArbolBinarioAVL, que es una plantilla para manejar cualquier tipo de dato T
template <class T>
class ArbolBinarioAVL {
    protected:
        NodoBinarioAVL<T> *raiz; // Puntero a la raíz del árbol

    public:
        // Constructor por defecto
        ArbolBinarioAVL();

        // Destructor
        ~ArbolBinarioAVL();

        // Métodos de acceso y modificación de la raíz
        void setRaiz(NodoBinarioAVL<T>* raiz);
        NodoBinarioAVL<T>* getRaiz();

        // Métodos para verificar si el árbol está vacío
        bool esVacio();

        // Método para obtener el dato en la raíz del árbol
        T& datoRaiz();

        // Métodos para calcular la altura y el tamaño del árbol
        int altura(NodoBinarioAVL<T> *inicio);
        int tamano(NodoBinarioAVL<T> *inicio);

        // Métodos para realizar rotaciones necesarias en un árbol AVL
        NodoBinarioAVL<T>* giroDerecha(NodoBinarioAVL<T>*& inicio);
        NodoBinarioAVL<T>* giroIzquierda(NodoBinarioAVL<T>*& inicio);
        NodoBinarioAVL<T>* giroIzquierdaDerecha(NodoBinarioAVL<T>* &padre);
        NodoBinarioAVL<T>* giroDerechaIzquierda(NodoBinarioAVL<T>* &padre);

        // Métodos para insertar, eliminar y buscar valores en el árbol
        bool insertar(T& val);
        bool eliminar(T& val);
        bool buscar(T& val);

        // Métodos para recorrer el árbol en diferentes órdenes
        void preOrden(NodoBinarioAVL<T> *inicio);
        void inOrden(NodoBinarioAVL<T> *inicio);
        void posOrden(NodoBinarioAVL<T> *inicio);
        void nivelOrden(NodoBinarioAVL<T> *inicio);
};

// Incluye la implementación de los métodos en el archivo .hxx (definición de plantillas)
#include "ArbolBinarioAVL.hxx"

#endif
