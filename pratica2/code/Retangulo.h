#ifndef RETANGULO_H
#define RETANGULO_H

#include "FigBase.h"

class Retangulo: public FigBase{

    private:
    double largura, altura;

    public:
    Retangulo();
    Retangulo(double, double, double, double, int, int, int);
    const double getLargura() const;
    const double getAltura() const;
    void setLargura(const double);
    void setAltura(const double);
    const float area() const;
    const float perimetro() const;
    void imprime() const;
    friend operator<<(ostream& os, Retangulo &r);
    


};


#endif