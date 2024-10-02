#include "Arbol.h"
#include <iostream>
#include <string>

KDTree::KDTree(int dimension) : raiz(nullptr), dimension(dimension) {}

KDTree::~KDTree() {
    borrarNodos(raiz);
}

void KDTree::borrarNodos(Node* node) {
    if (node) {
        borrarNodos(node->left);
        borrarNodos(node->right);
        delete node;
    }
}

void KDTree::AgregarNodoAlArbol(const std::vector<double>& puntos) {
    raiz = agregarNodo(raiz, puntos, 0);
}

Node* KDTree::agregarNodo(Node* node, const std::vector<double>& puntos, int profundidad) {
    if (node == nullptr) {
        return new Node(puntos);
    }
    int axis = profundidad % dimension;
    if (puntos[axis] < node->getValor(axis)) {
        node->left = agregarNodo(node->left, puntos, profundidad + 1);
    } else {
        node->right = agregarNodo(node->right, puntos, profundidad + 1);
    }
    return node;
}

bool KDTree::buscarNodo(const std::vector<double>& puntos) {
    return buscar(raiz, puntos, 0);
}

bool KDTree::buscar(Node* node, const std::vector<double>& puntos, int depth) {
    if (node == nullptr) {
        return false;
    }

    if (puntos == node->getValores()) {
        return true;
    }

    int axis = depth % dimension;

    if (puntos[axis] < node->getValor(axis)) {
        return buscar(node->left, puntos, depth + 1);
    } else {
        return buscar(node->right, puntos, depth + 1);
    }
}

std::string KDTree::preOrder(Node* node, std::string recorrido) {
    if (node == nullptr) {
        return recorrido;
    }
    recorrido += node->mostrarValor();
    recorrido = preOrder(node->left, recorrido);
    recorrido = preOrder(node->right, recorrido);

    return recorrido;
}


std::string KDTree::inOrder(Node* node, std::string recorrido) {
    if (node == nullptr) {
        return recorrido;
    }
    recorrido = inOrder(node->left, recorrido);
    recorrido += node->mostrarValor();
    recorrido = inOrder(node->right, recorrido);

    return recorrido;
}

std::string KDTree::postOrder(Node* node, std::string recorrido) {
    if (node == nullptr) {
        return recorrido;
    }

    recorrido = postOrder(node->left, recorrido);
    recorrido = postOrder(node->right, recorrido);
    recorrido += node->mostrarValor();

    return recorrido;
}

int KDTree::getdimension() const {
    return dimension;
}

void KDTree::setdimension(int nuevaDimension) {
    dimension = nuevaDimension;
}

Node* KDTree::getraiz() const {
    return raiz;
}
