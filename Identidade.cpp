#include "Identidade.h"

Identidade::Identidade()
{
    id = 0;
    nome = NULL;
}

Identidade::Identidade(int id, char* nome)
{
    this->id = id;
    strcpy(this->nome, nome);
}

Identidade::~Identidade()
{

}

void Identidade::setId(int id)
{
    this->id = id;
}

const int Identidade::getId()
{
    return id;
}

void Identidade::setNome(char* nome)
{
    strcpy(this->nome, nome);
}

const char* Identidade::getNome()
{
    return nome;
}