#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"
#include <vector>
#include <string>

class KDTree {
private:
    Node* raiz;
    int dimension;

public:
    KDTree(int dimension);
    ~KDTree();
    void borrarNodos(Node* node);
    void AgregarNodoAlArbol(const std::vector<double>& puntos);
    Node* agregarNodo(Node* node, const std::vector<double>& puntos, int depth);
    bool buscarNodo(const std::vector<double>& puntos);
    bool buscar(Node* node, const std::vector<double>& puntos, int depth);
    std::string preOrder(Node* node, std::string recorrido);
    std::string inOrder(Node* node,std::string recorrido);
    std::string postOrder(Node* node, std::string recorrido);
    int getdimension() const;
    void setdimension(int nuevaDimension);
    Node* getraiz() const;
};

#endif // ARBOL_H