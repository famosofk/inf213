#include <bits/stdc++.h>
#include "MySet.h"
#include "MyVecNewIterator.h"
using namespace std;

int main (int argc, char ** argv) {
    const char * DELIMITERS = " \t\n";
    int wordNumber = 0; 
    string line;
    //Implementação vetor. Leio apenas o char que diferencia os dois pra comparação em vez de colocar 'myvec', 'myset'
    if (argv[1][2] == 'v') {
        //criamos o vetor e damos getline enquanto for necessário, em seguida, usamos o strtok para quebrar a linha
        //percorremos o vetor pra ver se tem a string, se não tiver, damos um pushback. Em ambos os casos, adicionamos
        //o contador de palavras, pois ele é necessário já que o vetor contém apenas a palavra
        MyVec<string> vec;
        while (getline(cin, line)) {
            char * tok = strtok(&line.at(0), DELIMITERS);
            while (tok) {
                string str(tok);
                bool contain = false;
                for (int i=0; i<vec.size(); i++) 
                    if (vec[i] == str) contain = true;
                if (!contain) vec.push_back(str);
                tok = strtok(NULL, DELIMITERS);
                wordNumber++;
            }    
        }
        cout << wordNumber << " " << vec.size() << endl;
        return 0;
    } 
    //implementação set
    if (argv[1][2] == 's') {
        //criamos um set e lemos a linha. Quebramos usando o strtok e damos insert no set. Em ambos os casos usamos
        //um incremento no wordNumber, pois o set não armazena chave e valor, apenas chave.
        MySet<string> set;
        while (getline(cin, line)) {
            char * tok = strtok(&line.at(0), DELIMITERS);
            while (tok) {
                string str(tok);
                set.insert(str);
                tok = strtok(NULL, DELIMITERS);
                wordNumber++;
            }    
        }
        cout << wordNumber << " " << set.size() << endl;
        return 0;
    } 
    return 1;
}