#include "Pessoa.h"

Pessoa::Pessoa():
endereco()
{

}

Pessoa::Pessoa(char* nome, char* cpf, char* telefone, Endereco endereco)
{
    this->endereco = endereco;
}

Pessoa::~Pessoa()
{

}