#include "Identidade.h"

Identidade::Identidade():
data(0, 0, 0)
{
    id = 0;
    nome = NULL;
}

Identidade::~Identidade()
{

}

void Identidade::setId(int id)
{
    this->id = id;
}

int Identidade::getId()
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

void Identidade::setDataCadastro(int dia, int mes, int ano)
{
    data.setData(dia, mes, ano);
}