#ifndef CONJUNTO_H
#define CONJUNTO_H
#include<iostream>

using namespace std;

template <class T>
class Conjunto;

template <class T>
ostream &operator<<(ostream &, const Conjunto<T> &);

template <class T>
istream &operator>>(istream &, Conjunto<T> &);

template<typename T>
class Conjunto{
    
    private:
    int tam_array, num_elementos;
    T* elementos;
    T* copyElements(int size, Conjunto<T>& object) const;

    public:

    Conjunto(int = 10);
    Conjunto(Conjunto<T>& original);
    ~Conjunto();
    T getElement(int i);
    bool pertence(T object);
    void insere(T object);
    int numeElementos();
    bool operator==(const Conjunto<T> &other) const;
    
    
};

template<typename T>
Conjunto<T>::Conjunto(int size){
    elementos = new T[size];
    num_elementos = 0;
    this->tam_array = size;
}

template<typename T>
Conjunto<T>::Conjunto(Conjunto<T>& original) {
    tam_array = original.tam_array;
    num_elementos = original.num_elementos;
    elementos = copyElements(tam_array, original);
}

template<typename T>
Conjunto<T>::~Conjunto(){
    delete [] elementos;
}

template<typename T>
T Conjunto<T>::getElement(int i){
    return elementos[i];
}

template<typename T>
bool Conjunto<T>::pertence(T object) {
    for(int i=0; i< elementos; i++) {
        if (this->elementos[i] == object) {
            return true;
        }
    }
    return false;
}

template<typename T>
T* Conjunto<T>::copyElements(int size, Conjunto<T>& object) const{
    T* pointer = new T[size];
    for(int i=0; i < object.num_elementos; i++){
        elementos[i] = object.elementos[i];
    }
    return pointer;   
}

template<typename T>
void Conjunto<T>::insere(T object){
    if(num_elementos +1 > tam_array) {
        elementos = copyElements(tam_array*2, this);
        tam_array *= 2;   
    }
    elementos[num_elementos + 1] = object;
    num_elementos++;
}

template<typename T>
int Conjunto<T>::numeElementos() {
    return num_elementos;
}

template <class T>
bool Conjunto<T>::operator==(const Conjunto<T> &other) const{
	int size = other->num_elementos();
    for(int i=0;i<size;i++)
		if(elementos[i]!=other.v[i]) 
			return false;
	return true;
}
#endif


/*

template <class T>
istream &operator>>(istream &is, Conjunto<T> &conjunto){
    T c;
    
    //enquanto puder ser lido eh interpretado como TRUE
    while(is >> c){
        conjunto.insere(c);
    }
    return is;
}

template<typename T>
bool operator==(const Conjunto<T>& object, const Conjunto<T>& object2) {
    if (object.numeElementos == object2.numeElementos) {
        return false;
    }
    int num = object2.numeElementos();
    for (int i=0; i< num; i++) {
        if (object.getElement[i] != object2.getElement[i]) {
            return false;
        }
    }
    return true;
}


template <typename T>
bool operator==(const Conjunto<T>& object, const Conjunto<T>& object2) {
    if (object.numeElementos == object2.numeElementos) {
        return false;
    }
    int num = object2.numeElementos();
    for (int i=0; i< num; i++) {
        if (object.getElement[i] != object2.getElement[i]) {
            return false;
        }
    }
    return true;
}


template<typename T>
bool operator=(const Conjunto<T>& object) {
    return false;
}

*/