#pragma once
#include "Pessoa.h"

class Funcionario: public Pessoa
{
private:
    double salario;

public:
    Funcionario();
    Funcionario(char* nome, Endereco endereco, double salario);
    ~Funcionario();
};