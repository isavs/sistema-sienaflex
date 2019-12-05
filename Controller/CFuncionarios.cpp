#include "CFuncionarios.h"

int CFuncionarios::ids = 0;

CFuncionarios::CFuncionarios()
{
    funcionarios = MFuncionarios::getMFuncionarios();
}

CFuncionarios::~CFuncionarios()
{

}

bool CFuncionarios::adicionar(string nome, string cpf, string telefone, double salario)
{
    MFuncionario* funcionario = new MFuncionario();
    funcionario->setNome(nome);
    funcionario->setCpf(cpf);
    funcionario->setTelefone(telefone);
    funcionario->setId(++id);
    funcionario->setSalario(salario);

    if (funcionario != NULL){
        funcionarios->setFuncionario(funcionario);
        return true;
    }
    return false;
}

bool CFuncionarios::remover(const string nome, const int id)
{
    list<MFuncionario*>::iterator it;
    for (it = funcionarios->getListaFuncionarios().begin(); it != funcionarios->getListaFuncionarios().end(); ++it){
        if ((*it)->getId() == id){
            if ((*it)->getNome().compare(nome) == 0){
                //funcionarios.erase(it);
                return true;
            }
        }
    }
    return false;
}

list<MFuncionario*> CFuncionarios::pesquisar(const string nome)
{
    list<MFuncionario*> listaAux;
    list<MFuncionario*>::iterator it;
    for (it = funcionarios->getListaFuncionarios().begin(); it != funcionarios->getListaFuncionarios().end(); ++it){
        size_t nomeEncontrado = ((*it)->getNome()).find(nome);
        if (nomeEncontrado != string::npos){
            listaAux.push_back(*it);
        }
    }
    return listaAux;
}

list<MFuncionario*> CFuncionarios::listar()
{
    return funcionarios->getListaFuncionarios();
}
