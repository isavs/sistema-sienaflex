#include "Pessoal.h"

Pessoal::Pessoal()
{

}

Pessoal::~Pessoal()
{
    // TEM QUE LIBERAR A LIST? SE SIM, COMO? DESCOBRIR.
}

void Pessoal::adicionarFuncionario(Funcionario* funcionario)
{
    if (funcionario != NULL){
        funcionarios.push_back(funcionario);
    }
}

void Pessoal::removerFuncionario(const int id)
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

Funcionario* Pessoal::pesquisarFuncionario(const int id)
{
    list<Funcionario*>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
        if ((*it)->getId() == id){
            return *it;
        }
    }
    return NULL;
}

void Pessoal::listarFuncionarios()
{
    list<Funcionario*>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
        cout << "\n\tColaborador " << (*it)->getNome()
        << " com id " << (*it)->getId() << endl;
    }
    cout << endl;
}
