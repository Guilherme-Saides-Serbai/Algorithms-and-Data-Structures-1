#include <iostream>
int fatorial(int n) {
    if (n == 0) {
        return 1; // Caso base
    } else {
        return n * fatorial(n - 1); // Chamada recursiva
    }
}


int main() {
    int numero;
    std::cout << "Digite um número: ";
    std::cin >> numero;

    if (numero < 0) {
        std::cout << "Fatorial não definido para números negativos." << std::endl;
    } else {
        std::cout << "Fatorial de " << numero << " é " << fatorial(numero) << std::endl;
    }

    return 0;
}  