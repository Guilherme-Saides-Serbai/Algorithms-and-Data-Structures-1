#include <iostream>
#include <string>
#include <vector>
using namespace std;

void STL() {
    string stl = 
        "STL: Standard Template Library\n\n"
        "• Biblioteca padrão de C++ que provê várias estruturas de dados (TADs) e outros recursos.\n\n"
        "| TAD                            | Classe STL         |\n"
        "| ------------------------------- | ------------------- |\n"
        "| Lista Sequencial                | vector              |\n"
        "| Lista Encadeada                 | forward_list        |\n"
        "| Lista Duplamente Encadeada      | list                |\n"
        "| Pilha                           | stack               |\n"
        "| Fila                            | queue               |\n\n"
        "Utiliza templates para prover TADs genéricas. Templates permitem criar código que trabalha sobre tipos diferentes.";
}

vector<int> vet_to_vector(int n, int* v){
    vector<int> vec;
    for(int i=0;i<n;i++){
        vec.push_back(v[i]);
    }
    return vec;
}


int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    std::vector<int> vec = vet_to_vector(size,arr);
    
    // Exibindo os elementos do vector
    for (int i : vec) {
        std::cout << i << " ";
    }

    return 0;
}
