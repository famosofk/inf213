#ifndef AGENDA_H
#define AGENDA_H
#include "Data.h"
#include "Horario.h"
#include<string>
using namespace std;

class ItemAgenda{

    private:
    string descricao;
    Data data;
    Horario horario;

    public:
    ItemAgenda();
    ItemAgenda(const string& des, const Data& dat, const Horario& hor);
    ItemAgenda(const ItemAgenda& it);
    ~ItemAgenda();
    void setDesc(const string& des);
    void setData(const Data& dat);
    void setHorario(const Horario& hor);
    const Data& getData() const;
    const string& getDesc() const;
    const Horario& getHorario() const;
    friend ostream& operator<<(ostream& os, const ItemAgenda& it);
   

};

class Agenda{
    private:
    ItemAgenda compromissos[1000];
    int contador;

    public:
    Agenda();
    void inserirItem(const ItemAgenda& it);
    void const compromissosData(const Data& dat)const;
    
};

#endif