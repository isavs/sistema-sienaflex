#pragma once
#include <iostream>
using namespace std;
#include "Pessoal.h"
#include "Funcionario.h"

class GerenciadorDePessoal
{
private:
    static int id;
    Pessoal listaFuncionarios;

public:
    GerenciadorDePessoal();
    ~GerenciadorDePessoal();
    void cadastrarFuncionario();
    void desligarFuncionario();
    void pesquisarFuncionario();
    void listarFuncionarios();
};
