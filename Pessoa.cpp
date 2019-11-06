#include "Pessoa.h"

Pessoa::Pessoa():
endereco(0, "", 0, "", "", "", "", "")
{

}

Pessoa::Pessoa(char* nome, Endereco endereco)
{
    this->endereco = endereco;
}

Pessoa::~Pessoa()
{

}