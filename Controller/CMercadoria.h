#pragma once
#include "../Model/MMercadoria.h"
#include "../Model/MColchao.h"
#include "../Model/MEstofado.h"
#include "CEstoque.h"

class CMercadoria
{
private:
    static int ids;

private:
    CMercadoria();
    ~CMercadoria();

public:
    static CMercadoria& getCMercadoria();
    CMercadoria(const CMercadoria&) = delete;
    void operator = (const CMercadoria&) = delete;

    bool criarColchao(string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, string tamanho);
    bool criarBase(string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, string tamanho);
    bool criarSofa(string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, int lugares);
    bool criarPoltrona(string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, int lugares);
    bool criarPuff(string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, int lugares);
};
