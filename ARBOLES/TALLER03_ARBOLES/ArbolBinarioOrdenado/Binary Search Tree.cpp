/**************************************
* Archivo: Binary Search Tree.cpp
* Autor: Nicolas Algarra Polanco
* Descripcion: Se encontrara la clase BST, la cual sera un arbol binario
* de busqueda y tendra las siguientes operaciones:
* - BTS(numero), constructor que asigna un valor a la raiz dado por parametro
* - busquedaInOrder(), imprime todos los elementos del arbol usando la busqueda InOrder
* - busquedaPostOrder(), imprime todos los elementos del arbol usando la busqueda PostOrder
* - busquedaPreOrder(), imprime todos los elementos del arbol usando la busqueda PreOrder
* - buscarNumero(numero), busca en el arbol si el numero dado por parametro esta en el arbol
* - agregarNumero(numero), agrega al arbol un nuevo nodo con el numero dado por parametro
* - eliminarNumero(numero), elimina del arbol el nodo con el numero dado por parametro
**************************************/
#include "Binary Search Tree.h"

// Contructor que pide un numero para la raiz del arbol
BST::BST(int numero){
    raiz = new nodo(numero);
}

// funcion auxiliar que imprime todos los datos dado un nodo raiz por parametro en InOrder
void BST::busquedaInOrder(nodo *nodo){
    if(nodo != nullptr){
        busquedaInOrder(nodo->nodoIzquierda);
        cout << " " << nodo->dato;
        busquedaInOrder(nodo->nodoDerecha);
    }
}
// funcion auxiliar que imprime todos los datos dado un nodo raiz por parametro en PostOrder
void BST::busquedaPostOrder(nodo *nodo){
    if(nodo != nullptr){
        busquedaPostOrder(nodo->nodoIzquierda);
        busquedaPostOrder(nodo->nodoDerecha);
        cout << " " << nodo->dato;
    }
}
// funcion auxiliar que imprime todos los datos dado un nodo raiz por parametro en PreOrder
void BST::busquedaPreOrder(nodo *nodo){
    if(nodo != nullptr){
        cout << " " << nodo->dato;
        busquedaPreOrder(nodo->nodoIzquierda);
        busquedaPreOrder(nodo->nodoDerecha);
    }
}

// funcion que imprime todos los datos del arbol InOrder
void BST::busquedaInOrder(){
    busquedaInOrder(raiz);
    cout << endl;
}
// funcion que imprime todos los datos del arbol InOrder
void BST::busquedaPostOrder(){
    busquedaPostOrder(raiz);
    cout << endl;
}
// funcion que imprime todos los datos del arbol InOrder
void BST::busquedaPreOrder(){
    busquedaPreOrder(raiz);
    cout << endl;
}

// funcion auxiliar que retorna si el arbol de un nodo raiz contiene a un numero dado por parametro
bool BST::buscarNumero(int numero, nodo* nodo){
    
    // En caso de que el nodo tenga al numero se retorna verdadero
    if(nodo->dato == numero){
        return true;
    } 

    // En caso de que el nodo sea mayor al numero, se buscara el numero en el nodo izquierdo
    // Si no existe un nodo izquierdo significa que el numero no esta en el arbol
    if(nodo->dato>numero){
        if(nodo->nodoIzquierda == nullptr){
            return false;
        }
        return buscarNumero(numero, nodo->nodoIzquierda);
    }

    // En caso de que el nodo sea menor al numero, se buscara el numero en el nodo derecho
    // Si no existe un nodo derecho significa que el numero no esta en el arbol
    if(nodo->nodoDerecha == nullptr){
        return false;
    }
    return buscarNumero(numero, nodo->nodoDerecha);
}
// funcion auxiliar que agrega un nodo nuevo al arbol de un nodo raiz
void BST::agregarNodo(nodo *nodoNuevo, nodo* nodoActual){
    // En caso de existir un nodo con el mismo dato se manda un error
    if(nodoActual->dato == nodoNuevo->dato){
        throw ("Nodo con el numero dado ya existe");
    } 

    // Si el dato del nodo actual (el nodo que se esta analizando) es mayor al del nuevo nodo.
    // se verifica si el nodo actual tiene un nodo a la izquierda, si no lo tiene se agrega el
    // nuevo nodo a este. Si no, se va a ese nodo para intentar agregar el nodo a 
    // alguno de sus hijos
    if(nodoActual->dato > nodoNuevo->dato){
        if(nodoActual->nodoIzquierda == nullptr){
            nodoActual->nodoIzquierda = nodoNuevo;
            return;
        }
        agregarNodo(nodoNuevo, nodoActual->nodoIzquierda);
        return;
    }

    // Si el dato del nodo actual (el nodo que se esta analizando) es menor al del nuevo nodo.
    // se verifica si el nodo actual tiene un nodo a la derecha, si no lo tiene se agrega el
    // nuevo nodo a este. Si no, se va a ese nodo para intentar agregar el nodo a 
    // alguno de sus hijos
    if(nodoActual->nodoDerecha == nullptr){
        nodoActual->nodoDerecha = nodoNuevo;
        return;
    }
    agregarNodo(nodoNuevo, nodoActual->nodoDerecha);
    return;
}
// funcion auxiliar que elimina el nodo que contiene un numero del arbol de un nodo raiz
bool BST::eliminarNumero(int numero, nodo* nodo){
    // En caso del nodo ser el que contiene el numero, 
    // se le retorna al nodo padre que su hijo debe ser eliminado
    if(nodo->dato == numero){
        return true;
    } 

    // En caso de que el nodo sea mayor al numero, se verifica si tiene nodo izquierdo
    // si no, se genera un error de que no existe el numero, pero si sí tiene,
    // se verificara a ese nodo y se esperara su respuesta, en caso de ser verdadera,
    // significa que ese nodo hijo tiene que ser eliminado, por lo cual deja de apuntar a el
    // y retorna false para hacerle saber a su padre que el no es el nodo a eliminar
    if(nodo->dato>numero){
        if(nodo->nodoIzquierda == nullptr){
            throw ("El numero no existe dentro del arbol");
        }
        if(eliminarNumero(numero, nodo->nodoIzquierda)){
            nodo->nodoIzquierda = nullptr;
            return false;
        }
    }

    // En caso de que el nodo sea menor al numero, se verifica si tiene nodo derecho
    // si no, se genera un error de que no existe el numero, pero si sí tiene,
    // se verificara a ese nodo y se esperara su respuesta, en caso de ser verdadera,
    // significa que ese nodo hijo tiene que ser eliminado, por lo cual deja de apuntar a el
    // y retorna false para hacerle saber a su padre que el no es el nodo a eliminar
    if (nodo->dato<numero)
    {
        if(nodo->nodoDerecha == nullptr){
            throw ("El numero no existe dentro del arbol");
        }
        if(eliminarNumero(numero, nodo->nodoDerecha)){
            nodo->nodoDerecha = nullptr;
            return false;
        }
    }
    return false;
}

// funcion que busca en el arbol si este tiene un numero dado por parametro
bool BST::buscarNumero(int numero){
    if(raiz == nullptr){
        return false;
    }
    return buscarNumero(numero,raiz);
}
// funcion que agrega un nuevo numero al arbol dado por parametro
void BST::agregarNumero(int numero){
    nodo* nuevoNodo = new nodo(numero);

    if (raiz == nullptr) {
        raiz = nuevoNodo;
    } else {
        agregarNodo(nuevoNodo, raiz);
    }
}
// funcion que elimina del arbol un numero dado por parametro
void BST::eliminarNumero(int numero){
    if(eliminarNumero(numero,raiz)){
        raiz = nullptr;
    }
}