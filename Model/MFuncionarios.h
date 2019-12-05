#pragma once
#include <list>
#include "../Model/MFuncionario.h"

class MFuncionarios
{
private:
    static MFuncionarios* mFuncionarios;
    list<MFuncionario*> listaFuncionarios;

private:
    MFuncionarios();
    ~MFuncionarios();

public:
    static MFuncionarios* getMFuncionarios();
    bool setFuncionario(MFuncionario* funcionario);
    list<MFuncionario*> getListaFuncionarios();
};
