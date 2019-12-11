#pragma once
#include <list>
#include "../Model/MEstofado.h"
using namespace std;

class EstofadoDAO {
public:
    virtual bool gravar(const char* nome, MEstofado* estofado) = 0;
    virtual list<MEstofado*> getListaEstofados(const char* nome) = 0;
    virtual void fechar() = 0;
};
