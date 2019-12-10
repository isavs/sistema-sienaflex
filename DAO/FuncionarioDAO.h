#pragma once
#include <list>
#include "../Model/MFuncionario.h"
using namespace std;

class FuncionarioDAO {
public:
    virtual bool gravar(const char* nome, MFuncionario* funcionario) = 0;
    virtual list<MFuncionario*> getListaFuncionarios(const char* nome) = 0;
    virtual void fechar() = 0;
};
