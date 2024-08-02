
#include <string>

class No {
  public:
   No* ant;
   int dado;
   No* prox;

   No(No* ant, int dado, No* prox) {
      this->ant = ant;
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
   ListaEncadeada(){
      this->primeiro = nullptr;
      this->ultimo = nullptr;
      this->size = 0;
   }
   ~ListaEncadeada();

   // Insere o elemento e na última posição
   bool push_back(int e){
      No* novo = new No(nullptr, e, nullptr);
      
      if (this->empty()){
         this->primeiro = novo;
         this->ultimo = novo;
         this->size++;
      } else {         
         this->ultimo->prox=novo;
         novo->ant=this->ultimo;
         this->ultimo=novo;
         this->size++;
      }
   }
   // Insere o elemento e na primeira posição
   bool push_front(int e){
    No * novo = new No(nullptr,e,nullptr);
      if (this->empty()){
         this->primeiro = novo;
         this->ultimo = novo;
         this->size++;
      } 
      else{
        this->primeiro->ant=novo;
        novo->prox=this->primeiro;
        this->primeiro=novo;
        this->size++;
      }
   }
   // Insere o elemento e na posição pos
   bool insert(int pos, int e){
   }

   // Remove o último elemento
   int pop_back(){
      if(this->ultimo==nullptr){
         return -1;
      }
      No * temp=this->ultimo;
      int dado=this->ultimo->dado;
      
      if(temp->ant != nullptr){
         this->ultimo=temp->ant;
         this->ultimo->prox=nullptr;
      }else{
         this->ultimo=nullptr;
      }
      
      delete temp;
      this->size--;
      return dado;
      }
   // Remove o primeiro elemento
   int pop_front();
   // Remove o elemento da posição pos e retorna o elemento removido
   int erase(int pos);

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
   void clear();

   // Verifica se o vetor está vazio
   bool empty(){
       return this->size == 0;
   }

   // Devolve a quantidade de elementos
   int size();
   // Substitui o elemento da posição pos pelo elemento e
   bool replace(int pos, int e);

   // Imprime todos os elementos no formato [1,2,3]
   void print(){
      printf("[");
      No* aux = this->primeiro;
      while(aux != nullptr){
         printf("%d", aux->dado);
         aux = aux->prox;
      }

      printf("]");
   }

  private:
   // Dobrar a capacidade quando não houver mais espaço
   // Reduzir a capacidade pela metade quando for inferior a 25% de ocupação
   void gerenciaCapacidade();
};