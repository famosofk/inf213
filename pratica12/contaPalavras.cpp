#include <bits/stdc++.h>
#include "MySet.h"
#include "MyVecNewIterator.h"
using namespace std;

int main (int argc, char ** argv) {
    const char * DELIMITERS = " \t\n";
    int wordNumber = 0; 
    string line;
    if (argv[1][2] == 'v') {
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
    if (argv[1][2] == 's') {
        MySet<string> set;
        while (getline(cin, line)) {
            char * tok = strtok(&line.at(0), DELIMITERS);
            while (tok) {
                std::string str(tok);
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