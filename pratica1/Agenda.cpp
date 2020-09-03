#include "Agenda.h"
#include<iostream>
#include<string>
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

Data& ItemAgenda::getData(){
    return data;
}
string& ItemAgenda::getDesc(){
    return descricao;
}
Horario& ItemAgenda::getHorario(){
    return horario;
}

ostream& operator<<(ostream& os, ItemAgenda& it){
    it.getData().imprime();
    it.getHorario().imprime(); 
    os << " " << it.getDesc() << "\n";
    return os;
}


Agenda::Agenda(){}
void Agenda::inserirItem(const ItemAgenda& it){
    compromissos[contador] = it;
    contador++;

}

const void Agenda::compromissosData(const Data& dat) const{
    for(int i=0; i<contador;i++){
        ItemAgenda item = compromissos[i];
        if(item.getData().difDias(dat) == 0)
            cout << item;
    }

}