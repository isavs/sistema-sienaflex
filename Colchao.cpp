#include "Colchao.h"
#include "Estoque.h"

Colchao::Colchao(const char *nome)
{
    this->nome = nome;
    Estoque estoque;
    estoque.adicionarColchao(this);
}

Colchao::~Colchao()
{

}