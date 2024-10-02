#include "Binary Search Tree.h"
#include <iostream>

using namespace std;

int main(){

    BST arbol(5);

    arbol.agregarNumero(6);
    arbol.agregarNumero(4);
    arbol.agregarNumero(2);
    arbol.agregarNumero(3);
    arbol.agregarNumero(7);

    cout << "Esta el 3?: " << arbol.buscarNumero(3) << endl;
    cout << "Esta el 7?: " << arbol.buscarNumero(7) << endl;
    cout << "Esta el 1?: " << arbol.buscarNumero(1) << endl;

    cout << "InOrder\n";
    arbol.busquedaInOrder();
    cout << "PreOrder\n";
    arbol.busquedaPreOrder();
    cout << "PostOrder\n";
    arbol.busquedaPostOrder();

    arbol.eliminarNumero(3);

    cout<< "InOrder despues eliminar el 3\n";
    arbol.busquedaInOrder();

    return 0;
}