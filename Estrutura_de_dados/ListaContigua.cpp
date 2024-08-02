
#include <string>
#include <iostream>

class ListaContigua {

  private:
   int* vetor;
   int tam;
   int qtde;

  public:
   ListaContigua(int * vetor,int tam,int qtde){
    this->vetor=new int[tam];
    this->tam=tam;
    this->qtde=0;

   }
   ~ListaContigua();

   // Insere o elemento na última posição
   bool push_back(int e){
    if(qtde<tam){
       vetor[qtde]=e;
       qtde++;  
    }
    else{
      std::cout <<"cannot insert new element, the vetor is full!"<< std::endl;
    }}
   // Insere o elemento na primeira posição
   bool push_front(int e);
   // Insere o elemento na posição pos
   bool insert(int pos, int e);

   // Remove o último elemento
   int pop_back();
   // Remove o primeiro elemento
   int pop_front();
   // Remove o elemento da posição pos e retorna o elemento removido
   int erase(int pos);

   // Retorna o primeiro elemento
   int front();
   // Retorna o último elemento
   int back();
   // Retorna o elemento da posição pos
   int at(int pos);

   // Torna a lista vazia
   void clear();

   // Verifica se o vetor está vazio
   bool empty(){
    return qtde==0;
   }
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