#include "FigBase.h"
#include "Segmento.h"
#include<iostream>

Segmento::Segmento() : FigBase(){}
Segmento::Segmento(double x, double y, double x2, double y2, int e, int c, int t) : FigBase(x, y, e, c, t){}

void Segmento::setX2(double x){
    this->x2 = x;
}
double const Segmento::getX2() const{
    return this->x2;
}
void Segmento::setY2(double y){
    this->y2 = y;
}
double const Segmento::getY2() const{
    return this->y2;
}

float Segmento::area() const{
    return 0;
}
float Segmento::perimetro() const{

}

void Segmento::imprime() const{
    FigBase::imprime();
}