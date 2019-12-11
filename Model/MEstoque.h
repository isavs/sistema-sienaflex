#pragma once
#include <list>
#include "../Model/MMercadoria.h"
#include "../Model/MColchao.h"
#include "../Model/MEstofado.h"
#include "../DAO/ColchaoDAObin.h"
#include "../DAO/ColchaoDAOcsv.h"
#include "../DAO/EstofadoDAObin.h"
#include "../DAO/EstofadoDAOcsv.h"
class MEstoque
{
private:
    //static MEstoque* mEstoque;
    //list< list<MMercadoria*> > listaMercadorias;
    ColchaoDAObin cbin;
    ColchaoDAOcsv ccsv;

    EstofadoDAObin ebin;
    EstofadoDAOcsv ecsv;
    
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
    bool removerColchao(MColchao* colchao);
    bool removerBase(MColchao* base);
    bool removerSofa(MEstofado* sofa);
    bool removerPoltrona(MEstofado* poltrona);
    bool removerPuff(MEstofado* puff);
    list<MColchao*> getListaColchoes();
    list<MColchao*> getListaBases();
    list<MEstofado*> getListaSofas();
    list<MEstofado*> getListaPoltronas();
    list<MEstofado*> getListaPuffs();
    void salvarEstoque();
};
