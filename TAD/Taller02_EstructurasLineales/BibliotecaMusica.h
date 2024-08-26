// BibliotecaMusica.h
#ifndef BIBLIOTECA_MUSICA_H
#define BIBLIOTECA_MUSICA_H

#include "Cancion.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

// Clase que maneja la biblioteca de música
class BibliotecaMusica {
private:
    vector<Cancion> canciones; // Almacena todas las canciones

public:
    // Lee las canciones desde un archivo de texto
    void leerDesdeArchivo(const string& nombreArchivo);
    
    // Lista todos los autores ordenados alfabéticamente
    void listarAutoresOrdenados();
    
    // Lista todas las canciones de un autor específico
    void listarCancionesPorAutor(const string& autor);
    
    // Lista todos los álbumes ordenados cronológicamente
    void listarAlbumesOrdenados();
    
    // Lista todas las canciones de un álbum específico
    void listarCancionesPorAlbum(const string& album);
    
    // Lista todas las canciones y sus álbumes ordenados alfabéticamente
    void listarCancionesYAlbumesOrdenados();
};

#endif
