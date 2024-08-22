/******************************************
Fecha: 21/08/2024
Autor: Juliana Pacheco
Tema: Taller00 Estructuras y punteros
Ejercicio 2: CREACION DE FACTURA CON DETALLES
*******************************************/

#include <iostream>
#include <fstream>

using namespace std;

//Estructura de la factura
struct factura{
  string nombre;
  int cedula;
  int cantidad;
  double precio;
  string nombreProducto;
};

//Funcion para impresion (generar el fichero)
void imprimirFichero(factura *factura){
  ofstream fichero ("factura.txt");
  
//Se necesita comprobar si el sistema operativo a aberito el fichero
  if (fichero.is_open()){
  fichero << endl << "Nombre del cliente: " << (*factura).nombre << endl;
  fichero << "Numero de cedula: " << (*factura).cedula << endl;
  fichero << "Nombre del producto: " << (*factura).nombreProducto << endl;
  fichero << "Cantidad de productos: " << (*factura).cantidad << endl;
  fichero << "Precio del producto: " << (*factura).precio << endl;
  fichero << "Total a pagar: " << (*factura).cantidad*(*factura).precio << endl;

    //Se cierra el fichero
    fichero.close();
    
    } else {
  cout << "No se pudo abrir el fichero";
  }
}

int main(){
  //Datos de factura encapsulados, apuntados por puntero
  factura objetoFacturas;
  factura *puntero = &objetoFacturas;

  //Captura de datos del cliente
  cout << "Ingrese el nombre del cliente: ";
  cin >> (*puntero).nombre;
  cout << "Ingrese el numero de cedula: ";
  cin >> (*puntero).cedula;
  cout << "Ingrese el nombre del producto: ";
  cin >> (*puntero).nombreProducto;
  cout << "Ingrese la cantidad de productos: ";
  cin >> (*puntero).cantidad;
  cout << "Ingrese el precio del producto: ";
  cin >> (*puntero).precio;
  cout << "Valor a pagar: " << (*puntero).cantidad*(*puntero).precio << endl;

  //Se llama a la funcion para imprimir en el fichero
     imprimirFichero(puntero);
  
  return 0;
}
