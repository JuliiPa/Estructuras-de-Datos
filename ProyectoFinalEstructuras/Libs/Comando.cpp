#include "Comando.h"

// Constructor que recibe principal, ayuda y correcto
Comando::Comando(std::string &Nuevoprincipal, std::list<std::string> nuevaAyuda, std::list<std::string> Nuevocorrecto)
{
    principal = Nuevoprincipal;
    ayuda = nuevaAyuda;
    correcto = Nuevocorrecto;
}

// Métodos para obtener los atributos
std::string Comando::getPrincipal()
{
    return principal;
}

std::list<std::string> Comando::getAyuda()
{
    return ayuda;
}

std::list<std::string> Comando::getCorrecto()
{
    return correcto;
}
std::string Comando::mostrarAyudaCompleta()
{
    std::string ayudis="";
    std::list<std::string>::iterator it=ayuda.begin();
    std::list<std::string>::iterator it2=correcto.begin();
    for(int i=0;i<ayuda.size();i++)
    {
        ayudis+="Correcta forma de usarse:\n"+*it2+"\n"+*it+"\n";
        it++;
        it2++;
    }
    return ayudis;
}
