#ifndef FUNCIONESMAIN_H
#define FUNCIONESMAIN_H

#include <iostream>
#include <list>
#include <string>
#include "Comando.h"
#include "Objeto.h"

void CargarComando(std::list<Comando> comandos, std::list<Objeto> &Objetos);
void BuscarComandoAyuda(std::string ingresado, std::list<Comando> comandos);
void Ayuda(std::list<Comando> comandos);
bool cargar(std::string NombreArchivo, std::list<Objeto> &Objetos);
void listado(std::list<Objeto> &Objetos);
Vertice getMinVertice(std::list<Vertice> vertices);
Vertice getMaxVertice(std::list<Vertice> vertices);
Objeto& crearEnvolvente(std::string nombreObjeto,Vertice min,Vertice max);
void envolvente(std::list<Objeto> &Objetos);
void envolvente(std::string nombreObjeto,std::list<Objeto> &Objetos);
void descargar(std::string nombreObjeto,std::list<Objeto> &Objetos);
void Guardar(std::string nombreObjeto,std::string nombreArchivo,std::list<Objeto> &Objetos);
std::list<Comando> CargarComandos();

#endif // FUNCIONESMAIN_H
