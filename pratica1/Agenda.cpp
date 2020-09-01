#include "Agenda.h"

using namespace std;

ItemAgenda::ItemAgenda(){}
ItemAgenda::ItemAgenda(const string& des, const Data& dat, const Horario& hor){
    setData(dat);
    setHorario(hor);
    setDesc(des);
}
ItemAgenda::ItemAgenda(const ItemAgenda& it){
    setData(it.data);
    setDesc(it.descricao);
    setHorario(it.horario);
}
ItemAgenda::~ItemAgenda(){}

void ItemAgenda::setData(const Data& dat){
    data = dat;
}
void ItemAgenda::setHorario(const Horario& hor){
    horario = hor;
}
void ItemAgenda::setDesc(const string& des){
    descricao = des;
}
