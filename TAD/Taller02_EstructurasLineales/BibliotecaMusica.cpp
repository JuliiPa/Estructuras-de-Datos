// BibliotecaMusica.cpp
#include "BibliotecaMusica.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Función para leer las canciones desde un archivo y almacenarlas en el vector de canciones
void BibliotecaMusica::leerDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo); // Abre el archivo de entrada
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl; // Muestra un error si no se puede abrir el archivo
        return;
    }

    string linea;
    int numeroCanciones;
    getline(archivo, linea); // Lee la primera línea del archivo (número de canciones)
    numeroCanciones = stoi(linea); // Convierte la primera línea a un número entero

    // Lee cada línea de canción del archivo y la agrega al vector de canciones
    for (int i = 0; i < numeroCanciones; ++i) {
        getline(archivo, linea); // Lee la línea de datos de la canción
        size_t pos = 0;
        string datos[5];
        
        // Divide la línea por el carácter '|' y guarda los datos en un array
        for (int j = 0; j < 5; ++j) {
            pos = linea.find('|'); // Encuentra la posición del separador '|'
            datos[j] = linea.substr(0, pos); // Extrae el dato hasta el separador
            linea.erase(0, pos + 1); // Elimina el dato extraído de la línea
        }
        
        // Crea un objeto Cancion y lo añade al vector de canciones
        canciones.emplace_back(datos[0], datos[1], datos[2], datos[3], stoi(datos[4]));
    }

    archivo.close(); // Cierra el archivo
}

// Función para listar todos los autores presentes, ordenados alfabéticamente
void BibliotecaMusica::listarAutoresOrdenados() {
    vector<string> autores;
    
    // Extrae los nombres de los autores y los almacena en un vector
    for (const auto& cancion : canciones) {
        autores.push_back(cancion.autor);
    }

    sort(autores.begin(), autores.end()); // Ordena los autores alfabéticamente
    autores.erase(unique(autores.begin(), autores.end()), autores.end()); // Elimina duplicados

    // Imprime los autores ordenados
    for (const auto& autor : autores) {
        cout << autor << endl;
    }
}

// Función para listar todas las canciones de un autor específico, ordenadas alfabéticamente
void BibliotecaMusica::listarCancionesPorAutor(const string& autorBuscado) {
    vector<Cancion> cancionesPorAutor;

    // Encuentra todas las canciones del autor especificado
    for (const auto& cancion : canciones) {
        if (cancion.autor == autorBuscado) {
            cancionesPorAutor.push_back(cancion);
        }
    }

    // Ordena las canciones por título
    sort(cancionesPorAutor.begin(), cancionesPorAutor.end(), [](const Cancion& a, const Cancion& b) {
        return a.titulo < b.titulo;
    });

    // Imprime las canciones del autor ordenadas
    for (const auto& cancion : cancionesPorAutor) {
        cout << cancion.titulo << endl;
    }
}

// Función para listar todos los álbumes presentes, ordenados cronológicamente
void BibliotecaMusica::listarAlbumesOrdenados() {
    vector<pair<string, int>> albumes;

    // Extrae los álbumes y sus años de lanzamiento y los almacena en un vector de pares
    for (const auto& cancion : canciones) {
        albumes.emplace_back(cancion.album, cancion.anio);
    }

    // Ordena los álbumes cronológicamente
    sort(albumes.begin(), albumes.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    });

    // Elimina duplicados de álbumes
    albumes.erase(unique(albumes.begin(), albumes.end()), albumes.end());

    // Imprime los álbumes ordenados cronológicamente
    for (const auto& album : albumes) {
        cout << album.first << " (" << album.second << ")" << endl;
    }
}

// Función para listar todas las canciones de un álbum específico, ordenadas alfabéticamente
void BibliotecaMusica::listarCancionesPorAlbum(const string& albumBuscado) {
    vector<Cancion> cancionesPorAlbum;

    // Encuentra todas las canciones del álbum especificado
    for (const auto& cancion : canciones) {
        if (cancion.album == albumBuscado) {
            cancionesPorAlbum.push_back(cancion);
        }
    }

    // Ordena las canciones del álbum por título
    sort(cancionesPorAlbum.begin(), cancionesPorAlbum.end(), [](const Cancion& a, const Cancion& b) {
        return a.titulo < b.titulo;
    });

    // Imprime las canciones del álbum ordenadas
    for (const auto& cancion : cancionesPorAlbum) {
        cout << cancion.titulo << endl;
    }
}

// Función para listar todas las canciones y sus álbumes, ordenadas alfabéticamente primero por el álbum y luego por el nombre de la canción
void BibliotecaMusica::listarCancionesYAlbumesOrdenados() {
    // Ordena las canciones primero por álbum y luego por título de canción
    sort(canciones.begin(), canciones.end(), [](const Cancion& a, const Cancion& b) {
        if (a.album == b.album) {
            return a.titulo < b.titulo;
        }
        return a.album < b.album;
    });

    // Imprime las canciones y sus álbumes ordenados
    for (const auto& cancion : canciones) {
        cout << cancion.album << " - " << cancion.titulo << endl;
    }
}
