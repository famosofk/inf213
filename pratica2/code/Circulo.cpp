#include "FigBase.h"
#include "Circulo.h"
#include<iostream>


Circulo::Circulo() : FigBase(){}
Circulo::Circulo(double x, double y, double r, int e, int c, int t) : FigBase(x, y, e, c, t){

}
void Circulo::setRaio(double r){
    this->raio = r;
}
double Circulo::getRaio()const{
    return this->raio;
}
float Circulo::area() const{
    return pi*raio*raio;
}
float Circulo::perimetro()const{
    return 2*pi*raio;
}
void Circulo::imprime()const{
    FigBase::imprime();
}

void le(Circulo& c){
    FigBase::le(c);
    double r;
    std::cin >> r;
    c.setRaio(r);
}

ostream& operator<<(ostream& os, Circulo& c){
    FigBase::imprime();
    std::cout<<"Raio: " << c.getRaio();
    std::cout << "Area: " << area() << " Perimetro: " << perimetro << "\n";
}
