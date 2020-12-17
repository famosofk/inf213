#include<iostream>

void imprimeMatriz(int index, float matriz[]);
void calculaInversa(float matriz[]);

int main() {
    float matriz[4];
    for(int i=0; i< 4; i++)
        std::cin>>matriz[i];
    calculaInversa(matriz);
}

void calculaInversa(float matriz[]){
    float det = matriz[0]*matriz[3] - matriz[1]*matriz[2];
    float factor = 1/det;
    std::swap(matriz[0], matriz[3]);
    matriz[1] *=-1;
    matriz[2] *=-1;
    for(int i=0; i<4; i++)
        matriz[i] *= factor;
    imprimeMatriz(0, matriz);
}

void imprimeMatriz(int index, float matriz[]){
    if(index == 0)
        std::cout << "( ";
    if (index == 2)
        std::cout << "\n  ";
    std::cout << matriz[index] << " ";
    if(index == 3) {
        std::cout << ")";
        return;
    }
    imprimeMatriz(index+1, matriz);
}