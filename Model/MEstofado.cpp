#include "MEstofado.h"

MEstofado::MEstofado(int id, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, int lugares)
: MMercadoria(id, nome, fabricante, cor, largura, altura, profundidade, custo, preco)
{
    this->lugares = lugares;
}

MEstofado::~MEstofado()
{

}

void MEstofado::setLugares(int lugares)
{
    this->lugares = lugares;
}

const int MEstofado::getLugares()
{
    return lugares;
}
