/**************************************************
 Fecha: 25/08/2024 
 Tema: Estructura de Datos
 Taller 02: Estructuras de datos lineales
 ************************************************/
// main.cpp
#include "BibliotecaMusica.h"
#include <iostream>
#include <string>

using namespace std; // Utiliza el espacio de nombres estándar para simplificar el código

// Función para mostrar el menú de opciones al usuario
void mostrarMenu() {
    cout << "JaveMusic Menu:" << endl;
    cout << "1. Leer canciones desde archivo" << endl;
    cout << "2. Listar autores ordenados" << endl;
    cout << "3. Listar canciones por autor" << endl;
    cout << "4. Listar albumes ordenados" << endl;
    cout << "5. Listar canciones por album" << endl;
    cout << "6. Listar canciones y albumes ordenados" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    BibliotecaMusica biblioteca; // Crea una instancia de la clase BibliotecaMusica
    int opcion; // Variable que almacena la opción seleccionada por el usuario
    string entrada; // Variable que maneja la entrada del usuario

        cout << "***** BIENVENIDO A JAVEMUSIC *****" << endl;
        cout << "Este programa permite acceder a musica almacenada segun el archivo que elija" << endl;
        cout << "Tambien le permite realizar busquedas de sus canciones de diferentes maneras" << endl;
        cout << "-----------------------------" << endl;
        cout << "  Archivos nombre de los archivos que puede elegir:" << endl;
        cout << "    - example1.txt" << endl;
        cout << "    - example2.txt" << endl;
        cout << "    - example3.txt" << endl;
        cout << "    - example4.txt" << endl;
        cout << "    - example5.txt" << endl << endl;

    do {
        mostrarMenu(); // Muestra el menú al usuario
        cin >> opcion; // Lee la opción seleccionada por el usuario
        cin.ignore(); // Ignora el salto de línea

        switch (opcion) {
            case 1:
                // Solicita el nombre del archivo al usuario
                cout << "Ingrese el nombre del archivo: ";
                getline(cin, entrada);
                biblioteca.leerDesdeArchivo(entrada); // Lee canciones desde el archivo proporcionado
                break;
            case 2:
                // Lista todos los autores en orden alfabético
                biblioteca.listarAutoresOrdenados();
                break;
            case 3:
                // Solicita el nombre del autor y lista sus canciones
                cout << "Ingrese el nombre del autor: ";
                getline(cin, entrada);
                biblioteca.listarCancionesPorAutor(entrada);
                break;
            case 4:
                // Lista todos los álbumes en orden cronológico
                biblioteca.listarAlbumesOrdenados();
                break;
            case 5:
                // Solicita el nombre del álbum y lista las canciones del álbum
                cout << "Ingrese el nombre del album: ";
                getline(cin, entrada);
                biblioteca.listarCancionesPorAlbum(entrada);
                break;
            case 6:
                // Lista todas las canciones y álbumes en orden alfabético
                biblioteca.listarCancionesYAlbumesOrdenados();
                break;
            case 0:
                // Sale del programa
                cout << "Saliendo del programa." << endl;
                break;
            default:
                // Muestra un mensaje si la opción es inválida
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}
