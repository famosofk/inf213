#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

#include "MyMap.h"

int main () {
    const char * DELIMITERS = " \t\n";
    string line; 
    MyMap<string, int> map;
    int wordNumber = 0;
    while (getline(cin, line)) {
        char * token = strtok(&line.at(0), DELIMITERS);
        while (token) {
            string str(token);
            if (map.find(str) == NULL) map[str] = wordNumber++;
            cout << str << " " << map[str] << endl;
            token = strtok(NULL, DELIMITERS);
        }    
    }

    return 0;
}
    