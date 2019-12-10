#include "CEstoque.h"

CEstoque::CEstoque()
{

}

CEstoque::~CEstoque()
{

}

CEstoque& CEstoque::getCEstoque()
{
    static CEstoque cEstoque;
    return cEstoque;
}

bool CEstoque::adicionarColchao(MColchao* colchao)
{
    MEstoque& estoque = MEstoque::getMEstoque();
    if (colchao != NULL){
        estoque.setColchao(colchao);
        return true;
    }
    return false;
}

bool CEstoque::adicionarBase(MColchao* base)
{
    MEstoque& estoque = MEstoque::getMEstoque();
    if (base != NULL){
        estoque.setBase(base);
        return true;
    }
    return false;
}

bool CEstoque::adicionarSofa(MEstofado* sofa)
{
    MEstoque& estoque = MEstoque::getMEstoque();
    if (sofa != NULL){
        estoque.setSofa(sofa);
        return true;
    }
    return false;
}

bool CEstoque::adicionarPoltrona(MEstofado* poltrona)
{
    MEstoque& estoque = MEstoque::getMEstoque();
    if (poltrona != NULL){
        estoque.setPoltrona(poltrona);
        return true;
    }
    return false;
}

bool CEstoque::adicionarPuff(MEstofado* puff)
{
    MEstoque& estoque = MEstoque::getMEstoque();
    if (puff != NULL){
        estoque.setPuff(puff);
        return true;
    }
    return false;
}

MColchao* CEstoque::pesquisarColchao(int id)
{
    CEstoque& cEstoque = CEstoque::getCEstoque();
    if (cEstoque.pesquisarIdColchao(id, 1) != NULL)
        return cEstoque.pesquisarIdColchao(id, 1);
    if (cEstoque.pesquisarIdColchao(id, 2) != NULL)
        return cEstoque.pesquisarIdColchao(id, 2);
    return NULL;
}

MEstofado* CEstoque::pesquisarEstofado(int id)
{
    CEstoque& cEstoque = CEstoque::getCEstoque();
    if (cEstoque.pesquisarIdEstofado(id, 3) != NULL)
        return cEstoque.pesquisarIdEstofado(id, 3);
    if (cEstoque.pesquisarIdEstofado(id, 4) != NULL)
        return cEstoque.pesquisarIdEstofado(id, 4);
    if (cEstoque.pesquisarIdEstofado(id, 5) != NULL)
        return cEstoque.pesquisarIdEstofado(id, 5);
    return NULL;
}

MColchao* CEstoque::pesquisarIdColchao(int id, int tipo)
{
    tipoMercadoria(tipo);
    list<MColchao*>::iterator it;
    for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
        if ((*it)->getId() == id){
            return (*it);
        }
    }
    return NULL;
}

MEstofado* CEstoque::pesquisarIdEstofado(int id, int tipo)
{
    tipoMercadoria(tipo);
    list<MEstofado*>::iterator it;
    for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
        if ((*it)->getId() == id){
            return (*it);
        }
    }
    return NULL;
}

list<MColchao*> CEstoque::pesquisarColchoes(int tipo, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float preco, string tamanho)
{
    tipoMercadoria(tipo);
    list<MColchao*> listaAux = listaColchoes;
    list<MColchao*>::iterator it;
    if (nome != ""){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getNome() != nome){
                it = listaAux.erase(it);
            }
        }
    }
    if (fabricante != ""){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getFabricante() != fabricante){
                it = listaAux.erase(it);
            }
        }
    }
    if (cor != ""){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getCor() != cor){
                it = listaAux.erase(it);
            }
        }
    }
    if (largura != 0.0){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getLargura() > largura){
                it = listaAux.erase(it);
            }
        }
    }
    if (altura != 0.0){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getAltura() > altura){
                it = listaAux.erase(it);
            }
        }
    }
    if (profundidade != 0.0){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getProfundidade() > profundidade){
                it = listaAux.erase(it);
            }
        }
    }
    if (preco != 0.0){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getPreco() > preco){
                it = listaAux.erase(it);
            }
        }
    }
    if (tamanho != ""){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getTamanho() == tamanho){
                it = listaAux.erase(it);
            }
        }
    }
    return listaAux;
}

list<MEstofado*> CEstoque::pesquisarEstofados(int tipo, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float preco, int lugares)
{
    tipoMercadoria(tipo);
    list<MEstofado*> listaAux = listaEstofados;
    list<MEstofado*>::iterator it;
    if (nome != ""){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getNome() != nome){
                it = listaAux.erase(it);
            }
        }
    }
    if (fabricante != ""){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getFabricante() != fabricante){
                it = listaAux.erase(it);
            }
        }
    }
    if (cor != ""){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getCor() != cor){
                it = listaAux.erase(it);
            }
        }
    }
    if (largura != 0.0){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getLargura() > largura){
                it = listaAux.erase(it);
            }
        }
    }
    if (altura != 0.0){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getAltura() > altura){
                it = listaAux.erase(it);
            }
        }
    }
    if (profundidade != 0.0){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getProfundidade() > profundidade){
                it = listaAux.erase(it);
            }
        }
    }
    if (preco != 0.0){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getPreco() > preco){
                it = listaAux.erase(it);
            }
        }
    }
    if (lugares != 0){
        for (it = listaAux.begin(); it != listaAux.end(); ++it){
            if ((*it)->getLugares() != lugares){
                it = listaAux.erase(it);
            }
        }
    }
    return listaAux;
}

void CEstoque::tipoMercadoria(int tipo)
{
    MEstoque& estoque = MEstoque::getMEstoque();
    listaColchoes.clear();
    listaEstofados.clear();
    if (tipo == 1){
        listaColchoes = estoque.getListaColchoes();
    } else if (tipo == 2){
        listaColchoes = estoque.getListaBases();
    } else if (tipo == 3){
        listaEstofados = estoque.getListaSofas();
    } else if (tipo == 4){
        listaEstofados = estoque.getListaPoltronas();
    } else if (tipo == 5){
        listaEstofados = estoque.getListaPuffs();
    }
}

bool CEstoque::checarListaColchao(list<MColchao*> listaAux, MColchao* mercadoria)
{
    list<MColchao*>::iterator it;
    for (it = listaAux.begin(); it != listaAux.end(); ++it){
        if ((*it) == mercadoria){
            return true;
        }
    }
    return false;
}

bool CEstoque::checarListaEstofado(list<MEstofado*> listaAux, MEstofado* mercadoria)
{
    list<MEstofado*>::iterator it;
    for (it = listaAux.begin(); it != listaAux.end(); ++it){
        if ((*it) == mercadoria){
            return true;
        }
    }
    return false;
}

void CEstoque::atualizarColchao(MColchao* colchao, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float preco, string tamanho)
{
    if (nome != "")
        colchao->setNome(nome);
    if (fabricante != "")
        colchao->setFabricante(fabricante);
    if (cor != "")
        colchao->setCor(cor);
    if (largura != 0.0)
        colchao->setLargura(largura);
    if (altura != 0.0)
        colchao->setAltura(altura);
    if (profundidade != 0.0)
        colchao->setProfundidade(profundidade);
    if (preco != 0.0)
        colchao->setPreco(preco);
    if (tamanho != "")
        colchao->setTamanho(tamanho);
}

void CEstoque::atualizarEstofado(MEstofado* estofado, string nome, string fabricante, string cor, float largura, float altura, float profundidade, float preco, int lugares)
{
    if (nome != "")
        estofado->setNome(nome);
    if (fabricante != "")
        estofado->setFabricante(fabricante);
    if (cor != "")
        estofado->setCor(cor);
    if (largura != 0.0)
        estofado->setLargura(largura);
    if (altura != 0.0)
        estofado->setAltura(altura);
    if (profundidade != 0.0)
        estofado->setProfundidade(profundidade);
    if (preco != 0.0)
        estofado->setPreco(preco);
    if (lugares != 0)
        estofado->setLugares(lugares);
}

list<MColchao*> CEstoque::listarColchoes()
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    return mEstoque.getListaColchoes();
}

list<MColchao*> CEstoque::listarBases()
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    return mEstoque.getListaBases();
}

list<MEstofado*> CEstoque::listarSofas()
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    return mEstoque.getListaSofas();
}

list<MEstofado*> CEstoque::listarPoltronas()
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    return mEstoque.getListaPoltronas();
}

list<MEstofado*> CEstoque::listarPuffs()
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    return mEstoque.getListaPuffs();
}

bool CEstoque::removerColchao(int id)
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    return mEstoque.removerColchao(pesquisarIdColchao(id, 1));
}

bool CEstoque::removerBase(int id)
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    return mEstoque.removerBase(pesquisarIdColchao(id, 2));
}

bool CEstoque::removerSofa(int id)
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    return mEstoque.removerSofa(pesquisarIdEstofado(id, 3));
}

bool CEstoque::removerPoltrona(int id)
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    return mEstoque.removerPoltrona(pesquisarIdEstofado(id, 4));
}

bool CEstoque::removerPuff(int id)
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    return mEstoque.removerPuff(pesquisarIdEstofado(id, 5));
}
