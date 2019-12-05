#include "CEstoque.h"

CEstoque::CEstoque()
{
    estoque = MEstoque::getMEstoque();
}

CEstoque::~CEstoque()
{

}

bool CEstoque::adicionarColchao(MMercadoria* colchao)
{
    if (colchao != NULL){
        estoque->setColchao(colchao);
        return true;
    }
    return false;
}

bool CEstoque::adicionarBase(MMercadoria* base)
{
    if (base != NULL){
        estoque->setBase(base);
        return true;
    }
    return false;
}

bool CEstoque::adicionarSofa(MMercadoria* sofa)
{
    if (sofa != NULL){
        estoque->setSofa(sofa);
        return true;
    }
    return false;
}

bool CEstoque::adicionarPoltrona(MMercadoria* poltrona)
{
    if (poltrona != NULL){
        estoque->setPoltrona(poltrona);
        return true;
    }
    return false;
}

bool CEstoque::adicionarPuff(MMercadoria* puff)
{
    if (puff != NULL){
        estoque->setPuff(puff);
        return true;
    }
    return false;
}

MMercadoria* CEstoque::pesquisarId(int id, int tipo)
{
    tipoMercadoria(tipo);
    list<MMercadoria*>::iterator it;
    for (it = listaMercadoria.begin(); it != listaMercadoria.end(); ++it){
        if ((*it)->getId() == id){
            return (*it);
        }
    }
    return NULL;
}

list<MMercadoria*> CEstoque::pesquisarNome(string nome, int tipo)
{
    tipoMercadoria(tipo);
    list<MMercadoria*> listaAux;
    list<MMercadoria*>::iterator it;
    for (it = listaMercadoria.begin(); it != listaMercadoria.end(); ++it){
        size_t nomeEncontrado = ((*it)->getNome()).find(nome);
        if (nomeEncontrado != string::npos){
            listaAux.push_back(*it);
        }
    }
    return listaAux;
}

list<MMercadoria*> CEstoque::pesquisarFabricante(string cor, int tipo)
{
    tipoMercadoria(tipo);
    list<MMercadoria*> listaAux;
    list<MMercadoria*>::iterator it;
    for (it = listaMercadoria.begin(); it != listaMercadoria.end(); ++it){
        size_t corEncontrada = ((*it)->getCor()).find(cor);
        if (corEncontrada != string::npos){
            listaAux.push_back(*it);
        }
    }
    return listaAux;
}

void CEstoque::tipoMercadoria(int tipo)
{
    listaMercadoria.clear();
    if (tipo == 1){
        listaMercadoria = estoque->getListaColchoes();
    } else if (tipo == 2){
        listaMercadoria = estoque->getListaBases();
    } else if (tipo == 3){
        listaMercadoria = estoque->getListaSofas();
    } else if (tipo == 4){
        listaMercadoria = estoque->getListaPoltronas();
    } else if (tipo == 5){
        listaMercadoria = estoque->getListaPuffs();
    }
}
