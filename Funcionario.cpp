#include "Funcionario.h"

int Funcionario::quantidadeFuncionarios = 0;

Funcionario::Funcionario()
: Pessoa()
{
    id = ++quantidadeFuncionarios;
    salario = 0.0;
}

/* Para testes */
Funcionario::Funcionario(string nome)
: Pessoa(nome)
{
    id = ++quantidadeFuncionarios;
}

Funcionario::Funcionario(string nome, string cpf, string telefone, Endereco endereco, double salario)
: Pessoa(nome, cpf, telefone, endereco)
{
    id = ++quantidadeFuncionarios;
    this->salario = salario;
}

Funcionario::~Funcionario()
{

}

const int Funcionario::getId()
{
    return id;
}

const double Funcionario::getSalario()
{
    return salario;
}
