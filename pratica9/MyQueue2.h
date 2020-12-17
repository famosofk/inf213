#ifndef MyQueue2_H__
#define MyQueue2_H__

#include "MyStack.h"
#include <iostream>
using namespace std;

template<class T>
class MyQueue2 {
public:
	MyQueue2() {} 

	void push(const T&el);
	const T front() ; //Nesta implementacao vamos permitir retorno por copia...
	void pop() ;
	bool empty() ;
	int size() ;

private:
	void transferElementsFrom1To2IfNecessary();
	MyStack<T> pilha1; //nao mude nada nessa interface!!!
	MyStack<T> pilha2; //nao mude nada nessa interface!!!
};

template<typename T>
void MyQueue2<T>::push(const T& el){
	pilha1.push(el); 
}
template<typename T>
void MyQueue2<T>::transferElementsFrom1To2IfNecessary(){
	if(pilha2.empty()) {
		 while (!pilha1.empty()) { 
            pilha2.push(pilha1.top()); 
            pilha1.pop(); 
        } 
	}
}

template<typename T>
void MyQueue2<T>::pop(){
	if (pilha1.empty() && pilha2.empty()) 
		return;
  	transferElementsFrom1To2IfNecessary();
    pilha2.pop();  
    }

template<typename T>
const T MyQueue2<T>::front(){
	transferElementsFrom1To2IfNecessary();
	return pilha2.top();
}

template<typename T>
bool MyQueue2<T>::empty(){
	return pilha1.empty();
}

template<typename T>
int MyQueue2<T>::size(){
	return pilha1.size();
}

#endif