#pragma once
#include "MMercadoria.h"
#include <iostream>
using namespace std;

class MColchao: public MMercadoria
{
private:
    string tamanho;

public:
    MColchao(){}
    MColchao(int id, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, string tamanho);
    ~MColchao();
    void setTamanho(string tamanho);
    const string getTamanho();
};
