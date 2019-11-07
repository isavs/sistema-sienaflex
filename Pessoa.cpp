#include "Pessoa.h"

Pessoa::Pessoa():
endereco()
{

}

Pessoa::Pessoa(char* nome, char* cpf, char* telefone, Endereco endereco)
{
    strcpy(this->nome, nome);
    strcpy(this->cpf, cpf);
    strcpy(this->telefone, telefone);
    this->endereco = endereco;
}

Pessoa::~Pessoa()
{

}

const char* Pessoa::getNome()
{
    return nome;
}

const char* Pessoa::getCpf()
{
    return cpf;
}

const char* Pessoa::getTelefone()
{
    return telefone;
}