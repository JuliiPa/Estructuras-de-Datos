#ifndef VERTICE_H
#define VERTICE_H

class Vertice {
private:
    float coord[3];
    int indice;

public:
    // Constructor
    Vertice(float x, float y, float z,int nuevoIndice);

    // Métodos para obtener las coordenadas
    float getX() const;
    float getY() const;
    float getZ() const;
    int getIndice() const;

    // Métodos para establecer las coordenadas
    void setX(float x);
    void setY(float y);
    void setZ(float z);

    bool sonIguales(const Vertice& otro )const;
    double DistanciaEuclidiana(float x,float y,float z) const;
};

#endif
