
#include <string>
#include <iostream>
using namespace std;

class Vetor{

    private:
        int* array;
        int capacity;
        int size;

    public:
        Vetor(int _capacity,int _size,int initial_value){
            capacity=_capacity;
            size=_size;
            array=new int(capacity);
            for(int i=0;i<capacity;i++){
                array[i]=initial_value;
            }
        }
        ~Vetor(void){
            cout << "o objeto foi deletado!!!"<< endl;
            delete[] array;
        }

        // Insere o elemento e na última posição
        bool push_back(int e){
             if(size<capacity){
                array[size]=e;
                size++;
                cout << "o elemento:" << e << "foi inserido com sucesso!" << endl;
             }
             else{
                cout << "o vetor está cheio não foi possivel inserir o elemento:" << e << endl;
             }

        }
        // Insere o elemento e na primeira posição
        bool push_front(int e){
            if(size<capacity){
             for(int i=size-1;i>=0;i--){
                 array[i+1]=i;
             }
             array[0]=e;
             cout << "o elemento" << e << "foi inserido com sucesso!!!" << endl;
             }
             else{
                cout << "o vetor está cheio não foi possivel inserir o elemento" << e << endl;
             }
        }
        // Insere o elemento e na posição pos
        bool insert(int pos, int e){
            if(size<capacity){
                if(pos<size){
                    for(int i=size-1;i>=pos;i--){
                        array[i+1]=i;
                    }
                    array[pos]=e;
                    size++;
                    cout << "o elemento" << e << "foi inserido com sucesso!!!" << endl;
                }}
                
            else{
                cout << "o vetor está cheio não foi possivel inserir o elemento" << e << endl;
            }
        

        // Remove o último elemento
        int pop_back(){
            size--;
        }
        // Remove o primeiro elemento
        int pop_front(){
            if(size<=0){
                return -1;
            }
            for(int i=0;i<size-1;i++){
                array[i]=i++;
            }
            size--;
        }
        // Remove o elemento da posição pos e retorna o elemento removido
        int erase(int pos){
            int temp=array[pos];
            for(int i=pos;i<size-1;i++){
                    array[i]=array[i+1];
            }
            size--;
            return temp;
        }


        // Retorna o primeiro elemento
        int front(){
            if(array==NULL){
                cout << "o vetor está vazio!!!" << endl;
            }
            else{
            int temp=array[0];
            return temp;}
        }
        // Retorna o último elemento
        int back(){
            if(array==NULL){
                cout << "o vetor está vazio!!!" << endl;
            }
            else{
            int temp=array[size-1];
            return temp;}

        }
        // Retorna o elemento da posição pos
        int at(int pos){
            int temp=array[pos];
            return temp;
        }

        // Torna a lista vazia
        void clear(){
            for(int i=0;i<size-1;i++){
                array[i]=NULL
            }
        }

        // Verifica se o vetor está vazio
        bool empty(){
            if(array==NULL){
                return 1;
            }
            return 0;
        }
        // Devolve a quantidade de elementos
        int size(){
            if(arrray == NULL){
                return 0;
            }
            return size-1;
        }
        // Substitui o elemento da posição pos pelo elemento e
        bool replace(int pos, int e){
            for(int i=0;i<size-1;i++){
                if(array[i]==pos){
                    array[i]=e;
                }
            }
        }

        // Imprime todos os elementos no formato [1,2,3]
        void print(){
            for(int i=0;i<size-1;i++){
                cout << array[i] << endl;
            }
        }

    private:
	    // Dobrar a capacidade quando não houver mais espaço
	    // Reduzir a capacidade pela metade quando for inferior a 25% de ocupação
        void gerenciaCapacidade(){
            if(size==capacity){
                capacity=2*capacity;
                array=new int(capacity);
                   for(int i=0;i<capacity;i++){
                       array[i]=initial_value;
            }
        }    
        if(size=25*size/100){
            capacity=capacity/2;
             array=new int(capacity);
                for(int i=0;i<capacity;i++){
                    array[i]=initial_value;
        }   
}}}};

int main() {
    // Criando um objeto Vetor com capacidade 10, tamanho inicial 0 e sem valor inicial
    Vetor vetor(10, 0, 0);

    // Adicionando elementos ao vetor
    vetor.push_back(10);
    vetor.push_back(20);
    vetor.push_back(30);
    vetor.push_back(40);
    vetor.push_back(50);

    // Inserindo elementos em posições específicas
    vetor.insert(2, 25); // Inserir 25 na posição 2
    vetor.insert(5, 35); // Inserir 35 na posição 5

    // Adicionando um elemento no início do vetor
    vetor.push_front(5);

    // Tentando adicionar mais elementos quando o vetor está cheio
    vetor.push_back(60); // Tentativa de inserir em um vetor cheio

    return 0;
}


