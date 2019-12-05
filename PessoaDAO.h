#pragma once
#include <list>
#include "Pessoa.h"
using namespace std;

class PessoaDAO {
public:
    virtual bool gravar(const char* nome, Pessoa* Pessoa) = 0;
    virtual list<Pessoa*> getListaPessoas(const char* nome) = 0;
    virtual void fechar() = 0;
};
