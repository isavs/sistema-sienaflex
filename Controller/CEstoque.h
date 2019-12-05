#pragma once
#include <list>
#include "../Model/MEstoque.h"
#include "../Model/MMercadoria.h"

class CEstoque
{
private:
    MEstoque* estoque;
    list<MMercadoria*> listaMercadoria;

public:
    CEstoque();
    ~CEstoque();
    bool adicionarColchao(MMercadoria* colchao);
    bool adicionarBase(MMercadoria* base);
    bool adicionarSofa(MMercadoria* sofa);
    bool adicionarPoltrona(MMercadoria* poltrona);
    bool adicionarPuff(MMercadoria* puff);
    void tipoMercadoria(int tipo);
    MMercadoria* pesquisarId(int id, int tipo);
    list<MMercadoria*> pesquisarNome(string nome, int tipo);
    list<MMercadoria*> pesquisarFabricante(string fabricante, int tipo);
    list<MMercadoria*> pesquisarCor(string cor, int tipo);
    list<MMercadoria*> pesquisarMedidas(float largura, float altura, float profundidade, int tipo);
    list<MMercadoria*> pesquisarPreco(float preco, int tipo);
};
