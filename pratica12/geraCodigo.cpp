#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

#include "MyMap.h"

int main () {
    //Leio a linha e em seguida crio um token em ponteiro pra char. Enquanto ele não for null, construo uma string com o token e verifico
    //se está no map. Caso não esteja, atribuo um valor pra palavra.
    const char * DELIMITERS = " \t\n";
    string line; 
    MyMap<string, int> map;
    int wordNumber = 0;
    while (getline(cin, line)) { //
        char * token = strtok(&line.at(0), DELIMITERS); // crio um token em ponteiro pra char
        while (token) { 
            string str(token); 
            if (map.find(str) == NULL) 
                map[str] = wordNumber++;
            cout << str << " " << map[str] << endl;
            token = strtok(NULL, DELIMITERS);
        }    
    }

    return 0;
}
    