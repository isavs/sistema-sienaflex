#include "MFuncionario.h"

MFuncionario::MFuncionario()
: MPessoa()
{
    id = 0;
    salario = 0.0;
    ativo = true;
}

/* Para testes */
MFuncionario::MFuncionario(int id, string nome)
: MPessoa(nome)
{
    this->id = id;
}

MFuncionario::MFuncionario(int id, string nome, string cpf, string telefone, UEndereco endereco, double salario)
: MPessoa(nome, cpf, telefone, endereco)
{
    this->id = id;
    this->salario = salario;
}

MFuncionario::~MFuncionario()
{

}

void MFuncionario::setId(int id)
{
    this->id = id;
}

void MFuncionario::setSalario(double salario)
{
    this->salario = salario;
}

void MFuncionario::setStatus(bool ativo)
{
    this->ativo = ativo;
}

const int MFuncionario::getId()
{
    return id;
}

const double MFuncionario::getSalario()
{
    return salario;
}

const bool MFuncionario::getStatus()
{
    return ativo;
}
