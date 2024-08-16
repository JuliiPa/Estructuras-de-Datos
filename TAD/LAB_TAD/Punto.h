#ifndef PUNTO_H  // Estructura para crear TAD
#define PUNTO_H

//Diseño de TAD

class Punto {
public:
    float x, y, z;  // Coordenadas del punto
    int r, g, b;    // Color del punto (RGB)

    //Constructor Punto
    Punto(float x = 0, float y = 0, float z = 0, int r = 255, int g = 255, int b = 255)
        : x(x), y(y), z(z), r(r), g(g), b(b) {}
};

#endif
