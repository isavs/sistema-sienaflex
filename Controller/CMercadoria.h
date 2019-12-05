#pragma once
#include "../Model/MMercadoria.h"
#include "CEstoque.h"

class CMercadoria
{
private:
    static int ids;
    int id;
    CEstoque* cEstoque;

public:
    CMercadoria();
    ~CMercadoria();
    bool criarColchao(string nome);
    bool criarBase();
    bool criarSofa();
    bool criarPoltrona();
    bool criarPuff();
};
