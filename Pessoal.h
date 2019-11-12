/**
 * Classe lista contendo todos os funcionários cadastrados na empresa.
 */
#pragma once
#include <iostream>
#include <list>
using namespace std;
#include "Funcionario.h"

class Pessoal
{
private:
    int id;
    list<Funcionario*> funcionarios;

public:
    Pessoal();
    ~Pessoal();
    void adicionarFuncionario(Funcionario* funcionario);
    void removerFuncionario(const string nome, const int id);
    void pesquisarFuncionario(const string nome);
    void listarFuncionarios();
};
