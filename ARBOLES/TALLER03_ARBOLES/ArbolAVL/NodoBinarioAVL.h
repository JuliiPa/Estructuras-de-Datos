#ifndef NODOBINARIOAVL_H // Evita la inclusión múltiple de este archivo
#define NODOBINARIOAVL_H

// Definición de la clase NodoBinarioAVL, una plantilla para manejar cualquier tipo de dato T
template <class T>
class NodoBinarioAVL {
    public:
        T dato; // Dato almacenado en el nodo
        NodoBinarioAVL<T> *hijoIzq; // Puntero al hijo izquierdo
        NodoBinarioAVL<T> *hijoDer; // Puntero al hijo derecho

    public:
        // Constructor por defecto
        NodoBinarioAVL();

        // Destructor
        ~NodoBinarioAVL();

        // Métodos para obtener y establecer el dato del nodo
        T& getDato();
        void setDato(T& val);

        // Métodos para obtener y establecer los hijos del nodo
        NodoBinarioAVL<T>* getHijoIzq();
        NodoBinarioAVL<T>* getHijoDer();
        void setHijoIzq(NodoBinarioAVL<T>* izq);
        void setHijoDer(NodoBinarioAVL<T>* der);
};

// Incluye la implementación de los métodos en el archivo .hxx (definición de plantillas)
#include "NodoBinarioAVL.hxx"

#endif
