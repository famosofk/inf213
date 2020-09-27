#ifndef CONJUNTO2_H
#define CONJUNTO2_H
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
    T& operator[](int i) {return elementos[i];}
    const T& operator[](int i) const{return elementos[i];}
    
    Conjunto<T> operator+(const Conjunto<T> &other){
        Conjunto<T> a(this->numelementos() + other.numelementos());
        for(int i = 0; i < this->numelementos(); i++)
            a.insere(this->elementos[i]);
        for(int i = 0; i < other.num_elementos; i++)
            a.insere(other.elementos[i]);
        return a;
    }

    Conjunto<T> operator*(const Conjunto<T> &other) {
        Conjunto<T> a;
        delete [] a.elementos;
        a.num_elementos = this->num_elementos > other.num_elementos ? other.num_elementos : this->num_elementos; 
        a.elementos = new T[a.num_elementos];
        if (this->num_elementos > other.num_elementos){
            for(int i=0; i< other.num_elementos; i++) {
                if(this->pertence(other.getElement(i))){
                    a.insere(other.getElement(i));
                  }
              }      
        }else{
            for(int i=0; i< this->num_elementos; i++) {
                if(other.pertence(this->getElement(i))){
                    a.insere(other.getElement(i));
                }
            }
        }
        return a;
    }

    Conjunto<T> operator-(const Conjunto<T> &other) {
        Conjunto<T> a;
        a.num_elementos = 0;
        delete [] a.elementos;
        a.tam_array = this->tam_array;
        a.elementos = new T[a.tam_array];
        for(int i=0; i<this->numelementos();i++)
            if(!other.pertence(this->getElement(i)))
                a.insere(this->getElement(i));
        return a;
    }

    
    
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
    elementos = new T[original.tam_array];
    for(int i=0; i<original.num_elementos; i++) {
        elementos[i] = original.elementos[i];
    }
}

template<typename T>
Conjunto<T>::~Conjunto(){
    delete [] elementos;
}

template<typename T>
T Conjunto<T>::getElement(int i) const { 
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
bool Conjunto<T>::insere(T object) {
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
bool Conjunto<T>::operator==(const Conjunto<T> &other) const {
	int size = other.numelementos();
    if(num_elementos != size)
        return false;
    for(int i=0;i<size;i++)
		if(!other.pertence(elementos[i])) 
			return false;
	return true;
}

template <class T>
Conjunto<T>& Conjunto<T>::operator=(const Conjunto<T>& other){
    if(this == &other) {return *this;}
    delete []this->elementos;
    this->tam_array = other.num_elementos;
    this->num_elementos = other.numelementos();
    this->elementos = new T[this->numelementos()];
    for(int i = 0; i < this->numelementos(); i++){
        this->elementos[i] = other.elementos[i];
    }
    return *this;
}

template<typename T>
istream &operator>>(istream &is, Conjunto<T> &conjunto) {
    T c;
    while(is >> c){
        conjunto.insere(c);
    }
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, const Conjunto<T> &object) { 
    if(object.numelementos() == 0){
        os << "{}";
    }
    else{
        os << "{" << object.getElement(0);
        for(int i=1; i<object.numelementos(); i++)
        os << "," << object.getElement(i);
        os << "}";	
    }    
    return os;
}

#endif