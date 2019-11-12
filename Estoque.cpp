#include "Estoque.h"

Estoque::Estoque()
{

}

Estoque::~Estoque()
{

}

void Estoque::inicializarListas()
{
    listaMercadorias.push_back(listaColchoes);
    listaMercadorias.push_back(listaPoltronas);
}

void Estoque::adicionarColchao(Mercadoria* colchao)
{
    if (colchao != NULL){
        listaColchoes.push_back(colchao);
    }
}

void Estoque::adicionarPoltrona(Mercadoria* poltrona)
{
    if (poltrona != NULL){
        listaPoltronas.push_back(poltrona);
    }
}
