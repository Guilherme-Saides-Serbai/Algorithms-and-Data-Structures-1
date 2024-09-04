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
        return buscaSequencial(elemento,v+1,tam-1);
    }
}


int main() {
    int x = 48, y = 18;
    printf("MDC(%d, %d) = %d\n", x, y, mdc(x, y));
    return 0;
}
