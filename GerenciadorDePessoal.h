#pragma once
#include <stdio.h>
#include <stdio_ext.h>
#include <iostream>
using namespace std;
#include "Pessoal.h"
#include "Funcionario.h"

class GerenciadorDePessoal
{
private:
<<<<<<< HEAD
    //static int id;
=======
    static GerenciadorDePessoal* gerenciadorDePessoal;
>>>>>>> 5c4609f3541e17cd3f64e56cd965140a7ecd0624
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
