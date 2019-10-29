#include "Colchao.h"
#include "Estoque.h"

Colchao::Colchao()
{
    Estoque::adicionarColchao(this);
}

Colchao::~Colchao()
{

}