#ifndef DATA_H
#define DATA_H
#include<iostream>

using namespace std;

class Data{

    private:
    int dia, mes, ano;

    public:
    Data();
    Data(const int d, const int m, const int a);
    ~Data();
    void setDia(const int d);
    void setMes(const int m);
    void setAno(const int a);
    const int getDia();
    const int getMes();
    const int getAno();
    const int compData(const Data& data2);
    const int difDias(const Data& data2);
    const void imprime() const;
    friend ostream& operator<<(ostream& os, const Data& d);
    friend istream& operator>>(istream& is, Data& d);


    
    
};

#endif