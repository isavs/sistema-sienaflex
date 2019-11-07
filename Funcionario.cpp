#include "Funcionario.h"

Funcionario::Funcionario():
Pessoa()
{
    salario = 0.0;
}

Funcionario::Funcionario(char* nome, Endereco endereco, double salario)
{
    this->salario = salario;
}

Funcionario::~Funcionario()
{

}