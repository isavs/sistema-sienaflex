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
        for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
            size_t nomeEncontrado = ((*it)->getNome()).find(nome);
            if (nomeEncontrado != string::npos){
                listaAux.push_back(*it);
            }
        }
    }
    if (fabricante != ""){
        listaAux = checarFabricanteColchao(listaAux, fabricante);
        for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
            size_t fabricanteEncontrado = ((*it)->getFabricante()).find(fabricante);
            if (fabricanteEncontrado != string::npos){
                if (!checarListaColchao(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (cor != ""){
        listaAux = checarCorColchao(listaAux, cor);
        for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
            size_t corEncontrada = ((*it)->getCor()).find(cor);
            if (corEncontrada != string::npos){
                if (!checarListaColchao(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (largura != 0.0){
        listaAux = checarLarguraColchao(listaAux, largura);
        for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
            if (largura <= (*it)->getLargura()){
                if (!checarListaColchao(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (altura != 0.0){
        listaAux = checarAlturaColchao(listaAux, altura);
        for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
            if (altura <= (*it)->getAltura()){
                if (!checarListaColchao(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (profundidade != 0.0){
        listaAux = checarProfundidadeColchao(listaAux, profundidade);
        for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
            if (profundidade <= (*it)->getProfundidade()){
                if (!checarListaColchao(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (preco != 0.0){
        listaAux = checarPrecoColchao(listaAux, preco);
        for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
            if (preco <= (*it)->getPreco()){
                if (!checarListaColchao(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (tamanho != ""){
        listaAux = checarTamanhoColchao(listaAux, tamanho);
        for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
            size_t tamanhoEncontrado = ((*it)->getTamanho()).find(tamanho);
            if (tamanhoEncontrado != string::npos){
                if (!checarListaColchao(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
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
        for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
            size_t nomeEncontrado = ((*it)->getNome()).find(nome);
            if (nomeEncontrado != string::npos){
                listaAux.push_back(*it);
            }
        }
    }
    if (fabricante != ""){
        listaAux = checarFabricanteEstofado(listaAux, fabricante);
        for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
            size_t fabricanteEncontrado = ((*it)->getFabricante()).find(fabricante);
            if (fabricanteEncontrado != string::npos){
                if (!checarListaEstofado(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (cor != ""){
        listaAux = checarCorEstofado(listaAux, cor);
        for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
            size_t corEncontrado = ((*it)->getCor()).find(cor);
            if (corEncontrado != string::npos){
                if (!checarListaEstofado(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (largura != 0.0){
        listaAux = checarLarguraEstofado(listaAux, largura);
        for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
            if (largura <= (*it)->getLargura()){
                if (!checarListaEstofado(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (altura != 0.0){
        listaAux = checarAlturaEstofado(listaAux, altura);
        for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
            if (altura <= (*it)->getAltura()){
                if (!checarListaEstofado(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (profundidade != 0.0){
        listaAux = checarProfundidadeEstofado(listaAux, profundidade);
        for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
            if (profundidade <= (*it)->getProfundidade()){
                if (!checarListaEstofado(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (preco != 0.0){
        listaAux = checarPrecoEstofado(listaAux, preco);
        for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
            if (preco <= (*it)->getPreco()){
                if (!checarListaEstofado(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
            }
        }
    }
    if (lugares != 0){
        listaAux = checarLugaresEstofado(listaAux, lugares);
        for (it = listaEstofados.begin(); it != listaEstofados.end(); ++it){
            if (lugares == (*it)->getLugares()){
                if (!checarListaEstofado(listaAux, (*it))){
                    listaAux.push_back(*it);
                }
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

bool CEstoque::checarListaColchao(list<MColchao*> lista, MColchao* mercadoria)
{
    list<MColchao*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it) == mercadoria){
            return true;
        }
    }
    return false;
}

bool CEstoque::checarListaEstofado(list<MEstofado*> lista, MEstofado* mercadoria)
{
    list<MEstofado*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it) == mercadoria){
            return true;
        }
    }
    return false;
}

list<MColchao*> CEstoque::checarFabricanteColchao(list<MColchao*> lista, string fabricante)
{
    list<MColchao*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getFabricante() != fabricante){
            lista.erase(it);
        }
    }
    return lista;
}

list<MColchao*> CEstoque::checarCorColchao(list<MColchao*> lista, string cor)
{
    list<MColchao*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getCor() != cor){
            lista.erase(it);
        }
    }
    return lista;
}

list<MColchao*> CEstoque::checarLarguraColchao(list<MColchao*> lista, float largura)
{
    list<MColchao*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getLargura() > largura){
            lista.erase(it);
        }
    }
    return lista;
}

list<MColchao*> CEstoque::checarAlturaColchao(list<MColchao*> lista, float altura)
{
    list<MColchao*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getAltura() > altura){
            lista.erase(it);
        }
    }
    return lista;
}

list<MColchao*> CEstoque::checarProfundidadeColchao(list<MColchao*> lista, float profundidade)
{
    list<MColchao*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getProfundidade() > profundidade){
            lista.erase(it);
        }
    }
    return lista;
}

list<MColchao*> CEstoque::checarPrecoColchao(list<MColchao*> lista, float preco)
{
    list<MColchao*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getPreco() > preco){
            lista.erase(it);
        }
    }
    return lista;
}

list<MColchao*> CEstoque::checarTamanhoColchao(list<MColchao*> lista, string tamanho)
{
    list<MColchao*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getTamanho() == tamanho){
            lista.erase(it);
        }
    }
    return lista;
}

list<MEstofado*> CEstoque::checarFabricanteEstofado(list<MEstofado*> lista, string fabricante)
{
    list<MEstofado*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getFabricante() != fabricante){
            lista.erase(it);
        }
    }
    return lista;
}

list<MEstofado*> CEstoque::checarCorEstofado(list<MEstofado*> lista, string cor)
{
    list<MEstofado*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getCor() != cor){
            lista.erase(it);
        }
    }
    return lista;
}

list<MEstofado*> CEstoque::checarLarguraEstofado(list<MEstofado*> lista, float largura)
{
    list<MEstofado*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getLargura() > largura){
            lista.erase(it);
        }
    }
    return lista;
}

list<MEstofado*> CEstoque::checarAlturaEstofado(list<MEstofado*> lista, float altura)
{
    list<MEstofado*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getAltura() > altura){
            lista.erase(it);
        }
    }
    return lista;
}

list<MEstofado*> CEstoque::checarProfundidadeEstofado(list<MEstofado*> lista, float profundidade)
{
    list<MEstofado*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getProfundidade() > profundidade){
            lista.erase(it);
        }
    }
    return lista;
}

list<MEstofado*> CEstoque::checarPrecoEstofado(list<MEstofado*> lista, float preco)
{
    list<MEstofado*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getPreco() > preco){
            lista.erase(it);
        }
    }
    return lista;
}

list<MEstofado*> CEstoque::checarLugaresEstofado(list<MEstofado*> lista, int lugares)
{
    list<MEstofado*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        if ((*it)->getLugares() != lugares){
            lista.erase(it);
        }
    }
    return lista;
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
    list<MColchao*>::iterator it;
    for (it = mEstoque.getListaColchoes().begin(); it != mEstoque.getListaColchoes().end(); ++it){
        if ((*it)->getId() == id){
            mEstoque.getListaColchoes().erase(it);
            return true;
        }
    }
    return false;
}

bool CEstoque::removerBase(int id)
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    list<MColchao*>::iterator it;
    for (it = mEstoque.getListaBases().begin(); it != mEstoque.getListaBases().end(); ++it){
        if ((*it)->getId() == id){
            mEstoque.getListaBases().erase(it);
            return true;
        }
    }
    return false;
}

bool CEstoque::removerSofa(int id)
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    list<MEstofado*>::iterator it;
    for (it = mEstoque.getListaSofas().begin(); it != mEstoque.getListaSofas().end(); ++it){
        if ((*it)->getId() == id){
            mEstoque.getListaSofas().erase(it);
            return true;
        }
    }
    return false;
}

bool CEstoque::removerPoltrona(int id)
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    list<MEstofado*>::iterator it;
    for (it = mEstoque.getListaPoltronas().begin(); it != mEstoque.getListaPoltronas().end(); ++it){
        if ((*it)->getId() == id){
            mEstoque.getListaPoltronas().erase(it);
            return true;
        }
    }
    return false;
}

bool CEstoque::removerPuff(int id)
{
    MEstoque& mEstoque = MEstoque::getMEstoque();
    list<MEstofado*>::iterator it;
    for (it = mEstoque.getListaPuffs().begin(); it != mEstoque.getListaPuffs().end(); ++it){
        if ((*it)->getId() == id){
            mEstoque.getListaPuffs().erase(it);
            return true;
        }
    }
    return false;
}
