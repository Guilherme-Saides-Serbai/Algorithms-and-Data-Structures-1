#include <stdio.h>

int mdc(int x, int y) {
    if (y <= x && x % y == 0) {
        return y;
    } else if (x < y) {
        return mdc(y, x);
    } else {
        return mdc(y, x % y);
    }
}

bool buscaSequencial(int elemento, int* v, int tam){
    if(tam==0){
        return false;
    }
    if(v[0]==elemento){
        return true;
    }
    else{
        return buscaSequencial(elemento,v,tam-1);
    }
}
bool buscaBinariaRecursiva(int elemento, int* v, int inicio, int fim) {
    if (inicio > fim) {
        return false;
    }
    int meio = inicio + (fim - inicio) / 2;
    if (v[meio] == elemento) {
        return true;
    }
    if (elemento < v[meio]) {
        return buscaBinariaRecursiva(elemento, v, inicio, meio - 1);
    } else {
        return buscaBinariaRecursiva(elemento, v, meio + 1, fim);
    }
}
