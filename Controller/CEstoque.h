#pragma once
#include <list>
#include "../Model/MEstoque.h"
#include "../Model/MMercadoria.h"

class CEstoque
{
private:
    list<MColchao*> listaColchoes;
    list<MEstofado*> listaEstofados;

private:
    CEstoque();
    ~CEstoque();

public:
    static CEstoque &getCEstoque();
    CEstoque(const CEstoque&) = delete;
    void operator = (const CEstoque&) = delete;

    bool adicionarColchao(MColchao* colchao);
    bool adicionarBase(MColchao* base);
    bool adicionarSofa(MEstofado* sofa);
    bool adicionarPoltrona(MEstofado* poltrona);
    bool adicionarPuff(MEstofado* puff);
    void tipoMercadoria(int tipo);

    MColchao* pesquisarIdColchao(int id, int tipo);
    MEstofado* pesquisarIdEstofado(int id, int tipo);
    MColchao* pesquisarColchao(int id);
    MEstofado* pesquisarEstofado(int id);
    list<MColchao*> pesquisarColchoes(int tipo, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float preco, string tamanho);
    list<MEstofado*> pesquisarEstofados(int tipo, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float preco, int lugares);
    bool checarListaColchao(list<MColchao*> lista, MColchao* mercadoria); // checa se o produto ja não foi adicionado a lista
    bool checarListaEstofado(list<MEstofado*> lista, MEstofado* mercadoria);
    list<MColchao*> checarNomeColchao(list<MColchao*> lista, string nome);

    void atualizarColchao(MColchao* colchao, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float preco, string tamanho);
    void atualizarEstofado(MEstofado* estofado, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float preco, int lugares);

    list<MColchao*> listarColchoes();
    list<MColchao*> listarBases();
    list<MEstofado*> listarSofas();
    list<MEstofado*> listarPoltronas();
    list<MEstofado*> listarPuffs();

    bool removerColchao(int id);
    bool removerBase(int id);
    bool removerSofa(int id);
    bool removerPoltrona(int id);
    bool removerPuff(int id);

    void salvarEstoque();
};
