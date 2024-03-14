#include <iostream>
#include <time.h>
using namespace std;

void executeCarga(int carga){
    for(int i = 0; i <carga; i++);
}

void ordem_n(int n, int carga){  //carga = quantidade intruções
    for(int i = 0; i <n; i++){  // carga*n
        executeCarga(carga);
    }
}

void ordem_n2(int n, int carga){  // n^n
    for(int i = 0; i <n; i++){
        for(int j = 0; j <n; j++){
        executeCarga(carga);
        }           
    }
}

void ordem_logn(int n, int carga){  // n^n
    while(n > 0){
        executeCarga(carga);
        n = n/ 2;
    }
}

void ordem_nlogn(int n, int carga){  // n^n
    for(int i = 0; i <n; i++){
        int j = n;
        while(j > 0){
            executeCarga(carga);
            j = j/2;
        }           
    }
}


int main(){
    int n = 1000;
    int carga = 10;
    clock_t inicio, fim;
    inicio = clock();

    ordem_n2(n, carga);
    fim = clock();

    float tempo = (float)(fim - inicio)/ CLOCKS_PER_SEC;}