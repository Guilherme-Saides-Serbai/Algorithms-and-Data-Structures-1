#include <string>
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

class ListaEncadeada {

  private:
   No* primeiro;
   No* ultimo;

   int size;

  public:
   ListaEncadeada();
   ~ListaEncadeada();

   // Insere o elemento e na última posição
   bool push_back(int e){
        No * novo_no=new No(e);
        if(novo_no==NULL) return 0;
        if(primeiro==nullptr){
        primeiro->prox=novo_no;
        primeiro=novo_no;
        }
        else{
        ultimo->prox=novo_no;
        ultimo=novo_no;
        }
        size++;
        return 1;
   }
   // Insere o elemento e na primeira posição
   bool push_front(int e){
        No * novo_no=new No(e);
        if(novo_no==NULL)return 0;   
        if(primeiro==nullptr){
        primeiro->prox=novo_no;
        primeiro=novo_no;
        }
        else{
         return 0;
        }
        size++;

        }
   // Insere o elemento e na posição pos
   bool insert(int pos, int e){
   }

   // Remove o último elemento
   int pop_back(){
       delete ultimo->prox;
       size--;
   }
   // Remove o primeiro elemento
   int pop_front(){
       delete primeiro->prox;
       size--;
   }
   // Remove o elemento da posição pos e retorna o elemento removido
   int erase(int pos){
         if(pos==1){
            return primeiro->dado; 
            delete primeiro->prox;
         }

         else{
            return ultimo->dado;
            delete ultimo->prox;
         }
   }

   // Retorna o primeiro elemento
   int front(){
    return primeiro->dado;
   }
   // Retorna o último elemento
   int back(){
    return ultimo->dado;
   }
   // Retorna o elemento da posição pos
   int at(int pos){
   }

   // Torna a lista vazia
   void clear(){
    delete primeiro->prox;
    primeiro=nullptr;
    delete ultimo->prox;
    ultimo=nullptr;
   }
   

   // Verifica se o vetor está vazio
   bool empty();
   // Devolve a quantidade de elementos
   int size();
   // Substitui o elemento da posição pos pelo elemento e
   bool replace(int pos, int e);

   // Imprime todos os elementos no formato [1,2,3]
   void print();

  private:
   // Dobrar a capacidade quando não houver mais espaço
   // Reduzir a capacidade pela metade quando for inferior a 25% de ocupação
   void gerenciaCapacidade();
};