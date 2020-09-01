#include "Data.h"

#include<iostream>
using namespace std;

Data::Data(){}
Data::~Data(){}
Data::Data(const int d, const int m, const int a){
    setDia(d);
    setMes(m);
    setAno(a);
}

const int Data::difDias(const Data& data2){
    int dias, meses, anos;
    dias = this->dia - data2.dia;
    meses = (this->mes - data2.mes) * 30;
    anos = (this->ano - data2.ano) * 365;
    return abs(dias) + abs(meses) + abs(anos);
}

void Data::setDia(const int d){
    if(d > 0 && d < 31)
        this->dia = d;
    else{
        if(d<1)
        this->dia = 1;
        else
            this->dia = 30;
    }
}

void Data::setMes(const int m){
    if(m >0 && m <13)
        this->mes = m;
    else{
        if(m >12)
            this->mes = 12;
        else
            this->mes = 1;
    }
        
}

void Data::setAno(const int a){
    if(a > 2017 && a < 2021)
        this->ano = a;
    else{
        if (a<2018)
            this->ano = 2018;
        else
            this->ano = 2020;
    }
}

const int Data::getDia() {
    return this->dia;
}

const int Data::getMes(){
    return this->mes;
}

const int Data::getAno(){
    return this->ano;
}

const void Data::imprime() const{
    cout<< dia << " " << mes << " " << ano << "\n";
}

ostream& operator<<(ostream& os, const Data& d){
 //   os << d.dia << " " << d.mes << " " << d.ano << "\n";
        d.imprime();
    return os;
}
istream& operator>>(istream& is, Data& d){
    int di, me, an;
    is >> di >> me >> an;
    d.setDia(di); d.setMes(me);d.setAno(an);
    return is;
}

const int Data::compData(const Data& data2){
    int resultado = 0;
    if(this->ano > data2.ano)
        resultado = 1;
    else{
        if(this->ano < data2.ano)
            resultado = -1;
        else{
            if(this->mes > data2.mes)
                resultado = 1;
            else{
                if(this->mes < data2.mes)
                    resultado = -1;
                else{
                    if(this->dia > data2.dia)
                        resultado = 1;
                    else
                        resultado = -1;
                }
            }
        }
    }
}









