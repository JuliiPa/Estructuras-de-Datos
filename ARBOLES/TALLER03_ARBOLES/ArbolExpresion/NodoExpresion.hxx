#include "NodoExpresion.h"
#include <string>

using namespace std;

NodoExpresion::NodoExpresion(){
	this->hijoIzq=NULL;
	this->hijoDer=NULL;
}
NodoExpresion::~NodoExpresion(){
}

char NodoExpresion::getDato(){
	return this->dato;
}

void NodoExpresion::setDato(char val){
	this->dato=val;
	return;
}

NodoExpresion* NodoExpresion::getHijoIzq(){
	return this->hijoIzq;
}

NodoExpresion* NodoExpresion::getHijoDer(){
	return this->hijoDer;
}

void NodoExpresion::setHijoIzq(NodoExpresion* izq){
	this->hijoIzq=izq;
	return;
}
void NodoExpresion::setOperando(bool op){
	this->operando=op;
	return;
}
bool NodoExpresion::getOperando(){
	return this->operando;
}
void NodoExpresion::setHijoDer(NodoExpresion* der){
	this->hijoDer=der;
	return;
}
