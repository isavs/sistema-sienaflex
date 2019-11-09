#include "Funcionario.h"

int Funcionario::id = 0;

Funcionario::Funcionario()
: Pessoa()
{
    id++;
    salario = 0.0;
}

/* Para testes */
Funcionario::Funcionario(char* nome)
: Pessoa(nome)
{
    id++;
}

Funcionario::Funcionario(int id, char* nome, char* cpf, char* telefone, Endereco endereco, double salario)
: Pessoa(nome, cpf, telefone, endereco)
{
    this->id = id;
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
