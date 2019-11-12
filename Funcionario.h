#pragma once
#include "Pessoa.h"

class Funcionario: public Pessoa
{
private:
    static int quantidadeFuncionarios;
    int id;
    double salario;

public:
    Funcionario();
    Funcionario(string nome);
    Funcionario(string nome, string cpf, string telefone, Endereco endereco, double salario);
    ~Funcionario();
    const int getId();
    const double getSalario();
};
