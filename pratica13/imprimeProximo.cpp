#include <iostream>
#include "MySet.h"
using namespace std;

int main () {

    //primeiro lemos uma ordem para o programa e depois um número relativo a ela. Caso seja c, inserimos o número em nossa base de dados.
    //caso seja qualquer outra coisa, embora estejamos esperando apenas 'S', realizamos uma search no banco. Basicamente, localizamos um iterador para número e verificamos o de cima e o debaixo.
    // Caso ele seja o último, já retornamos falso porque não terá sucesso para ele, caso contrário incrementamos o danado. Como nosso incremento vai para a direita e depois pra esquerda (buscando o menor maior)
    //ou, caso não haja direita, ele vai pro parent enquanto estivermos a direita do parent. No momento que estivermos a esquerda, ele irá retornar o parent como sucessor
    char order; int number;
    MySet<int> dataBase;
    
    while (cin >> order >> number) {
        if (order == 'C') dataBase.insert(number);

        else {
            MySet<int>::iterator it = dataBase.find(number);
            
            if (it == nullptr)
                cout << "FALHA" << endl;
            
            else {
                if (++it == dataBase.end())
                    cout << "FALHA" << endl;
                    
                else cout << *it << endl;
            }
        }
    }

    return 0;
}