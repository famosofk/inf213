#include "Horario.h"
#include<iostream>
using namespace std;

Horario::Horario(){}
Horario::Horario(const int h, const int m, const int s){
    setHora(h); setMinuto(m);setSegundo(s);   
}
Horario::~Horario(){}

void Horario::setHora(const int h){
    if(h> 0 && h <24)
        this->hora = h;
    else{
        if(h<0)
            this->hora = 0;
        else if(h>23)
            this->hora = 23;
    }
}
void Horario::setMinuto(const int m){
    if(m>0 && m<60)
    this->minuto = m;
    else{
        if(m<0)
        this->minuto = 0;
        else if(m>59)
        this->minuto = 59;
    }
    
}
void Horario::setSegundo(const int s){
     if(s>0 && s<60)
    this->segundo = s;
    else{
        if(s<0)
        this->segundo = 0;
        else if(s>59)
        this->segundo= 59;
    }
}

ostream& operator<<(ostream& os, Horario& hor){
    hor.imprime();
    return os;
}

istream& operator>>(istream& is, Horario& hor){
    int ho, mi, se;
    cin >> ho >> mi >> se;
    hor.setHora(ho); hor.setMinuto(mi); hor.setSegundo(se);
    return is;
}

void const Horario::imprime() const{
    cout << hora << " " << minuto << " " << segundo;
}

int const Horario::compHorario(const Horario& horario2) const{
    int resultado = 0;
    if(this->hora > horario2.hora)
        resultado = 1;
        else
        {
            if(this->hora < horario2.hora)
            resultado = -1;
            else{
                if(this->minuto > horario2.minuto)
                resultado = 1;
                else{
                    if(this->segundo > horario2.segundo)
                    resultado = -1;
                    else
                        resultado = 1;
                }
            }
        }
}
int const Horario::difSegundos(const Horario& horario2) const{
    int hours = (this->hora - horario2.hora) * 3600;
    int minutes = (this->minuto - horario2.minuto) * 60;
    int seconds = (this->segundo - horario2.segundo);
    return abs(hours) + abs(minutes) + abs(seconds);
}