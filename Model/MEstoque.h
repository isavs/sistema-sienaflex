#pragma once
#include <list>
#include "../Model/MMercadoria.h"
#include "../Model/MColchao.h"
#include "../Model/MEstofado.h"

class MEstoque
{
private:
    //static MEstoque* mEstoque;
    //list< list<MMercadoria*> > listaMercadorias;
    list<MColchao*> listaColchoes;
    list<MColchao*> listaBases;
    list<MEstofado*> listaSofas;
    list<MEstofado*> listaPoltronas;
    list<MEstofado*> listaPuffs;

private:
    MEstoque();
    ~MEstoque();

public:
    static MEstoque &getMEstoque();
    MEstoque(const MEstoque&) = delete;
    void operator = (const MEstoque&) = delete;

    bool setColchao(MColchao* colchao);
    bool setBase(MColchao* base);
    bool setSofa(MEstofado* sofa);
    bool setPoltrona(MEstofado* poltrona);
    bool setPuff(MEstofado* puff);
    list<MColchao*> getListaColchoes();
    list<MColchao*> getListaBases();
    list<MEstofado*> getListaSofas();
    list<MEstofado*> getListaPoltronas();
    list<MEstofado*> getListaPuffs();
};
