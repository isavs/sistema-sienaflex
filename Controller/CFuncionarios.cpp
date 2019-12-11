#include "CFuncionarios.h"

int CFuncionarios::ids = 0;

CFuncionarios::CFuncionarios()
{

}

CFuncionarios::~CFuncionarios()
{

}

CFuncionarios& CFuncionarios::getCFuncionarios()
{
    static CFuncionarios cFuncionarios;
    return cFuncionarios;
}

bool CFuncionarios::adicionar(string nome, string cpf, string telefone, UEndereco endereco, string cargo, double salario)
{
    MFuncionarios& mFuncionarios = MFuncionarios::getMFuncionarios();
    MFuncionario* funcionario = new MFuncionario(ids++, nome, cpf, telefone, endereco, cargo, salario);
    if (funcionario != NULL){
        mFuncionarios.setFuncionario(funcionario);
        return true;
    }
    return false;
}

void CFuncionarios::atualizar(MFuncionario* funcionario, string nome, string cpf, string telefone, UEndereco endereco, string cargo, double salario)
{
    if (nome != "")
        funcionario->setNome(nome);
    if (cpf != "")
        funcionario->setCpf(cpf);
    if (telefone != "")
        funcionario->setTelefone(telefone);
    if (cargo != "")
        funcionario->setCargo(cargo);
    if (salario != 0.0)
        funcionario->setSalario(salario);
}

bool CFuncionarios::remover(const string nome, const int id)
{
    MFuncionarios& mFuncionarios = MFuncionarios::getMFuncionarios();
    list<MFuncionario*>::iterator it;
    for (it = mFuncionarios.getListaFuncionarios().begin(); it != mFuncionarios.getListaFuncionarios().end(); ++it){
        if ((*it)->getId() == id){
            if ((*it)->getNome().compare(nome) == 0){
                return mFuncionarios.removeFuncionario(*it);
            }
        }
    }
    return false;
}

MFuncionario* CFuncionarios::pesquisar(const int id, const string cpf)
{
    MFuncionarios& mFuncionarios = MFuncionarios::getMFuncionarios();
    list<MFuncionario*> lista = mFuncionarios.getListaFuncionarios();
    list<MFuncionario*>::iterator it;
    if (id != 0){
        for (it = lista.begin(); it != lista.end(); ++it){
            if ((*it)->getId() == id){
                return (*it);
            }
        }
    }
    if (cpf != ""){
        for (it = lista.begin(); it != lista.end(); ++it){
            size_t cpfEncontrado = ((*it)->getNome()).find(cpf);
            if (cpfEncontrado != string::npos){
                return (*it);
            }
        }
    }
    return NULL;
}

list<MFuncionario*> CFuncionarios::pesquisarNomes(const string nome)
{
    MFuncionarios& mFuncionarios = MFuncionarios::getMFuncionarios();
    list<MFuncionario*> listaAux;
    list<MFuncionario*>::iterator it;
    for (it = mFuncionarios.getListaFuncionarios().begin(); it != mFuncionarios.getListaFuncionarios().end(); ++it){
        size_t nomeEncontrado = ((*it)->getNome()).find(nome);
        if (nomeEncontrado != string::npos){
            listaAux.push_back(*it);
        }
    }
    return listaAux;
}

list<MFuncionario*> CFuncionarios::listar()
{
    MFuncionarios& mFuncionarios = MFuncionarios::getMFuncionarios();
    return mFuncionarios.getListaFuncionarios();
}
void CFuncionarios::salvarFuncionarios()
{
    MFuncionarios& mFuncionarios = MFuncionarios::getMFuncionarios();
    mFuncionarios.salvarFuncionarios();
}