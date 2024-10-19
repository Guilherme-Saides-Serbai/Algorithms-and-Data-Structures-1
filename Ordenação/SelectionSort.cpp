#include <algorithm>
#include <iostream>
#include <cstdlib>

int* vetor_aleatorio(int n, int max, int seed){
    int *v = new int[n];
    srand(seed);
    for(int i = 0; i < n-1; i++){
        v[i] = rand() % max;
    }
    return v;
}

int pos_maior(int*v, int ini, int fim){
    int maior = ini;
    for(int i = ini+1; i <= fim; i++){
        if(v[i] > v[maior]){
            maior = i;
        }
    }
    return maior;
}

void SelectionSort(int *v, int n){
    for(int i = n-1; i > 0; i--){
        int p = pos_maior(v, 0, i);
        std::swap(v[p], v[i]);
    }
}

int main(){
    int n = 100;
    int *v = vetor_aleatorio(n, n*100, 99);

    SelectionSort(v, n);
    for(int i = 0; i < n; i++){
        std::cout << v[i] << ", ";
    }
    std::cout << "\n";

    return 0;
}