/************************************
 Nombres: JULIANA PACHECO, DANIEL GONZALES, NICOLAS ALGARA
 TEMA: TALLER ARBOLES
 FECHA: 22/09/2024
 ***********************************/

#include<iostream> // Incluye la librería estándar de entrada y salida
#include "ArbolBinarioAVL.h" // Incluye la definición de la clase ArbolBinarioAVL
#include "NodoBinarioAVL.h" // Incluye la definición de la clase NodoBinarioAVL

using namespace std; // Usa el espacio de nombres estándar para simplificar el código

int main(int argc, char* argv[])
{
    // Crear una instancia del árbol binario AVL
    ArbolBinarioAVL<int> arbolito;
    
    // Bucle infinito para leer comandos y valores desde la entrada estándar
    while(true)
    {
        int dato;
        char op;
        
        // Leer operación (A: agregar, E: eliminar) y valor desde la entrada
        cin >> op >> dato;

        // Insertar el valor en el árbol si se ingresa 'A'
        if(op == 'A') {
            cout << "Insertando: " << dato << endl; // Mensaje de depuración
            arbolito.insertar(dato);
        }
        // Eliminar el valor del árbol si se ingresa 'E'
        else if(op == 'E') {
            cout << "Eliminando: " << dato << endl; // Mensaje de depuración
            arbolito.eliminar(dato);
        }
        // Salir del bucle si se ingresa cualquier otro carácter
        else {
            cout << "Saliendo..." << endl; // Mensaje de depuración
            break;
        }
    }

    // Imprimir el recorrido Inorden del árbol
    cout << endl << "Inorden: " << endl;
    arbolito.inOrden(arbolito.getRaiz());

    // Imprimir el recorrido Preorden del árbol
    cout << endl << "Preorden: " << endl;
    arbolito.preOrden(arbolito.getRaiz());

    // Imprimir el recorrido Posorden del árbol
    cout << endl <<"Posorden: " << endl;
    arbolito.posOrden(arbolito.getRaiz());

    return 0;
}
