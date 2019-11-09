#pragma once
#include "Pessoa.h"

class Funcionario: public Pessoa
{
private:
    static int id;
    double salario;

public:
    Funcionario();
    Funcionario(char* nome);
    Funcionario(int id, char* nome, char* cpf, char* telefone, Endereco endereco, double salario);
    ~Funcionario();
    const int getId();
    const double getSalario();
};
