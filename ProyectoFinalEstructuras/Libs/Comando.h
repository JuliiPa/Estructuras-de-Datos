#ifndef COMANDO_H
#define COMANDO_H

#include <string>
#include <list>

class Comando {
private:
    std::string principal;
    std::list<std::string> ayuda;
    std::list<std::string> correcto;

public:
    // Constructor que recibe principal, ayuda y correcto
    Comando( std::string& principal,  std::list<std::string> ayuda,  std::list<std::string> correcto);

    // Métodos para obtener los atributos (opcional)
    std::string getPrincipal() ;
    std::list<std::string> getParametros() ;
    std::list<std::string> getAyuda() ;
    std::list<std::string> getCorrecto();
    std::string mostrarAyudaCompleta();
};

#endif
