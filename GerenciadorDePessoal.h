#pragma once
#include <stdio.h>
//#include <stdio_ext.h>
#include <iostream>
using namespace std;
#include "Pessoal.h"
#include "Funcionario.h"

class GerenciadorDePessoal
{
private:
    static GerenciadorDePessoal* gerenciadorDePessoal;
    Pessoal listaFuncionarios;

private:
    GerenciadorDePessoal();
    ~GerenciadorDePessoal();

public:
    static GerenciadorDePessoal* getGerenciadorDePessoal();
    void cadastrarFuncionario();
    void desligarFuncionario();
    void pesquisarFuncionario();
    void listarFuncionarios();
};
