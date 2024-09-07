#include <iostream>
#include <vector>
#include <forward_list>
#include <stack> 
#include <queue>
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
    vector<int> vet;
    for (int i = 0; i < n; i++)
    {
        vet.push_back(v[i]);
    }
    return vet;
    
}
forward_list<int> vet_to_flist(int n, int v[]){
    forward_list<int>flist;
    auto it=flist.before_begin();
    for (int i = 0; i < n; i++)
    { 
        it=flist.insert_after(it,v[i]);
    }
    return flist;
}
stack<int> vet_to_stack(int n, int v[]) {
    stack<int> s;
    for (int i = n - 1; i >= 0; --i) {
        s.push(v[i]);
    }

    return s;
}
vector<int> list_concat(forward_list<int>& list1, forward_list<int>& list2){
    vector<int> vet;
    for (auto it=list1.begin();it!=list1.end();++it)
    {
        vet.push_back(*it);
    }
     for (auto it=list2.begin();it!=list2.end();++it)
    {
        vet.push_back(*it);
    }
    return vet;
}