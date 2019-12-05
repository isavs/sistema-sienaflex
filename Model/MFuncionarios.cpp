#include "MFuncionarios.h"

MFuncionarios* MFuncionarios::mFuncionarios = 0;

MFuncionarios::MFuncionarios()
{

}

MFuncionarios::~MFuncionarios()
{
    delete mFuncionarios;
}

MFuncionarios* MFuncionarios::getMFuncionarios()
{
    if (mFuncionarios == 0){
        mFuncionarios = new MFuncionarios();
    }
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
