#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "FigBase.h"

class Segmento: public FigBase{

    private:
    double x2, y2;

    public:
    Segmento();
    Segmento(double, double, double, double, int, int, int);
    double const getX2()const;
    double const getY2() const;
    void setX2(const double);
    void setY2(const double);
    float area() const;
    float perimetro() const;
    void imprime() const;


};




#endif