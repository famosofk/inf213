#include <iostream>
#include <string>
#include "MyVec.h"
using namespace std;


class ArvoreExpressao {
public:
	void imprimeArrays() const;

	void leArvore();
	void imprimeExpressao() const;
	int avaliaValor() const;
	int altura() const;
	int nivelMaisNodos() const;

	string percorre (int) const;
	int avalia (int) const;
	int calculaAlt (int) const;
	void nodosPorNivel (int [], int, int) const;

private:
	//Nao adicione nenhum membro de dados na sua classe!!!!
	//Funcoes auxiliares podem ser adicionadas se necessario.

	MyVec<int> filhoEsquerdo;
	MyVec<int> filhoDireito;
	MyVec<char> operador;
};

void ArvoreExpressao::imprimeArrays() const {
	for(int i=0;i<filhoEsquerdo.size();i++) cout << i << " "; cout << "\n";
	for(int i=0;i<filhoEsquerdo.size();i++) cout << filhoEsquerdo[i] << " "; cout << "\n";
	for(int i=0;i<filhoDireito.size();i++) cout << filhoDireito[i] << " "; cout << "\n";
	for(int i=0;i<operador.size();i++) cout << operador[i] << " "; cout << "\n";
}

/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
//sua implementacao:


void ArvoreExpressao::leArvore() {
	int numNodes; cin >> numNodes;

	filhoEsquerdo.resize(numNodes);
	filhoDireito.resize(numNodes);
	operador.resize(numNodes);

	for (int i=0; i<numNodes; i++) {
		int node, leftNode, rightNode; 
		cin >> node >> leftNode >> rightNode;

		filhoEsquerdo[node] = leftNode;
		filhoDireito[node] = rightNode;

		char content; cin >> content;
		operador[node] = content;
	}
}

string ArvoreExpressao::percorre (int node) const {
	string result = "";

	//Caso não tenha filhos, concateno no result o valor de operator. (da expressão)
	if (filhoEsquerdo[node] == -1 && filhoDireito[node] == -1)
		return result += operador[node];

	//Caso tenha filhos, chamo a função recursivamente adicionando o valor do operator entre eles e os parenteses, olhando pra cada filho
	result += '(' + percorre(filhoEsquerdo[node]) + operador[node] + percorre(filhoDireito[node]) + ')';

	return result;
}

void ArvoreExpressao::imprimeExpressao() const {
	if (operador.size() == 1) {
		cout << operador[0];
		return;
	}

	string result = percorre(filhoEsquerdo[0]) + operador[0] + percorre(filhoDireito[0]);

	cout << result;
}

int ArvoreExpressao::avalia (int node) const {
	// Mesmo conceito da função passada, porém aqui iremos trabalhar com números. Com temos vetor de char
	//os números serão de 0 a 9. Sendo assim, caso não tenha filhos, eu retorno o char como int		
	if (filhoEsquerdo[node] == -1 && filhoDireito[node] == -1)
		return int(operador[node]) - 48; 

	switch (operador[node]) {
		case '+':
			return avalia(filhoEsquerdo[node]) + avalia(filhoDireito[node]);
		
		case '-':
			return avalia(filhoEsquerdo[node]) - avalia(filhoDireito[node]);
		
		case '*':
			return avalia(filhoEsquerdo[node]) * avalia(filhoDireito[node]);
	}
}

int ArvoreExpressao::avaliaValor() const {
	return avalia(0);
}

int ArvoreExpressao::calculaAlt (int node) const {
	//basicamente ele se o nodo tem filhos, caso ele tenha, retorna 1 + a chamada pra calcular os filhos dos filhos.
	if (filhoEsquerdo[node] == -1 && filhoDireito[node] == -1)
		return 0;
		
	return 1 + std::max(calculaAlt(filhoEsquerdo[node]), calculaAlt(filhoDireito[node]));
} 

int ArvoreExpressao::altura() const {
	return calculaAlt(0);
}

void ArvoreExpressao::nodosPorNivel (int nodesPerLevel [], int currentLevel, int node) const {
	//basicamente temos um vetor com n possições. Chamamos essa função pra cada nodo examinando seus filhos
	//ou seja, cada nodo chama a função até 2 vezes (supondo que tenha dois filhos), e aí cada filho aumenta
	// em um a posição do vetor correspondente ao nível em que se encontra.
	nodesPerLevel[currentLevel]++;
	
	if (filhoEsquerdo[node] == -1 && filhoDireito[node] == -1)
		return;
	
	nodosPorNivel(nodesPerLevel, currentLevel+1, filhoEsquerdo[node]);
	nodosPorNivel(nodesPerLevel, currentLevel+1, filhoDireito[node]);
}


int ArvoreExpressao::nivelMaisNodos() const {
	//depois de aplicar o que foi comentado acima, percorremos o vetor e retornamos o index que contem
	//o maior número de filhos.
	if (operador.size() == 1) return 1;

	int numLevels = calculaAlt(0);
	int nodesPerLevel[1 + numLevels] = { 0 };

	nodosPorNivel(nodesPerLevel, 0, 0);

	int mostNodes = 0, idx; 
	for (int i=0; i<numLevels+1; i++)
		if (nodesPerLevel[i] > mostNodes) {
			mostNodes = nodesPerLevel[i]; idx = i;
		}
		
	return idx+1;
}




/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/

//Nao modifique aqui
//OBS: cada arquivo de teste começa com a descricao de uma arvore.
//A seguir, ha um numero indicando qual etapa sera testada...
int main() {
	ArvoreExpressao a;
	a.leArvore();

	int etapa;
	cin >> etapa; 
	switch(etapa) {
		case 1:
			cout << "Etapa 1:" << endl;
			a.imprimeArrays();
			break;
		case 2:
			cout << "Etapa 2:" << endl;
			a.imprimeExpressao();
			cout << endl;
			break;
		case 4:
			cout << "Etapa 4:" << endl;
			cout << a.avaliaValor() << endl;
			break;
		case 5:
			cout << "Etapa 5:" << endl;
			cout << a.altura() << endl;
			cout << a.nivelMaisNodos() << endl;
			break;
		default:
			cout << "Erro! Etapa invalida" << endl;
			break;
	}

}