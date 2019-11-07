/**
 * Classe lista contendo todos os funcionários cadastrados na empresa.
 */
#pragma once
#include <iostream>
#include <list>
using namespace std;
#include "Funcionario.h"

class Membros
{
private:
    int id;
    list<Funcionario*> funcionarios;

public:
    Membros();
    ~Membros();
    void adicionarFuncionario(Funcionario* funcionario);
    void removerFuncionario(const int id);
    Funcionario* pesquisarFuncionario(const int id);
    void listarFuncionarios();
};