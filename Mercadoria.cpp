#include "Mercadoria.h"


Mercadoria::Mercadoria()
{
    id = 0;
    nome = fabricante = cor = marca = nullptr;
    custo = preco = 0.0;
    vendida = false;
}

Mercadoria::~Mercadoria()
{
    id = 0;
    nome = fabricante = cor = marca = nullptr;
    custo = preco = 0.0;
    vendida = false;
}