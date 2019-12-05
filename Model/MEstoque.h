#pragma once
#include <list>
#include "../Model/MMercadoria.h"

class MEstoque
{
private:
    static MEstoque* mEstoque;
    //list< list<MMercadoria*> > listaMercadorias;
    list<MMercadoria*> listaColchoes;
    list<MMercadoria*> listaBases;
    list<MMercadoria*> listaSofas;
    list<MMercadoria*> listaPoltronas;
    list<MMercadoria*> listaPuffs;

private:
    MEstoque();
    ~MEstoque();

public:
    static MEstoque* getMEstoque();
    bool setColchao(MMercadoria* colchao);
    bool setBase(MMercadoria* base);
    bool setSofa(MMercadoria* sofa);
    bool setPoltrona(MMercadoria* poltrona);
    bool setPuff(MMercadoria* puff);
    list<MMercadoria*> getListaColchoes();
    list<MMercadoria*> getListaBases();
    list<MMercadoria*> getListaSofas();
    list<MMercadoria*> getListaPoltronas();
    list<MMercadoria*> getListaPuffs();
};
