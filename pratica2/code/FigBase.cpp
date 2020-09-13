#include "FigBase.h"

FigBase::FigBase(){}
FigBase::FigBase(double x1, double y1, int e, int c, int t){
    setX(x1); setY(y1); setEspessura(e); setCor(c); setTipo(t);
}

void FigBase::setX(double x1){}
double const FigBase::getX() const{}
void FigBase::setY(double y1){}
double const FigBase::getY()const{}
void FigBase::setEspessura(int e){}
const int FigBase::getEspessura() const{}
void FigBase::setCor(int c){}
int const FigBase::getCor() const{}
void FigBase::setTipo(int t){}
int const FigBase::getTipo() const{}
