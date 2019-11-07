#include "Membros.h"

Membros::Membros()
{

}

Membros::~Membros()
{
    // TEM QUE LIBERAR A LIST?
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
        if ((*it)->getId() == id){
            funcionarios.erase(it);
            return;
        }
    }
    cout << "\n\tErro: funcionário não encontrado para remoção." << endl;
}

Funcionario* Membros::pesquisarFuncionario(const int id)
{
    list<Funcionario*>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
        if ((*it)->getId() == id){
            return *it;
        }
    }
    cout << "\n\tErro: funcionário não encontrado." << endl;
}

void Membros::listarFuncionarios()
{
    list<Funcionario*>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
        cout << "\n\tNome: " << (*it)->getNome() << endl
        << "\tId: " << (*it)->getId() << endl << endl; // checar se 2 endls pulas 2 linhas
    }
}