/******************************************
Fecha: 21/08/2024
Autor: Juliana Pacheco
Tema: Taller00 Estructuras y punteros
Ejercicio 1: LLENAR ARRAY CON NUMEROS ALEATORIOS
*******************************************/

#include <iostream>
#include <ctime> //Time ()
#include <cstdlib> //Srand () y Rand ()
using namespace std;

struct venta{
  int cantidad;
  double precio;
};

//Funcion para retornar un numero aleatori entre 0 y 25
int numero_aleatorio(){
  return rand()%26;
}

int main(){
  // Crea el array
  int array [10];
  
  //Crea la semilla
  srand(time(0));

  //Se crea puntero
  int *puntero= array;
  
  //Llenar el array con numeros aletorios
    for (int i=0; i<10; i++){
      array[i] = numero_aleatorio();
    }
  
  //imprime usando el puntero
  for (int i=0; i<10; i++){
    cout << "Valores del array [" << i << "] = " << *puntero++ << " " << "      Direccion en memoria: " << puntero << endl;
  }
}
