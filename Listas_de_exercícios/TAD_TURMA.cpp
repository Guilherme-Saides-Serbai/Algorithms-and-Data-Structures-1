#include <iostream>
#include <string>
using namespace std;

class Aluno {
public:
    string nome;
    string ra;
public:
    Aluno(string _nome, string _ra);
    void get_aluno();
};

Aluno::Aluno(string _nome, string _ra) {
    nome = _nome;
    ra = _ra;
}

void Aluno::get_aluno() {
    cout << "nome:" << nome << endl;
    cout << "ra:" << ra << endl;
}

class Turma {
private:
    string codigo_da_disciplina;
    string codigo_da_turma;
    string semestre;
    Aluno ** aluno;
    int tamanho_turma;
    int contador_alunos = 0;
public:
    Turma(string _codigo_da_disciplina, string _codigo_da_turma, string _semestre, int _tamanho_turma);
    ~Turma();
    void get_turma();
    void set_aluno(string _nome, string _ra);
    void get_alunos();
};

Turma::Turma(string _codigo_da_disciplina, string _codigo_da_turma, string _semestre, int _tamanho_turma) {
    codigo_da_disciplina = _codigo_da_disciplina;
    codigo_da_turma = _codigo_da_turma;
    semestre = _semestre;
    tamanho_turma = _tamanho_turma;
    aluno = new Aluno * [_tamanho_turma];
    for (int i = 0; i < _tamanho_turma; i++) {
        aluno[i] = nullptr;
        
    }
}

Turma::~Turma() {
    cout << "o objeto foi destruido!!!" << endl;
}

void Turma::get_turma() {
    cout << "codigo da disciplina:" << codigo_da_disciplina << endl;
    cout << "codigo da turma:" << codigo_da_turma << endl;
    cout << "semestre:" << semestre << endl;
}

void Turma::set_aluno(string _nome, string _ra) {
    if (contador_alunos < tamanho_turma) {
        aluno[contador_alunos] = new Aluno(_nome, _ra);
        contador_alunos++;
    }
    else {
        cout << "Não há espaço para mais alunos nesta turma." << endl;
    }
}

void Turma::get_alunos() {
    cout << "Alunos na turma:" << endl;
    for (int i = 0; i < contador_alunos; ++i) {
        if (aluno[i] != nullptr) {
            aluno[i]->get_aluno();
        }
    }
}

int main() {
    string codigo_disciplina, codigo_turma, semestre;
    int tamanho_turma;

    cout << "Digite o código da disciplina: ";
    cin >> codigo_disciplina;
    cout << "Digite o código da turma: ";
    cin >> codigo_turma;
    cout << "Digite o semestre: ";
    cin >> semestre;
    cout << "Digite o tamanho da turma: ";
    cin >> tamanho_turma;

    Turma turma(codigo_disciplina, codigo_turma, semestre, tamanho_turma);
    turma.get_turma();

    for (int i = 0; i < tamanho_turma; ++i) {
        string nome, ra;
        cout << "Digite o nome do aluno " << i + 1 << ": ";
        cin >> nome;
        cout << "Digite o RA do aluno " << i + 1 << ": ";
        cin >> ra;
        turma.set_aluno(nome, ra);
    }

    turma.get_alunos();

    return 0;
}

