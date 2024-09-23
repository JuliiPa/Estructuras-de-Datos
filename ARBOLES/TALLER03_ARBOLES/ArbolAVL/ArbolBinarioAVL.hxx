#include "ArbolBinarioAVL.h" // Incluye la definición de la clase ArbolBinarioAVL
#include <queue> // Incluye la biblioteca para manejar colas (útil para el recorrido por niveles)

using namespace std; // Usa el espacio de nombres estándar para simplificar el código

// Constructor por defecto: inicializa la raíz como NULL
template <class T>
ArbolBinarioAVL<T>::ArbolBinarioAVL(){
    this->raiz = NULL;
}

// Destructor: en este caso no se hace nada explícito
template <class T>
ArbolBinarioAVL<T>::~ArbolBinarioAVL(){
}

// Establece la raíz del árbol
template <class T>
void ArbolBinarioAVL<T>::setRaiz(NodoBinarioAVL<T>* raiz){
    this->raiz = raiz;
    return;
}

// Obtiene la raíz del árbol
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::getRaiz(){
    return this->raiz;
}

// Verifica si el árbol está vacío (si la raíz es NULL)
template <class T>
bool ArbolBinarioAVL<T>::esVacio(){
    if (this->raiz == NULL) {
        return true; // Devuelve true si el árbol está vacío
    }
    return false; // Devuelve false si el árbol no está vacío
}

// Devuelve el dato almacenado en la raíz del árbol
template <class T>
T& ArbolBinarioAVL<T>::datoRaiz(){
    return (this->raiz)->getDato();
}

// Calcula la altura del árbol a partir de un nodo dado
template <class T>
int ArbolBinarioAVL<T>::altura(NodoBinarioAVL<T> *inicio){
    int alturaIzq = 0; // Inicializa la altura del subárbol izquierdo
    int alturaDer = 0; // Inicializa la altura del subárbol derecho
    if (inicio == NULL) {
        return -1; // Altura de un nodo nulo es -1
    }
    if (inicio->getHijoIzq() == NULL && inicio->getHijoDer() == NULL) {
        return 0; // Si el nodo no tiene hijos, la altura es 0
    }
    if (inicio->getHijoIzq() != NULL) {
        alturaIzq += altura(inicio->getHijoIzq()) + 1; // Calcula la altura del subárbol izquierdo
    }
    if (inicio->getHijoDer() != NULL) {
        alturaDer += altura(inicio->getHijoDer()) + 1; // Calcula la altura del subárbol derecho
    }
    if (alturaIzq > alturaDer) {
        return (alturaIzq); // Devuelve la mayor altura entre ambos subárboles
    } else {
        return (alturaDer);
    }
}

// Calcula el número total de nodos en el árbol a partir de un nodo dado
template <class T>
int ArbolBinarioAVL<T>::tamano(NodoBinarioAVL<T> *inicio){
    int nodosIzq = 0; // Número de nodos en el subárbol izquierdo
    int nodosDer = 0; // Número de nodos en el subárbol derecho
    if (inicio == NULL) {
        return 0; // Tamaño de un nodo nulo es 0
    }
    if (inicio->getHijoIzq() == NULL && inicio->getHijoDer() == NULL) {
        return 1; // Si no tiene hijos, es una hoja y cuenta como 1
    }
    if (inicio->getHijoIzq() != NULL) {
        nodosIzq += tamano(inicio->getHijoIzq()); // Calcula el tamaño del subárbol izquierdo
    }
    if (inicio->getHijoDer() != NULL) {
        nodosDer += tamano(inicio->getHijoDer()); // Calcula el tamaño del subárbol derecho
    }
    return nodosIzq + nodosDer + 1; // Devuelve la suma de nodos de ambos subárboles más la raíz
}

// Realiza una rotación simple a la derecha para balancear el árbol
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerecha(NodoBinarioAVL<T>* &padre){
    NodoBinarioAVL<T> *n_padre = padre->getHijoIzq(); // El nuevo padre será el hijo izquierdo del actual
    padre->setHijoIzq(n_padre->getHijoDer()); // El hijo izquierdo del padre original se convierte en el hijo derecho del nuevo padre
    n_padre->setHijoDer(padre); // El nuevo padre toma el lugar del padre original
    return n_padre; // Devuelve el nuevo padre
}

// Realiza una rotación simple a la izquierda para balancear el árbol
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierda(NodoBinarioAVL<T>* &padre){
    NodoBinarioAVL<T> *n_padre = padre->getHijoDer(); // El nuevo padre será el hijo derecho del actual
    padre->setHijoDer(n_padre->getHijoIzq()); // El hijo derecho del padre original se convierte en el hijo izquierdo del nuevo padre
    n_padre->setHijoIzq(padre); // El nuevo padre toma el lugar del padre original
    return n_padre; // Devuelve el nuevo padre
}

// Realiza una rotación doble izquierda-derecha para balancear el árbol
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierdaDerecha(NodoBinarioAVL<T>* &padre){
    NodoBinarioAVL<T> **primGiro = &(padre->hijoIzq); // Primero realiza una rotación simple a la izquierda en el hijo izquierdo
    padre->setHijoIzq(giroIzquierda(*primGiro));
    return giroDerecha(padre); // Luego realiza una rotación simple a la derecha en el padre
}

// Realiza una rotación doble derecha-izquierda para balancear el árbol
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerechaIzquierda(NodoBinarioAVL<T>* &padre){
    NodoBinarioAVL<T> **primGiro = &(padre->hijoDer); // Primero realiza una rotación simple a la derecha en el hijo derecho
    padre->setHijoDer(giroDerecha(*primGiro));
    return giroIzquierda(padre); // Luego realiza una rotación simple a la izquierda en el padre
}

// Inserta un valor en el árbol, manteniendo las propiedades del AVL
template <class T>
bool ArbolBinarioAVL<T>::insertar(T& val){
    NodoBinarioAVL<T> *nodoActual = this->raiz; // Empieza desde la raíz del árbol
    NodoBinarioAVL<T> *nNodo = new NodoBinarioAVL<T>(); // Crea un nuevo nodo para el valor
    bool nodoInsertado, valorTomado = false; // Flags para controlar el estado de inserción

    // Busca la posición adecuada para el nuevo valor
    while (!valorTomado) {
        if (nodoActual == NULL) { // Si el árbol está vacío
            nNodo->setDato(val); // Establece el valor en el nuevo nodo
            this->raiz = nNodo; // El nuevo nodo se convierte en la raíz
            nodoInsertado = true; // Indica que el nodo ha sido insertado
            valorTomado = true; // Sale del bucle
            break;
        }
        else if (val == nodoActual->getDato()) { // Si el valor ya existe en el árbol
            nodoInsertado = false; // No se puede insertar un valor duplicado
            valorTomado = true; // Sale del bucle
            break;
        }
        else if (val > nodoActual->getDato() && nodoActual->getHijoDer() == NULL) { // Si el valor es mayor y el hijo derecho es nulo
            nNodo->setDato(val); // Establece el valor en el nuevo nodo
            nodoActual->setHijoDer(nNodo); // Lo coloca como hijo derecho
            nodoInsertado = true; // Indica que el nodo ha sido insertado
            valorTomado = true; // Sale del bucle
            break;
        }
        else if (val < nodoActual->getDato() && nodoActual->getHijoIzq() == NULL) { // Si el valor es menor y el hijo izquierdo es nulo
            nNodo->setDato(val); // Establece el valor en el nuevo nodo
            nodoActual->setHijoIzq(nNodo); // Lo coloca como hijo izquierdo
            nodoInsertado = true; // Indica que el nodo ha sido insertado
            valorTomado = true; // Sale del bucle
            break;
        }

        // Actualiza el nodo actual dependiendo de si el valor es mayor o menor
        if (val > nodoActual->getDato()) {
            nodoActual = nodoActual->getHijoDer(); // Se mueve al hijo derecho
        } else {
            nodoActual = nodoActual->getHijoIzq(); // Se mueve al hijo izquierdo
        }
    }

    // Si el nodo fue insertado, es necesario balancear el árbol
    if (nodoInsertado) {
        NodoBinarioAVL<T> **nBalanceo = &(this->raiz); // Comienza desde la raíz
        while ((*nBalanceo) != NULL) {
            // Realiza la rotación correspondiente según el balance del nodo
            if (altura((*nBalanceo)->getHijoIzq()) - altura((*nBalanceo)->getHijoDer()) > 1 &&
                altura(((*nBalanceo)->getHijoIzq())->getHijoIzq()) > altura(((*nBalanceo)->getHijoIzq())->getHijoDer())) {
                *nBalanceo = giroDerecha(*nBalanceo);
            } else if (altura((*nBalanceo)->getHijoIzq()) - altura((*nBalanceo)->getHijoDer()) > 1 &&
                       altura(((*nBalanceo)->getHijoIzq())->getHijoIzq()) < altura(((*nBalanceo)->getHijoIzq())->getHijoDer())) {
                *nBalanceo = giroIzquierdaDerecha(*nBalanceo);
            } else if (altura((*nBalanceo)->getHijoDer()) - altura((*nBalanceo)->getHijoIzq()) > 1 &&
                       altura(((*nBalanceo)->getHijoDer())->getHijoDer()) > altura(((*nBalanceo)->getHijoDer())->getHijoIzq())) {
                *nBalanceo = giroIzquierda(*nBalanceo);
            } else if (altura((*nBalanceo)->getHijoDer()) - altura((*nBalanceo)->getHijoIzq()) > 1 &&
                       altura(((*nBalanceo)->getHijoDer())->getHijoDer()) < altura(((*nBalanceo)->getHijoDer())->getHijoIzq())) {
                *nBalanceo = giroDerechaIzquierda(*nBalanceo);
            }

            // Continua balanceando según la posición del valor insertado
            if ((*nBalanceo)->getDato() < val) {
                nBalanceo = &((*nBalanceo)->hijoDer);
            } else {
                nBalanceo = &((*nBalanceo)->hijoIzq);
            }
        }
    }
    return nodoInsertado; // Devuelve si el nodo fue insertado correctamente
}

// Elimina un valor del árbol manteniendo las propiedades del AVL
template <class T>
bool ArbolBinarioAVL<T>::eliminar(T& val){
    NodoBinarioAVL<T> *buscaNodo = this->raiz; // Empieza desde la raíz
    if (this->raiz == NULL) {
        return false; // Si la raíz es nula, no hay nada que eliminar
    } else {
        while (buscaNodo->getHijoDer() != NULL || buscaNodo->getHijoIzq() != NULL || buscaNodo->getDato() == val) {
            if (buscaNodo->getDato() == val) { // Si encuentra el nodo con el valor a eliminar
                // Caso 1: Nodo hoja
                if (buscaNodo->getHijoDer() == NULL && buscaNodo->getHijoIzq() == NULL) {
                    NodoBinarioAVL<T> *buscaNodo3 = this->raiz;
                    if (this->raiz == buscaNodo) {
                        this->raiz = NULL; // Si es la raíz, se elimina
                    } else {
                        // Encuentra el nodo padre y elimina la referencia al nodo actual
                        while (buscaNodo3->getHijoIzq() != NULL || buscaNodo3->getHijoDer() != NULL) {
                            if (buscaNodo3->getHijoIzq() != NULL) {
                                if ((buscaNodo3->getHijoIzq())->getDato() == buscaNodo->getDato()) {
                                    buscaNodo3->setHijoIzq(NULL);
                                    break;
                                }
                            }
                            if (buscaNodo3->getHijoDer() != NULL) {
                                if ((buscaNodo3->getHijoDer())->getDato() == buscaNodo->getDato()) {
                                    buscaNodo3->setHijoDer(NULL);
                                    break;
                                }
                            }
                            if (buscaNodo->getDato() > buscaNodo3->getDato()) {
                                buscaNodo3 = buscaNodo3->getHijoDer();
                            } else {
                                buscaNodo3 = buscaNodo3->getHijoIzq();
                            }
                        }
                    }
                    delete(buscaNodo); // Elimina el nodo
                }
                // Caso 2: Nodo con un hijo izquierdo
                else if (buscaNodo->getHijoDer() == NULL) {
                    *(buscaNodo) = *(buscaNodo->getHijoIzq()); // Reemplaza el nodo con su hijo izquierdo
                }
                // Caso 3: Nodo con un hijo derecho
                else if (buscaNodo->getHijoIzq() == NULL) {
                    *(buscaNodo) = *(buscaNodo->getHijoDer()); // Reemplaza el nodo con su hijo derecho
                }
                // Caso 4: Nodo con dos hijos
                else {
                    NodoBinarioAVL<T> *buscaNodo2 = buscaNodo->getHijoIzq();
                    while (buscaNodo2->getHijoDer() != NULL) {
                        buscaNodo2 = buscaNodo2->getHijoDer(); // Encuentra el mayor de los menores
                    }
                    buscaNodo->setDato(buscaNodo2->getDato()); // Reemplaza el valor del nodo a eliminar
                    if (buscaNodo2->getHijoIzq() == NULL) {
                        if ((buscaNodo->getHijoIzq())->getHijoDer() != NULL) {
                            NodoBinarioAVL<T> *buscaNodo3 = buscaNodo->getHijoIzq();
                            while ((buscaNodo3->getHijoDer())->getDato() != buscaNodo2->getDato()) {
                                buscaNodo3 = buscaNodo3->getHijoDer();
                            }
                            buscaNodo3->setHijoDer(NULL);
                        } else {
                            buscaNodo->setHijoIzq(NULL);
                        }
                        delete(buscaNodo2); // Elimina el nodo
                    } else {
                        *(buscaNodo2) = *(buscaNodo2->getHijoIzq());
                    }
                }

                // Balancea el árbol después de la eliminación
                NodoBinarioAVL<T> **nBalanceo = &(this->raiz);
                while ((*nBalanceo) != NULL) {
                    if (altura((*nBalanceo)->getHijoIzq()) - altura((*nBalanceo)->getHijoDer()) > 1 &&
                        altura(((*nBalanceo)->getHijoIzq())->getHijoIzq()) > altura(((*nBalanceo)->getHijoIzq())->getHijoDer())) {
                        *nBalanceo = giroDerecha(*nBalanceo);
                    } else if (altura((*nBalanceo)->getHijoIzq()) - altura((*nBalanceo)->getHijoDer()) > 1 &&
                               altura(((*nBalanceo)->getHijoIzq())->getHijoIzq()) < altura(((*nBalanceo)->getHijoIzq())->getHijoDer())) {
                        *nBalanceo = giroIzquierdaDerecha(*nBalanceo);
                    } else if (altura((*nBalanceo)->getHijoDer()) - altura((*nBalanceo)->getHijoIzq()) > 1 &&
                               altura(((*nBalanceo)->getHijoDer())->getHijoDer()) > altura(((*nBalanceo)->getHijoDer())->getHijoIzq())) {
                        *nBalanceo = giroIzquierda(*nBalanceo);
                    } else if (altura((*nBalanceo)->getHijoDer()) - altura((*nBalanceo)->getHijoIzq()) > 1 &&
                               altura(((*nBalanceo)->getHijoDer())->getHijoDer()) < altura(((*nBalanceo)->getHijoDer())->getHijoIzq())) {
                        *nBalanceo = giroDerechaIzquierda(*nBalanceo);
                    }

                    if ((*nBalanceo)->getDato() < val) {
                        nBalanceo = &((*nBalanceo)->hijoDer);
                    } else {
                        nBalanceo = &((*nBalanceo)->hijoIzq);
                    }
                }
                return true;
            } else if (val < buscaNodo->getDato() && buscaNodo->getHijoIzq() != NULL) {
                buscaNodo = buscaNodo->getHijoIzq(); // Se mueve al hijo izquierdo
            } else if (val > buscaNodo->getDato() && buscaNodo->getHijoDer() != NULL) {
                buscaNodo = buscaNodo->getHijoDer(); // Se mueve al hijo derecho
            } else if (val < buscaNodo->getDato() && buscaNodo->getHijoIzq() == NULL) {
                return false; // No se encontró el valor a eliminar
            } else if (val > buscaNodo->getDato() && buscaNodo->getHijoDer() == NULL) {
                return false; // No se encontró el valor a eliminar
            }
        }
    }
    return false; // No se encontró el valor a eliminar
}

// Busca un valor en el árbol, devuelve true si se encuentra, de lo contrario, false
template <class T>
bool ArbolBinarioAVL<T>::buscar(T& val){
    NodoBinarioAVL<T> *buscaNodo = this->raiz; // Empieza desde la raíz
    if (this->raiz == NULL) {
        return false; // Si la raíz es nula, el árbol está vacío
    } else {
        while (buscaNodo->getHijoDer() != NULL || buscaNodo->getHijoIzq() != NULL || buscaNodo->getDato() == val) {
            if (buscaNodo->getDato() == val) { // Si encuentra el valor, devuelve true
                return true;
            } else {
                if (val > buscaNodo->getDato() && buscaNodo->getHijoDer() != NULL) {
                    buscaNodo = buscaNodo->getHijoDer(); // Se mueve al hijo derecho
                } else if (val < buscaNodo->getDato() && buscaNodo->getHijoIzq() != NULL) {
                    buscaNodo = buscaNodo->getHijoIzq(); // Se mueve al hijo izquierdo
                } else if (val > buscaNodo->getDato() && buscaNodo->getHijoDer() == NULL) {
                    return false; // No se encontró el valor
                } else {
                    return false; // No se encontró el valor
                }
            }
        }
        return false; // No se encontró el valor
    }
}

// Recorre el árbol en preorden (Raíz -> Izquierda -> Derecha)
template <class T>
void ArbolBinarioAVL<T>::preOrden(NodoBinarioAVL<T> *inicio){
    cout << inicio->getDato() << " "; // Imprime el dato del nodo actual
    if (inicio->getHijoIzq() != NULL) {
        preOrden(inicio->getHijoIzq()); // Llama recursivamente al subárbol izquierdo
    }
    if (inicio->getHijoDer() != NULL) {
        preOrden(inicio->getHijoDer()); // Llama recursivamente al subárbol derecho
    }
    return;
}

// Recorre el árbol en inorden (Izquierda -> Raíz -> Derecha)
template <class T>
void ArbolBinarioAVL<T>::inOrden(NodoBinarioAVL<T> *inicio){
    if (inicio->getHijoIzq() != NULL) {
        inOrden(inicio->getHijoIzq()); // Llama recursivamente al subárbol izquierdo
    }
    cout << inicio->getDato() << " "; // Imprime el dato del nodo actual
    if (inicio->getHijoDer() != NULL) {
        inOrden(inicio->getHijoDer()); // Llama recursivamente al subárbol derecho
    }
    return;
}

// Recorre el árbol en posorden (Izquierda -> Derecha -> Raíz)
template <class T>
void ArbolBinarioAVL<T>::posOrden(NodoBinarioAVL<T> *inicio){
    if (inicio->getHijoIzq() != NULL) {
        posOrden(inicio->getHijoIzq()); // Llama recursivamente al subárbol izquierdo
    }
    if (inicio->getHijoDer() != NULL) {
        posOrden(inicio->getHijoDer()); // Llama recursivamente al subárbol derecho
    }
    cout << inicio->getDato() << " "; // Imprime el dato del nodo actual
    return;
}

// Recorre el árbol por niveles usando una cola
template <class T>
void ArbolBinarioAVL<T>::nivelOrden(NodoBinarioAVL<T> *inicio){
    queue<NodoBinarioAVL<T>> colaNivel; // Cola para almacenar nodos en cada nivel
    NodoBinarioAVL<T> nodo;
    colaNivel.push(*inicio); // Empuja la raíz a la cola
    while (!colaNivel.empty()) {
        nodo = colaNivel.front(); // Toma el nodo de la parte delantera de la cola
        colaNivel.pop(); // Elimina el nodo de la cola
        cout << nodo.getDato() << " "; // Imprime el dato del nodo
        if (nodo.getHijoIzq() != NULL) {
            colaNivel.push(*nodo.getHijoIzq()); // Empuja el hijo izquierdo a la cola
        }
        if (nodo.getHijoDer() != NULL) {
            colaNivel.push(*nodo.getHijoDer()); // Empuja el hijo derecho a la cola
        }
    }
    return;
}
