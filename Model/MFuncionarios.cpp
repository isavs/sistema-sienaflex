#include "MFuncionarios.h"

MFuncionarios::MFuncionarios()
{

}

MFuncionarios::~MFuncionarios()
{
    delete mFuncionarios;
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

list<MFuncionario*> MFuncionarios::getListaFuncionarios()
{
    return listaFuncionarios;
}
