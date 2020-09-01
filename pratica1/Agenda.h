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
    const string& getDesc() const;
    const Data& getData() const;
    const Horario& getHorario()const;

};

class Agenda{
    private:
    ItemAgenda compromissos[1000];
    int contador;

    public:
    Agenda();
    void const inserirItem(const ItemAgenda& it);
    void const compromissosData(const Data& dat);
};

#endif