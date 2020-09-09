#ifndef CIRCULO_H
#define CIRCULO_H

#include "FigBase.h"

class Circulo : public FigBase{

    private:
    double raio, pi;

    public:
    Circulo();
    Circulo(double, double, double, int, int, int);
    double getRaio() const;
    void setRaio(const double);
    float area() const;
    float perimetro() const;
    void imprime() const;

};


#endif