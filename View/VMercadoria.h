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
    void pesquisarId();
    void pesquisarCaracteristicas();
    void remover();
    void listar();
    void imprimirInformacoes(MColchao* mercadoria);
    void imprimirInformacoes(MEstofado* mercadoria);
    void salvar();
};

