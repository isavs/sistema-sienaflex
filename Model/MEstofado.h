#pragma once
#include "MMercadoria.h"

class MEstofado: public MMercadoria
{
private:
    int lugares;

public:
    MEstofado(){}
    MEstofado(int id, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, int lugares);
    ~MEstofado();
    void setLugares(int lugares);
    const int getLugares();
};
