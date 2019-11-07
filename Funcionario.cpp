#include "Funcionario.h"

Funcionario::Funcionario()
: Pessoa()
{
    id = 0;
    salario = 0.0;
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