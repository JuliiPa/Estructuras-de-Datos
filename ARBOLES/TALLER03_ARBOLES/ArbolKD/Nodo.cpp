#include "Nodo.h"
#include <string>

Node::Node(const std::vector<double> &puntos) : Valores(puntos), left(nullptr), right(nullptr) {}

void Node::setValores(const std::vector<double> &puntos)
{
    Valores = puntos;
}

double Node::getValor(int indice) const
{
    return Valores[indice];
}

int Node::getDimensiones() const
{
    return Valores.size();
}

std::vector<double>& Node::getValores() const {
    return const_cast<std::vector<double>&>(Valores);
}
std::string Node::mostrarValor() const {
    std::string result = "(";
    for (size_t i = 0; i < Valores.size(); ++i) {
        result += std::to_string(Valores[i]);
        if (i < Valores.size() - 1) {
            result += ",";
        }
    }
    result += ")";
    return result;
}