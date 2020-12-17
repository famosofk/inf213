#ifndef CONJUNTO1_H
#define CONJUNTO1_H
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
    int tam_array = 0; 
    int num_elementos = 0;
    T* elementos;

    public:

    Conjunto(int = 10);
    Conjunto(Conjunto<T>& original);
    ~Conjunto();
    T getElement(int i) const;
    bool pertence(T object) const;
    bool insere(T object);
    int numelementos() const;
    bool operator==(const Conjunto<T> &other) const;
    Conjunto<T>& operator=(const Conjunto<T> &other);
    
    
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
    elementos = new T[num_elementos];
    for (int i=0; i<num_elementos; i++)
        elementos[i] = original.elementos[i];
}

template<typename T>
Conjunto<T>::~Conjunto(){
    delete [] elementos;
}

template<typename T>
T Conjunto<T>::getElement(int i) const{
    return elementos[i];
}

template<typename T>
bool Conjunto<T>::pertence(T object) const {
    for(int i=0; i< numelementos(); i++) {
        if (this->elementos[i] == object) {
            return true;
        }
    }
    return false;
}

template<typename T>
bool Conjunto<T>::insere(T object){
    if(num_elementos +1 > tam_array || pertence(object)) 
        return false;
    elementos[num_elementos] = object;
    num_elementos++;
    return true;
}

template<typename T>
int Conjunto<T>::numelementos() const {
    return num_elementos;
}

template <class T>
bool Conjunto<T>::operator==(const Conjunto<T> &other) const{
	int size = other.numelementos();
    if(num_elementos != size)
        return false;
    for(int i=0;i<size;i++)
		if(!other.pertence(elementos[i])) 
			return false;
	return true;
}


template<typename T>
Conjunto<T>& Conjunto<T>::operator=(const Conjunto<T> &other) {
    if(&other == this) { return *this; }
    delete [] elementos;
    this->num_elementos = other.num_elementos;
    this->tam_array = other.tam_array;
    this->elementos = new T[other.tam_array];
    for( int i=0; i< other.num_elementos; i++)
        this->elementos[i] = other.elementos[i];
    return *this;
}

template<typename T>
istream &operator>>(istream &is, Conjunto<T> &conjunto){
    T c;
    while(is >> c){
        conjunto.insere(c);
    }
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, const Conjunto<T> &object){
    os << "{" << object.getElement(0);
    for(int i=1; i<object.numelementos(); i++)
        os << "," << object.getElement(i);
    os << "}";    
    return os;
}

#endif