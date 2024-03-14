#include <stdio.h>
#include <stdlib.h>

int main() {
    int valor = 30;
    int *pointer = NULL;
    pointer = &valor;

    printf("%d", *pointer);
    return 0;
}
