#include "Pessoa.h"

Pessoa::Pessoa():
endereco()
{
    this->nome = "";
    this->cpf = "";
    this->telefone = "";
}

/* Para testes */
Pessoa::Pessoa(string nome)
{
    this->nome = nome;
}

Pessoa::Pessoa(string nome, string cpf, string telefone, Endereco endereco)
{
    this->nome = nome;
    this->cpf = cpf;
    this->telefone = telefone;
    this->endereco = endereco;
}

Pessoa::~Pessoa()
{

}

const string Pessoa::getNome()
{
    return nome;
}

const string Pessoa::getCpf()
{
    return cpf;
}

const string Pessoa::getTelefone()
{
    return telefone;
}
Endereco Pessoa::getEndereco()
{
    return endereco;
}