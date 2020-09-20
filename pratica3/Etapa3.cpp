#include <iostream>
#include "FigBase.h"
#include "Retangulo.h"
#include "Circulo.h"
#include "Segmento.h"
#include <typeinfo>
using std::cin;
using std::cout;
using std::endl;

int main(){
    FigBase* array[5];
    Circulo c1 = Circulo();
    Circulo c2 = Circulo();
    Retangulo r1 = Retangulo();
    Segmento s1 = Segmento();
    Segmento s2 = Segmento();
    array[0] = &c1; array[1] = &c2; array[2] = &r1; array[3] = &s1; array[4] = &s2;
    for(int i=0; i < 5; i++)
        cin >> *(array[i]);
    for(int i=0; i < 5; i++)
        cout << *(array[i]);
    for(int i=0; i< 5; i++)
        if(typeid(*array[i]).name() == typeid(Circulo).name()) {
            Circulo* derivedPointer = dynamic_cast < Circulo *>(array[i]);
            if(derivedPointer != 0){
                derivedPointer->setRaio(derivedPointer->getRaio()*2);
                derivedPointer->imprime();
                }
        }
    return 0;
}
