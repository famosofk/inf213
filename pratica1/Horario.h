#ifndef HORARIO_H
#define HORARIO_H
#include<iostream>
using namespace std;
class Horario{
    private:
    int hora, minuto, segundo;
    public:
    void setHora(const int h);
    void setMinuto(const int m);
    void setSegundo(const int s);
    const int getHora() const;
    const int getMinuto() const;
    const int getSegundo() const;
    const int compHorario(const Horario& horario2) const;
    const int difSegundos(const Horario& horario2) const;
    const void imprime() const;
    Horario();
    Horario(const int h, const int m, const int s);
    ~Horario();
    friend istream& operator>>(istream& is, Horario& hor); 
    friend ostream& operator<<(ostream& os, Horario& hor);

};


#endif