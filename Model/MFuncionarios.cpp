#include "MFuncionarios.h"

MFuncionarios::MFuncionarios()
{

}

MFuncionarios::~MFuncionarios()
{

}

MFuncionarios& MFuncionarios::getMFuncionarios()
{
    static MFuncionarios mFuncionarios;
    return mFuncionarios;
}

bool MFuncionarios::setFuncionario(MFuncionario* funcionario)
{
    if (funcionario != NULL){
        listaFuncionarios.push_back(funcionario);
        return true;
    }
    return false;
}

bool MFuncionarios::removeFuncionario(MFuncionario* funcionario)
{
    if (funcionario != NULL){
        listaFuncionarios.remove(funcionario);
        return true;
    }
    return false;
}

list<MFuncionario*> MFuncionarios::getListaFuncionarios()
{
    return listaFuncionarios;
}
