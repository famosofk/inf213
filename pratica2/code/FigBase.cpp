#include "FigBase.h"
#include<iostream>


FigBase::FigBase(){}
FigBase::FigBase(double x1, double y1, int e, int c, int t){
    setX(x1); setY(y1); setEspessura(e); setCor(c); setTipo(t);
}

void FigBase::setX(double x1){
    this->x = x1;
}
double const FigBase::getX() const{
    return this->x;
}
void FigBase::setY(double y1){
    this->y = y1;
}
double const FigBase::getY()const{
    return this->y; 
}
void FigBase::setEspessura(int e){
       if(e>5)
        e=5;
    else if(e<1)
        e=1;
    this->espessura = e;
}
const int FigBase::getEspessura() const{
    return this->espessura;
}
void FigBase::setCor(int c){
       if(c>5)
        c=5;
    else if(c<1)
        c=1;
    this->cor = c;
}
int const FigBase::getCor() const{
    return this->cor;
}
void FigBase::setTipo(int t){
    if(t>3)
        t=3;
    else if(t<1)
        t=1;
    tipo = t;
}
int const FigBase::getTipo() const{
    return this->tipo;
}

operator<<(ostream & os, FigBase & f){
    f.imprime();
    return os;
}

operator>>(istream& is, FigBase& f){
    return is;    
}

void FigBase::le(FigBase &f){
    double x1, x2;
    int e, c, t;
    cin >> x1>> x2>> e>> c>> t;
    f.setX(x1); f.setY(x2); f.setEspessura(e); f.setCor(c); f.setTipo(t); 
}


void FigBase::imprime() const {
    std::cout << "x: " <<x <<" y: " << y << "\n"
    std::cout << " ---*--- ATRIBUTOS DA LINHA ---*--- " << "\n";
    std::cout << "Espessura: " << espessura << "  Cor: " << cor << "  Tipo: " <<tipo << "\n";
}