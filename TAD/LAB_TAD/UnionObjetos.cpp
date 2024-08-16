#include <string>
#include <list>
#include "OBJETO/Objeto.h"
#include "OBJETO/Punto.h"

using namespace std;

/* 
Funcion que recibe dos nubes de puntos y devuelve una nueva nube de puntos 
que contiene los puntos que se encuentran en ambas nubes.
*/
list<Punto> unirNubePuntos(Objeto objeto1, Objeto objeto2){
	
	list<Punto> nubePuntosUnido;
	
	for (const Punto& punto : objeto1.getNubePuntos()){
		nubePuntosUnido.push_back(punto);
	}
	for (const Punto& punto : objeto2.getNubePuntos()){
		nubePuntosUnido.push_back(punto);
	}
	
	return nubePuntosUnido;
};

/*
Funcion que calcula el centroide de una nube de puntos. El cual es el punto
con las coordenadas x, y y z que se encuentran en el promedio de la nube.
*/
Punto calcularCentroide(Objeto objeto){
	Punto puntoPromedio;
	int promedioX = 0;
	int promedioY = 0;
	int promedioZ = 0;
	int tamanoNubePuntos = objeto.getNubePuntos().size();

	for(Punto& punto : objeto.getNubePuntos()){
		promedioX += punto.getX();
		promedioY += punto.getY();
		promedioZ += punto.getZ();
	}

	promedioX = promedioX / tamanoNubePuntos;
	promedioY = promedioY / tamanoNubePuntos;
	promedioZ = promedioZ / tamanoNubePuntos;

	puntoPromedio.setCoordenadas(promedioX, promedioY, promedioZ);

	return puntoPromedio;
};

/*
Funcion que crea un objeto nuevo con todos los puntos que se encuentran
en los dos objetos dados por parametro
*/
Objeto unirObjetos( Objeto objeto1, Objeto objeto2){
	
	Objeto objetoUnido;
	
	objetoUnido.setNube(unirNubePuntos(objeto1, objeto2));
	objetoUnido.setCentroide(calcularCentroide(objetoUnido));
	
	return objetoUnido;
};
