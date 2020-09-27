#include "Conjunto2.h"
#include<iostream>

using namespace std;


int main(){

    int n = 40000;
    Conjunto<int> a1(n);
    Conjunto<int> b1(n);
    Conjunto<int> c1(2*n); 
    for (int i=1; i<=n; i++){
        a1.insere(i);
        b1.insere(i);
    }
    c1 = a1 + b1;
    cout << c1.pertence(10) << endl;    

}