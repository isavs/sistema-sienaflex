#pragma once
#include <list>
#include "../Model/MFuncionario.h"
#include "../DAO/FuncionarioDAObin.h"
#include "../DAO/FuncionarioDAOcsv.h"

class MFuncionarios
{
private:
    static MFuncionarios* mFuncionarios;
    list<MFuncionario*> listaFuncionarios;
    FuncionarioDAObin fbin;
    FuncionarioDAOcsv fcsv;

private:
    MFuncionarios();
    ~MFuncionarios();

public:
    static MFuncionarios &getMFuncionarios();
    MFuncionarios(const MFuncionarios&) = delete;
    void operator = (const MFuncionarios&) = delete;

    bool setFuncionario(MFuncionario* funcionario);
    bool removeFuncionario(MFuncionario* funcionario);
    list<MFuncionario*> getListaFuncionarios();

    void salvarFuncionarios();
};
