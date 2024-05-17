#include <iostream>
using namespace std;

class No{
public:
    int dado;
    No * pointer_to_prox;
public:
    No(int _dado, No * _pointer_to_prox){
        dado = _dado;
        pointer_to_prox = _pointer_to_prox;
    }
    ~No(){
        cout << "o objeto foi destruido !!!" << endl;
    }
    static void print_encadeada(No * no){ // Método estático para chamar sem uma instância da classe
        No * temp = no;
        cout << "[";
        while(temp != nullptr){
            cout << temp->dado;
            temp = temp->pointer_to_prox;
            if(temp != nullptr){
                cout << ",";
            }
        }
        cout << "]";
    }
};

int main(){
    No * n1 = new No(12, nullptr);
    No * n2 = new No(14, nullptr);
    No * n3 = new No(25, nullptr);
    n1->pointer_to_prox = n2;
    n2->pointer_to_prox = n3;
    No::print_encadeada(n1);// Chamar o método usando o escopo da classe No
    printf("\n");
    delete n1; // Lembre-se de liberar a memória alocada
    delete n2;
    delete n3;
    return 0;
}
