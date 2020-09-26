#ifndef CONJUNTO_H
#define CONJUNTO_H

template<class T>
class Conjunto{
    
    private:
    int tam_array, num_elementos;
    T* elementos;
    T* copyElements(int size, Conjunto& object){
        T* pointer = new T[size];
        for(int i=0; i < object.num_elementos; i++){
            elementos[i] = object.elementos[i];
        }
        return pointer;
    } 

    public:
    Conjunto(int size = 10) {
        elementos = new T[size];
        num_elementos = 0;
        this->tam_array = size;
    }

    Conjunto(Conjunto& original) {
        tam_array = original.tam_array;
        num_elementos = original.num_elementos;
        elementos = copyElements(tam_array, original);
    }

    ~Conjunto(){
        delete [] elementos;
    }
    T getElement(int i){
        return elementos[i];
    }


    bool pertence(T object) {
        for(int i=0; i< elementos; i++) {
            if (this->elementos[i] == object) {
                return true;
            }
        }
        return false;
    }

    void insere(T object){
        if(num_elementos +1 > tam_array) {
            elementos = copyElements(tam_array*2, this);
            tam_array *= 2;   
        }
        elementos[num_elementos + 1] = object;
        num_elementos++;
    }

    int numeElementos() {
        return num_elementos;
    }
    
    friend bool operator==(const Conjunto& object, const Conjunto& object2) {
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
    
    bool operator=(const Conjunto& object) {
        return false;
    }
    



};


#endif