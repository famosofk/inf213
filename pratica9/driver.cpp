#include <iostream>
#include <string>

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
//#include "MyStack.h"
#include "MyStack.h"
#include "MyQueue.h"

void etapa1() {
	int readNumber = 6;
	MyQueue<int> queue;
	MyStack<int> stack;
	int value;
	for(int i=0; i<6; i++) {
		cin >> value;
		queue.push(value);
		stack.push(value);
	}

	for(int i=0; i<6; i++) {
		cout << stack.top() << " ";
		stack.pop();	
	}
	cout << endl;

	for(int i=0; i<6; i++) {
		cout << queue.front() << " "; 
		queue.pop();
	}
	cout << endl;


	//RESPOSTA: A diferença se da na função push. Enquanto a queue ordena o vetor normalmente, a stack ordena o vetor de tras para frente, sendo assim, 
	// a ordem delas fica invertida, de tal modo que, a queue imprime na ordem de inserção e a stack na ordem inversa a inserção.
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2() {
	bool valid = true;
	MyStack<char> stack;
	string expression;
	char c;
	getline(cin, expression);
	for(int i=0; i< expression.length(); i++){
		c = expression.at(i);
		switch (c) {
			case '(':
				stack.push(c);
				break;
			case '[':
				stack.push(c);
				break;
			case '{':
				stack.push(c);
				break;
			case ')':
				if(stack.empty() || stack.top()!='(')
					valid = false;
				stack.pop();
				break;
			case ']':
				if(stack.empty() || stack.top()!='[') 
					valid = false;
				stack.pop();
				break;
			case '}':
				if(stack.empty() || stack.top()!='{')
					valid = false;
				stack.pop();
				break;
		}
		if(!valid) break;
	}

	if(valid && stack.empty()) cout << "Consistente" << endl;
	else cout << "Inconsistente" << endl;
	
}

//---------------------------------------

// Na etapa 3 voce deve implementar MyQueue2.h e descomentar os codigos de teste abaixo...


#include "MyQueue2.h"
void etapa3() {
	char operacao;
	MyQueue2<string> q;

	while(cin>> operacao) {
		if(operacao=='p') {
			string st;
			cin >> st;
			q.push(st); //insere um novo elemento na sua fila...
		} else if(operacao=='f') {
			cout << q.front() << "\n";
		} else if(operacao=='P') {
			q.pop();
		} else if(operacao=='e') {
			cout << ((q.empty())?"vazia":"cheia") << "\n";
		} else cout << q.size() << "\n";
	}	
}

//---------------------------------------

// Insira aqui o codigo para a etapa 4....


void etapa4() {
	MyStack<int> s;
	
	int argumentsNumber; cin >> argumentsNumber;
	int count = 0;
	for (int i=0; i<argumentsNumber; i++) {
		int input; cin >> input;
		if (input > count) {
			for (int j=count + 1; j!=input; j++) s.push(j);
			count = input;
			continue;
		}
		if (input == count) {
			cout << "NAO" << endl;
			return;
		} 
		if (input != s.top()) {
			cout << "NAO" << endl;
			return;
		}

		s.pop();  
	}

	cout << "SIM" << endl;
}

//---------------------------------------

	
	int main() {

	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
		case 4:
			cout << "Etapa 4" << endl;
			etapa4();
			break;
	}
}