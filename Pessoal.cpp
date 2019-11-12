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

void Pessoal::removerFuncionario(const string nome, const int id)
{
    list<Funcionario*>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
        if ((*it)->getId() == id){
            if ((*it)->getNome().compare(nome) == 0){
                funcionarios.erase(it);
            }
            return;
        }
    }
    cout << "\n\tErro: funcionário não encontrado para remoção." << endl;
}

void Pessoal::pesquisarFuncionario(const string nome)
{
    bool flag = true;
    list<Funcionario*>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
        size_t nomeEncontrado = ((*it)->getNome()).find(nome);
        if (nomeEncontrado != string::npos){
            cout << "\tColaborador: " << (*it)->getNome()
                 << " Id: " << (*it)->getId() << endl;
            flag = false;
        }
    }
    if (flag){
        cout << "\tNenhum funcionário encontrado." << endl;
    }
}

void Pessoal::listarFuncionarios()
{
    bool flag = true;
    list<Funcionario*>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it){
        cout << "\n\tColaborador " << (*it)->getNome()
        << " com id " << (*it)->getId();
        flag = false;
    }
    if (flag){
        cout << "\n\tLista de funcionários vazia.";
    }
    cout << endl;
}
