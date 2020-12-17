#include "FigBase.h"
#include "Retangulo.h"
#include<iostream>

Retangulo::Retangulo() : FigBase(){}
Retangulo::Retangulo(double x, double y, double l, double a, int esp, int c, int t ) : FigBase(x, y, esp, c, t){
    setAltura(a); setLargura(l);
}
void Retangulo::setLargura(double l){
    this->largura=l;
}

const double Retangulo::getLargura()const{
    return this->largura;
}

void Retangulo::setAltura(double a){
    this->altura = a;
}

const double Retangulo::getAltura()const{
    return this->altura;
}

const float Retangulo::area()const{
    return altura*largura;
}

const float Retangulo::perimetro() const{
    return altura*2 + largura*2;
}

operator<<(ostream & os, Retangulo &r){
    r.imprime()
    return os;
}

void Retangulo::imprime() const{
    FigBase::imprime();
    std::cout << "Altura: " << altura << " Largura: " << largura << "\n";
    std::cout << "Area: " << area() << " Perimetro: " << perimetro << "\n";
}
