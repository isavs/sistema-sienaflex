#pragma once
#include <list>
#include "Mercadoria.h"
using namespace std;

class MercadoriaDAO {
public:
    virtual bool gravar(const char* nome, Mercadoria* mercadoria) = 0;
    virtual list<Mercadoria*> getListaMercadorias(const char* nome) = 0;
    virtual void fechar() = 0;
};
