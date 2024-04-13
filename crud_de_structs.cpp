#include<iostream>
#include<string>
using namespace std;

typedef struct Livro {
    string titulo;
    unsigned int numero_de_paginas;
    float preco;
} Livro;

Livro* create_Livro(const string& titulo, unsigned int numero_de_paginas, float preco) {
    Livro* pointer = new Livro; 
    pointer->titulo = titulo;
    pointer->numero_de_paginas = numero_de_paginas;
    pointer->preco = preco;
    return pointer;
}

Livro* update_Livro(Livro* pointer, const string& novo_titulo, unsigned int novo_numero_de_paginas, float novo_preco){
    pointer->titulo = novo_titulo;
    pointer->numero_de_paginas = novo_numero_de_paginas;
    pointer->preco = novo_preco;
    return pointer;
}

void _delete(Livro * Pointer){
    delete Pointer;
}

void read_livro(Livro * pointer){
    cout << pointer->titulo << endl;
    cout << pointer->numero_de_paginas << endl;
    cout << pointer->preco << endl;
}

int main() {
    // Criar um livro
    Livro* meuLivro = create_Livro("Dom Quixote", 600, 45.99);
    if (meuLivro == NULL) {
        cout << "Erro ao criar o livro." << endl;
        return 1;
    }

    // Exibir informações do livro
    cout << "Informações do livro:" << endl;
    read_livro(meuLivro);
    printf("\n\n");

    // Atualizar informações do livro
    meuLivro = update_Livro(meuLivro, "Cem Anos de Solidão", 400, 35.50);
    cout << "Informações atualizadas do livro:" << endl;
    read_livro(meuLivro);

    // Deletar o livro
    _delete(meuLivro);

    return 0;
}
