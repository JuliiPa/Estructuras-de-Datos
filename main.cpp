#include <iostream>
using namespace std;

/*Tipo de Dato Abstracto para las Cafeteras*/
class Cafetera {
public:
    virtual void Capuchino(bool option) = 0;
    virtual void Tinto(bool option) = 0;
};

/*Implementación del TAD para OSTER*/
class Oster : public Cafetera {
public:
    void Capuchino(bool option) {
        if(option == true){
            cout << "Oster haciendo capuchino Cargado!!!" << endl;
        }else{
            cout << "Oster haciendo Capuchino!!!" << endl;
        }
        
    }

    void Tinto(bool option){
        if( option == true){
            cout << "Oster haciendo tinto Cargado!!!" << endl;
        } else{
            cout << "Oster haciendo tinto!!!" << endl;
        }
        
    }
    
};


class Haceb : public Cafetera{
public:
void Capuchino(bool option) {
    if(option == true){
        cout << "Haceb haciendo capuchino Cargado!!!" << endl;
    }else{
        cout << "Haceb haciendo Capuchino!!!" << endl;
    }

}

    void Tinto(bool option){
        if(option == true){
            cout << "Haceb haciendo tinto Cargado!!!" << endl;
        }
        else{
            cout << "Haceb haciendo tinto!!!" << endl;
        }
        
    }
};

int main() {

    int op, op2;

    
    /*Creación objeto Oster*/
    Cafetera* c_Oster = new Oster();
    /*Creación objeto Haceb*/
    Cafetera* c_Haceb = new Haceb();
   
    
    cout<<"Que marca de cafetera desea seleccionar"<<endl;
    cout<<"1. Oster"<<endl;
    cout<<"2. Haceb"<<endl;
    cin>>op;

    cout<<"Que tipo de cafe desea preparar"<<endl;
    cout<<"1. Capuchino"<<endl;
    cout<<"2. Tinto"<<endl;
    cin>>op2;


    if(op == 1 && op2 == 1){
        c_Oster->Capuchino(false);
    }else if(op ==1 && op2 ==2){
        c_Oster->Tinto(true);
    }else if(op == 2 && op2 == 1){
        c_Haceb->Capuchino(true);
    }else{
        c_Haceb->Tinto(false);
    }
    

    return 0;
}
