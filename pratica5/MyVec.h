/*
TAD MyVec
- Representa uma lista implementada por contiguidade
- Interface similar a da classe Vector do STL
- Criado por Salles Magalhaes em 19/02/2018

*/

#ifndef MyVec_H__
#define MyVec_H__

#include <iostream>
#include <string>
#include <ostream>


//Excessao usada pela classe MyVec
class MyVecException {
private:
	std::string msg;
public:
	MyVecException (const std::string &msg0): msg(msg0) { }
	const std::string & what() const { return msg; }
};


template<class T>
class MyVec {
public:
	template<class T2>
	friend std::ostream& operator<<(std::ostream &, const MyVec<T2> &);

	//construtores/destrutures/etc
	MyVec();
	MyVec(int n, const T&init=T());

	//destrutor
	~MyVec() { destroy(); };

	//Construtor de copia
	MyVec(const MyVec &);
	MyVec & operator=(const MyVec &);

	//funcoes de acesso
	T &operator[](int pos) {return data[pos];}
	const T &operator[](int pos) const {return data[pos];}
	void push_back(const T&);
	void resize(int newSize);
	void insert(const T&,int pos);
	void clear();
	int eraseMatchingElements(const T& elem);
	void sortedInsert(const T& elem);

	void empty() const {return size() == 0;};
	int size() const {return dataSize;};


private:
	T* data; 
	int dataSize; 
	int dataCapacity; 

	void create();
	void destroy();
	void resizeCapacity(int newCapacity);
};
//Ao analisarmos a função, vemos que o pior caso está no for. Como ele é O(n) e o inserte também
//temos a complexidade de O(n^2)
template<typename T>
void MyVec<T>::sortedInsert(const T& elem) {
	if (this->dataSize == 0) {
		this->insert(elem, 0);
		return;
	}

	else if (elem > this->data[dataSize-1]) {
		this->insert(elem, dataSize);
		return;
	}

	for (int i=0; i<this->dataSize; i++)
		if (this->data[i] > elem) {
			this->insert(elem, i++);
			break;
		}
}

//Essa função é O(3n) pois é composta por 3 O(n), logo O(n).
template<typename T>
int MyVec<T>::eraseMatchingElements(const T& elem) {
	int numElem = 0;
	T a = T();
	for(int i=0; i<this->dataSize; i++) 
		if (this->data[i] == elem) {
			this->data[i] = a;
			numElem++;
		}
	for (int i=0; i<this->dataSize-1; i++)
		if (this->data[i] == a) {
			data[i] = data[i+1];
			data[i+1] = a;
		}
	if(this->data[dataSize-1] != a){
		for(int i=0; i<this->dataSize-numElem; i++){
			if(this->data[i] == a)
			this->data[i] = this->data[dataSize-1];
		}
	}
	this->dataSize -= numElem;
	return numElem;
}

template<class T>
void MyVec<T>::push_back(const T&elem) {
	this->insert(elem, this->dataSize);
}

template<class T>
void MyVec<T>::resize(int newSize) {
	if(newSize >= dataCapacity) { 
		resizeCapacity(newSize); 
	}
	for(int i=dataSize;i<newSize;i++) { 
		data[i] = T();
	}
	dataSize = newSize;
}

template<class T>
void MyVec<T>::insert(const T&elem,int pos) {
	if(pos > dataSize || pos < 0) {
		throw MyVecException("Erro na funcao insert: posicao invalida");
	}

	if(dataSize == dataCapacity) { 
		if(dataCapacity ==0) //Exercicio: Por que e' preciso testar isso? Caso não tenha sido inicializado, apenas usado o create.
			resizeCapacity(1);
		else
			resizeCapacity(dataCapacity*2);
	}	

	for(int i=dataSize;i>pos;i--)
		data[i] = data[i-1];
	data[pos] = elem;
	dataSize++;
}


template<class T>
void MyVec<T>::clear() {
	destroy();
	create();
}


template<class T>
void MyVec<T>::resizeCapacity(int newCapacity) {
	if (newCapacity < this->dataCapacity) 
		return;
	T* temp = new T[newCapacity];
	for(int i=0; i< this->dataSize; i++)
		temp[i] = this->data[i];
	this->dataCapacity = newCapacity;
	delete[] this->data;
	this->data = temp;
}

template<class T>
void MyVec<T>::destroy() {
	delete []data;
	dataSize = dataCapacity = 0;
}

template<class T>
void MyVec<T>::create() {
	data = NULL;
	dataSize = dataCapacity = 0;
}

template<class T>
MyVec<T>::MyVec() {
	create();
}

template<class T>
MyVec<T>::MyVec(int n, const T&init) {
	this->create();
	dataCapacity = n;
	data = new T[n];
	for ( int i=0; i<n; i++)
		this->insert(init, dataSize);
}


//Construtor de copia
template<class T>
MyVec<T>::MyVec(const MyVec &other) {
this->data = NULL;
	*this = other;

}


template<class T>
MyVec<T> & MyVec<T>::operator=(const MyVec &other) {
	if(this==&other) return *this; 
	destroy(); //Exercicio: por que precisamos disso? Desalocar.
	dataCapacity = other.dataCapacity;
	dataSize = other.dataSize;
	//data = other.data; //por que nao podemos fazer isso? Não seria uma cópia, apontaria pro mesmo.
	data = new T[dataCapacity];
	for(int i=0;i<dataSize;i++) data[i] = other.data[i];
	return *this;
}

template<class T2>
std::ostream& operator<<(std::ostream &out, const MyVec<T2> &v) {
	out << "Size: " << v.size() << "\n";
	out << "Capacity: " << v.dataCapacity << "\n";
	for(int i=0;i<v.size();i++) out << v.data[i] << " ";
	out << "\n";
	return out;
}

#endif