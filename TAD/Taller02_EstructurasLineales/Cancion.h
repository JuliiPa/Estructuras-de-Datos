// Cancion.h
#ifndef CANCION_H
#define CANCION_H

#include <string> // Incluye la librería para manejar cadenas de caracteres

using namespace std;

// Estructura que representa una canción
struct Cancion {
    string titulo;  // Título de la canción
    string autor;   // Autor de la canción
    string genero;  // Género de la canción
    string album;   // Álbum al que pertenece la canción
    int anio;       // Año de lanzamiento de la canción

    // Constructor que inicializa una canción con sus atributos
    Cancion(const string& t, const string& a, const string& g, const string& al, int y)
        : titulo(t), autor(a), genero(g), album(al), anio(y) {}
};

#endif
