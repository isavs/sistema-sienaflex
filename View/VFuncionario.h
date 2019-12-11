#pragma once
#include <stdio_ext.h>
#include <iostream>
#include <string>
using namespace std;
#include "../Controller/CFuncionarios.h"
#include "../Util/UEndereco.h"

class VFuncionario
{
public:
    VFuncionario();
    ~VFuncionario();
    void view();
    void cadastrar();
    void pesquisar();
    void atualizar();
    void desligar();
    void listar();
    void imprimirInformacoes(MFuncionario* funcionario);
};
