#include "Membros.h"

Membros::Membros()
{

}

Membros::~Membros()
{
    list<Funcionario*>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
        funcionarios.erase(it);
    }
    funcionarios.clear();
}

void Membros::adicionarFuncionario(Funcionario* funcionario)
{
    if (funcionario != NULL){
        funcionarios.push_back(funcionario);
    }
}

void Membros::removerFuncionario(const int id)
{
    list<Funcionario*>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
        if ((*it)->getId == id){
            funcionarios.erase(it);
            return;
        }
    }
    cout << "Erro: funcionário não encontrado para remoção." << endl;
}

Funcionario* Membros::pesquisarFuncionario(const int id)
{
    list<Funcionario*>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
        if ((*it)->getId == id){
            return *it;
        }
    }
    cout << "Erro: funcionário não encontrado." << endl;
}

void Membros::listarFuncionarios()
{
    list<Funcionario*>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
        cout << "Nome: " << (*it)->getNome() << endl
        << "Id: " << (*it)->getId() << endl << endl; // checar se 2 endls pulas 2 linhas
    }
}