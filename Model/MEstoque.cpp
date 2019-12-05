#include "MEstoque.h"

MEstoque* MEstoque::mEstoque = 0;

MEstoque::MEstoque()
{

}

MEstoque::~MEstoque()
{
    delete mEstoque;
}

MEstoque* MEstoque::getMEstoque()
{
    if (mEstoque == 0){
        mEstoque = new MEstoque();
    }
    return mEstoque;
}

bool MEstoque::setColchao(MMercadoria* colchao)
{
    if (colchao != NULL){
        listaColchoes.push_back(colchao);
        return true;
    }
    return false;
}

bool MEstoque::setBase(MMercadoria* base)
{
    if (base != NULL){
        listaBases.push_back(base);
        return true;
    }
    return false;
}

bool MEstoque::setSofa(MMercadoria* sofa)
{
    if (sofa != NULL){
        listaSofas.push_back(sofa);
        return true;
    }
    return false;
}

bool MEstoque::setPoltrona(MMercadoria* poltrona)
{
    if (poltrona != NULL){
        listaPoltronas.push_back(poltrona);
        return true;
    }
    return false;
}

bool MEstoque::setPuff(MMercadoria* puff)
{
    if (puff != NULL){
        listaPuffs.push_back(puff);
        return true;
    }
    return false;
}

list<MMercadoria*> MEstoque::getListaColchoes()
{
    return listaColchoes;
}

list<MMercadoria*> MEstoque::getListaBases()
{
    return listaBases;
}

list<MMercadoria*> MEstoque::getListaSofas()
{
    return listaSofas;
}

list<MMercadoria*> MEstoque::getListaPoltronas()
{
    return listaPoltronas;
}

list<MMercadoria*> MEstoque::getListaPuffs()
{
    return listaPuffs;
}
