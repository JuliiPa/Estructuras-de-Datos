#ifndef NODO_H
#define NODO_H

#include <vector>
#include <string>
class Node {
private:
    std::vector<double> Valores;

public:
    Node(const std::vector<double>& puntos);
    void setValores(const std::vector<double>& puntos);
    double getValor(int indice) const;
    std::vector<double>& getValores() const;
    int getDimensiones() const;
    Node* left;
    Node* right;
    std::string mostrarValor() const;
};

#endif // NODO_H
