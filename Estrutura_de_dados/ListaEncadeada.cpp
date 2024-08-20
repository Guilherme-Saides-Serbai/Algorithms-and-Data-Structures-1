#include <iostream>

class No {
  public:
   No* ant;
   int dado;
   No* prox;

   No(No* ant, int dado, No* prox) : ant(ant), dado(dado), prox(prox) {}
};

class ListaEncadeada {

  private:
   No* primeiro;
   No* ultimo;
   int size;

  public:
   ListaEncadeada() : primeiro(nullptr), ultimo(nullptr), size(0) {}
   ~ListaEncadeada();

   // Insere o elemento na última posição
   bool push_back(int e) {
      No* novo = new No(nullptr, e, nullptr);
      
      if (this->empty()) {
         this->primeiro = novo;
         this->ultimo = novo;
      } else {
         this->ultimo->prox = novo;
         novo->ant = this->ultimo;
         this->ultimo = novo;
      }
      this->size++;
      return true;
   }

   // Insere o elemento na primeira posição
   bool push_front(int e) {
      No* novo = new No(nullptr, e, this->primeiro);

      if (this->empty()) {
         this->primeiro = novo;
         this->ultimo = novo;
      } else {
         this->primeiro->ant = novo;
         this->primeiro = novo;
      }
      this->size++;
      return true;
   }

   // Insere o elemento na posição pos
   bool insert(int pos, int e) {
      if (pos < 0 || pos > size) return false;

      if (pos == 0) {
         push_front(e);
         return true;
      } else if (pos == size) {
         push_back(e);
         return true;
      } else {
         No* atual = primeiro;
         for (int i = 0; i < pos; ++i) {
            atual = atual->prox;
         }
         No* novo = new No(atual->ant, e, atual);
         if (atual->ant) {
            atual->ant->prox = novo;
         }
         atual->ant = novo;
         this->size++;
         return true;
      }
   }

   // Remove o último elemento
   int pop_back() {
      if (this->empty()) return -1;
      
      No* temp = this->ultimo;
      int dado = temp->dado;
      
      if (this->ultimo->ant) {
         this->ultimo = this->ultimo->ant;
         this->ultimo->prox = nullptr;
      } else {
         this->primeiro = nullptr;
         this->ultimo = nullptr;
      }
      
      delete temp;
      this->size--;
      return dado;
   }

   // Remove o primeiro elemento
   int pop_front() {
      if (this->empty()) return -1;
      
      No* temp = this->primeiro;
      int dado = temp->dado;
      
      if (this->primeiro->prox) {
         this->primeiro = this->primeiro->prox;
         this->primeiro->ant = nullptr;
      } else {
         this->primeiro = nullptr;
         this->ultimo = nullptr;
      }
      
      delete temp;
      this->size--;
      return dado;
   }

   // Remove o elemento da posição pos e retorna o elemento removido
   int erase(int pos) {
      if (pos < 0 || pos >= size) return -1;
      
      if (pos == 0) return pop_front();
      if (pos == size - 1) return pop_back();
      
      No* atual = primeiro;
      for (int i = 0; i < pos; ++i) {
         atual = atual->prox;
      }
      
      No* temp = atual;
      int dado = atual->dado;
      if (atual->ant) {
         atual->ant->prox = atual->prox;
      }
      if (atual->prox) {
         atual->prox->ant = atual->ant;
      }
      delete temp;
      this->size--;
      return dado;
   }

   // Retorna o primeiro elemento
   int front() {
      if (this->empty()) throw std::out_of_range("Lista vazia");
      return primeiro->dado;
   }

   // Retorna o último elemento
   int back() {
      if (this->empty()) throw std::out_of_range("Lista vazia");
      return ultimo->dado;
   }

   // Retorna o elemento da posição pos
   int at(int pos) {
      if (pos < 0 || pos >= size) throw std::out_of_range("Índice fora dos limites");
      
      No* atual = primeiro;
      for (int i = 0; i < pos; ++i) {
         atual = atual->prox;
      }
      return atual->dado;
   }

   // Torna a lista vazia
   void clear() {
      while (!empty()) {
         pop_front();
      }
   }

   // Verifica se a lista está vazia
   bool empty() {
       return this->size == 0;
   }

   // Devolve a quantidade de elementos
   int size() {
       return this->size;
   }

   // Substitui o elemento da posição pos pelo elemento e
   bool replace(int pos, int e) {
      if (pos < 0 || pos >= size) return false;
      
      No* atual = primeiro;
      for (int i = 0; i < pos; ++i) {
         atual = atual->prox;
      }
      atual->dado = e;
      return true;
   }

   // Imprime todos os elementos no formato [1,2,3]
   void print() {
      std::cout << "[";
      No* aux = this->primeiro;
      while (aux != nullptr) {
         std::cout << aux->dado;
         aux = aux->prox;
         if (aux != nullptr) std::cout << ",";
      }
      std::cout << "]" << std::endl;
   }

   // Destrutor para liberar a memória
   ~ListaEncadeada() {
      clear();
   }
};
