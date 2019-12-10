#pragma once
#include <list>
#include "../Model/MColchao.h"
using namespace std;

class ColchaoDAO {
public:
    virtual bool gravar(const char* nome, MColchao* colchao) = 0;
    virtual list<MColchao*> getListaColhaos(const char* nome) = 0;
    virtual void fechar() = 0;
};
