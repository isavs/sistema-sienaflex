#include "MColchao.h"

MColchao::MColchao()
{

}

MColchao::MColchao(int id, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, string tamanho)
: MMercadoria(id, nome, fabricante, cor, largura, altura, profundidade, custo, preco)
{
    this->tamanho = tamanho;
}

MColchao::~MColchao()
{

}

void MColchao::setTamanho(string tamanho)
{
    this->tamanho = tamanho;
}

const string MColchao::getTamanho()
{
    return tamanho;
}
