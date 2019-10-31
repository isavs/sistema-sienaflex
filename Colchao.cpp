#include "Colchao.h"
#include "Estoque.h"

Colchao::Colchao(const char *nome)
{
    this->nome = nome;
    Estoque::adicionarColchao(this);
}

Colchao::~Colchao()
{

}