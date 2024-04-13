#include <iostream>
#include <cstring> 
using namespace std;
typedef struct produto {
    int codigo;
    char descricao[12];
    float preco;
} Produto;

int main1() {
    Produto prod = {1, "teclado", 98.50};
    Produto *p = &prod;
    int *pi = &prod.codigo;
    char *pc = prod.descricao;
    float *pf = &prod.preco;

    prod.codigo = 2;
    strcpy(prod.descricao, "mouse"); 
    prod.preco = 100.00;
    prod={2,"mouse",100.00};

    cout << "Codigo: " << prod.codigo << endl;
    cout << "Descricao: " << prod.descricao << endl;
    cout << "Preco: " << prod.preco << endl;

    return 0;
}

typedef struct produto{
int codigo;
char descricao[12]; 
float preco;
} Produto;

int main2(){
Produto prodA = {1, "Teclado", 98.50};
Produto prodB = {2, "Mouse", 65.00};
Produto prodC = {3, "Webcam", 130.00};
Produto prodG = {2004,"headphone",340.00};
Produto* vet[4];
vet[0] = &prodA;
vet[1] = &prodB;
vet[2] = &prodB;
vet[3] = &prodC;
vet[3]->codigo=100;
strcpy(vet[1]->descricao,"mouse sem fio");
vet[3]=&prodG;
}