#include "MEstoque.h"

//MEstoque* MEstoque::mEstoque = NULL;

MEstoque::MEstoque()
{

}

MEstoque::~MEstoque()
{

}

MEstoque& MEstoque::getMEstoque()
{
    static MEstoque mEstoque;
    return mEstoque;
}

bool MEstoque::setColchao(MColchao* colchao)
{
    if (colchao != NULL){
        listaColchoes.push_back(colchao);
        return true;
    }
    return false;
}

bool MEstoque::setBase(MColchao* base)
{
    if (base != NULL){
        listaBases.push_back(base);
        return true;
    }
    return false;
}

bool MEstoque::setSofa(MEstofado* sofa)
{
    if (sofa != NULL){
        listaSofas.push_back(sofa);
        return true;
    }
    return false;
}

bool MEstoque::setPoltrona(MEstofado* poltrona)
{
    if (poltrona != NULL){
        listaPoltronas.push_back(poltrona);
        return true;
    }
    return false;
}

bool MEstoque::setPuff(MEstofado* puff)
{
    if (puff != NULL){
        listaPuffs.push_back(puff);
        return true;
    }
    return false;
}

list<MColchao*> MEstoque::getListaColchoes()
{
    return listaColchoes;
}

list<MColchao*> MEstoque::getListaBases()
{
    return listaBases;
}

list<MEstofado*> MEstoque::getListaSofas()
{
    return listaSofas;
}

list<MEstofado*> MEstoque::getListaPoltronas()
{
    return listaPoltronas;
}

list<MEstofado*> MEstoque::getListaPuffs()
{
    return listaPuffs;
}
