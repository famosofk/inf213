#include<iostream>
#include "Data.h"
#include "Horario.h"
#include "Agenda.h"
//#include "Data.cpp"

using namespace std;

int main(){

    Data d = Data(1,1,2019);
    cout << d;
    Horario h = Horario(24,70,70);
    cout << h;

    return 0;
}
