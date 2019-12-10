#include "CMercadoria.h"

int CMercadoria::ids = 0;

CMercadoria::CMercadoria()
{

}

CMercadoria::~CMercadoria()
{

}

CMercadoria& CMercadoria::getCMercadoria()
{
    static CMercadoria cMercadoria;
    return cMercadoria;
}

bool CMercadoria::criarColchao(string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, string tamanho)
{
    MColchao* colchao = new MColchao(ids++, nome, fabricante, cor, largura, altura, profundidade, custo, preco, tamanho);
    CEstoque& cEstoque = CEstoque::getCEstoque();
    return cEstoque.adicionarColchao(colchao);
}

bool CMercadoria::criarBase(string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, string tamanho)
{
    MColchao* base = new MColchao(ids++, nome, fabricante, cor, largura, altura, profundidade, custo, preco, tamanho);
    CEstoque& cEstoque = CEstoque::getCEstoque();
    bool valido = cEstoque.adicionarBase(base);
    return valido;
}

bool CMercadoria::criarSofa(string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, int lugares)
{
    MEstofado* sofa = new MEstofado(ids++, nome, fabricante, cor, largura, altura, profundidade, custo, preco, lugares);
    CEstoque& cEstoque = CEstoque::getCEstoque();
    bool valido = cEstoque.adicionarSofa(sofa);
    return valido;
}

bool CMercadoria::criarPoltrona(string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, int lugares)
{
    MEstofado* poltrona = new MEstofado(ids++, nome, fabricante, cor, largura, altura, profundidade, custo, preco, lugares);
    CEstoque& cEstoque = CEstoque::getCEstoque();
    bool valido = cEstoque.adicionarPoltrona(poltrona);
    return valido;
}

bool CMercadoria::criarPuff(string nome, string fabricante, string cor, float largura, float altura, float profundidade, float custo, float preco, int lugares)
{
    MEstofado* puff = new MEstofado(ids++, nome, fabricante, cor, largura, altura, profundidade, custo, preco, lugares);
    CEstoque& cEstoque = CEstoque::getCEstoque();
    bool valido = cEstoque.adicionarPuff(puff);
    return valido;
}
