#include "MPessoa.h"

MPessoa::MPessoa():
endereco()
{
    this->nome = "";
    this->cpf = "";
    this->telefone = "";
}

/* Para testes */
MPessoa::MPessoa(string nome)
{
    this->nome = nome;
}

MPessoa::MPessoa(string nome, string cpf, string telefone, UEndereco endereco)
{
    this->nome = nome;
    this->cpf = cpf;
    this->telefone = telefone;
    this->endereco = endereco;
}

MPessoa::~MPessoa()
{

}

void MPessoa::setNome(string nome)
{
    this->nome = nome;
}

void MPessoa::setCpf(string cpf)
{
    this->cpf = cpf;
}

void MPessoa::setTelefone(string telefone)
{
    this->telefone = telefone;
}

const string MPessoa::getNome()
{
    return nome;
}

const string MPessoa::getCpf()
{
    return cpf;
}

const string MPessoa::getTelefone()
{
    return telefone;
}

const UEndereco MPessoa::getEndereco()
{
    return endereco;
}
