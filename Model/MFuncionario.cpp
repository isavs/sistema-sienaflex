#include "MFuncionario.h"

MFuncionario::MFuncionario()
: MPessoa()
{
    id = 0;
    cargo = "";
    salario = 0.0;
}

/* Para testes */
MFuncionario::MFuncionario(int id, string nome)
: MPessoa(nome)
{
    this->id = id;
}

MFuncionario::MFuncionario(int id, string nome, string cpf, string telefone, UEndereco endereco, string cargo, double salario)
: MPessoa(nome, cpf, telefone, endereco)
{
    this->id = id;
    this->cargo = cargo;
    this->salario = salario;
}

MFuncionario::~MFuncionario()
{

}

void MFuncionario::setId(int id)
{
    this->id = id;
}

void MFuncionario::setCargo(string cargo)
{
    this->cargo = cargo;
}

void MFuncionario::setSalario(double salario)
{
    this->salario = salario;
}

const int MFuncionario::getId()
{
    return id;
}

const string MFuncionario::getCargo()
{
    return cargo;
}

const double MFuncionario::getSalario()
{
    return salario;
}
