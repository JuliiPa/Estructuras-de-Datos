/*********************************************
Nombre : Juliana Pacheco Amaya
Fecha : 22/07/2024
Reto 1 TAD-Cafeteras
*********************************************/

#include <iostream>
using namespace std;


//Tipo de Dato Abstracto (TAD) para las Cafeteras
class Cafetera {
public:
    virtual void Capuchino(int op3) = 0;
    virtual void Tinto(int op3) = 0;
};


//Implementación del TAD para OSTER
class Oster : public Cafetera {
public:
    void Capuchino(int op3) {
        if (op3 == 1) {
            cout << "Oster haciendo capuchino Cargado!!!" << endl;
        }
        else {
            cout << "Oster haciendo Capuchino!!!" << endl;
        }

    }


    void Tinto(int op3) {
        if (op3 == 1) {
            cout << "Oster haciendo tinto Cargado!!!" << endl;
        }
        else {
            cout << "Oster haciendo tinto!!!" << endl;
        }

    }

};


//Implementación del TAD para Haceb
class Haceb : public Cafetera {
public:
    void Capuchino(int op3) {
        if (op3 == 1) {
            cout << "Haceb haciendo capuchino Cargado!!!" << endl;
        }
        else {
            cout << "Haceb haciendo Capuchino!!!" << endl;
        }

    }

    void Tinto(int op3) {
        if (op3 == 1) {
            cout << "Haceb haciendo tinto Cargado!!!" << endl;
        }
        else {
            cout << "Haceb haciendo tinto!!!" << endl;
        }

    }
};



int main() {

    int op, op2, op3;

    //Creación objeto Oster
    Cafetera* c_Oster = new Oster();
    //Creación objeto Haceb
    Cafetera* c_Haceb = new Haceb();

    cout << "    ¡¡¡ BIENVENIDO A SU CAFETERA !!!" << endl;
    cout << endl << "Seleccione una de las siguientes opciones..." << endl;
    cout << "Seleccione la marca de cafetera que desea:" << endl;
    cout << "  1. Oster" << endl;
    cout << "  2. Haceb" << endl;
    cin >> op;

    cout << endl << "Seleccione el tipo de cafe que desea preparar:" << endl;
    cout << "  1. Capuchino" << endl;
    cout << "  2. Tinto" << endl;
    cin >> op2;

    cout << endl << "Desea el cafe cargado?" << endl;
    cout << "  1. si" << endl;
    cout << "  2. no" << endl;
    cin >> op3;


    if (op == 1 && op2 == 1) {
        c_Oster->Capuchino(op3);
    }
    else if (op == 1 && op2 == 2) {
        c_Oster->Tinto(op3);
    }
    else if (op == 2 && op2 == 1) {
        c_Haceb->Capuchino(op3);
    }
    else {
        c_Haceb->Tinto(op3);
    }

    cout << "Fin del programa :)";

    return 0;
}
