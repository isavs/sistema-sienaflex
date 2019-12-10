#pragma once
#include "../Controller/CMercadoria.h"
#include <stdio_ext.h>
#include <iostream>
using namespace std;

class VMercadoria
{
public:
    VMercadoria();
    ~VMercadoria();
    void view();
    void adicionar();
    void atualizar();
    void pesquisar();
    void remover();
    void listar();
    void getInfo(MColchao* mercadoria);
    void getInfo(MEstofado* mercadoria);
    void pesquisarId();
    void pesquisarCaracteristicas();
};

