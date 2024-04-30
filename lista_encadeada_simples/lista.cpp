#include <iostream>
using namespace std;

class No {
  public:
   int dado;
   No* prox;

   No() {}
   No(int dado) { this->dado = dado; }
   No(int dado, No* prox) {
      this->dado = dado;
      this->prox = prox;
   }
};

void printEncadeada(No* no) {

   No* tmp = no;

   cout << "[";
   while (tmp != nullptr) {
      cout << tmp->dado;
      tmp = tmp->prox;
      if (tmp != nullptr) cout << ",";
   }
   cout << "]" << endl;
}


int main() {

   No* n1 = new No(1);
   No* n2 = new No();
   No* n3 = new No(3, nullptr);

   //    n1->dado = 1;
   n2->dado = 2;
   //   n3->dado = 3;

   n1->prox = n2;
   n2->prox = n3;
   //    n3->prox = nullptr;

   n3->prox = new No();
   n3->prox->dado = 4;
   n3->prox->prox = nullptr;

   No* organizacaoEncadeada = n1;
   n1 = nullptr;
   n2 = nullptr;
   n3 = nullptr;

   
   printEncadeada(organizacaoEncadeada);
}