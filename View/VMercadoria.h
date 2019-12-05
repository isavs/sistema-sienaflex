#pragma once
#include "../Controller/CEstoque.h"
#include <iostream>
using namespace std;

class VMercadoria
{
public:
    VMercadoria();
    ~VMercadoria();
    void adicionar();
    void atualizar();
    void pesquisar();
    void remover();
    void listar();
};

