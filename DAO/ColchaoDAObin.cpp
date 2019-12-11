#include "ColchaoDAObin.h"
#include <iostream>
#include <string.h>
ColchaoDAObin::ColchaoDAObin() {

}
ColchaoDAObin::~ColchaoDAObin() {
    fechar();
}

/*Métodos privados*/

bool ColchaoDAObin::gravar(sColchao colchao, const char* nome) {

    if(abrir(nome, ios::app)){
            arquivo.write((const char*)(&colchao), sizeof(sColchao));
            fechar();
            return true;
        }
    fechar();
    return false;
}

/*Métodos publicos*/

bool ColchaoDAObin::abrir(const char* nome, std::ios_base::openmode modo){

    arquivo.open(nome, modo);
    if(!arquivo.is_open() || !arquivo.good()) {
      return false;
    }

    return true;
}

bool ColchaoDAObin::gravar(const char* nome, MColchao* colchao) {
    sColchao m;

    m.id = colchao->getId();
    m.ds = colchao->getDataSaida().getDia();
    m.ms = colchao->getDataSaida().getMes();
    m.as = colchao->getDataSaida().getAno();
    m.de = colchao->getDataEntrada().getDia();
    m.me = colchao->getDataEntrada().getDia();
    m.ae = colchao->getDataEntrada().getDia();
    strcpy(m.nome, (colchao->getNome()).c_str());
    strcpy(m.fabricante, (colchao->getFabricante()).c_str());
    strcpy(m.cor, (colchao->getCor()).c_str());
    m.largura = colchao->getLargura();
    m.altura = colchao->getAltura();
    m.profundidade = colchao->getProfundidade();
    m.custo = colchao->getCusto();
    m.preco = colchao->getPreco();
    m.vendida = colchao->getStatus();
    strcpy(m.tamanho, (colchao->getTamanho()).c_str());
    
    return gravar(m, nome);
}

list<MColchao*> ColchaoDAObin::getListaColchoes(const char* nome) {
    list<MColchao*> lista;
    sColchao m;

    if(abrir(nome, ios::in)){
        while(arquivo && !arquivo.eof()) {
            arquivo.read((char *)(&m), sizeof(sColchao));
            MColchao* colchao = new MColchao(m.id, m.nome, m.fabricante, m.cor, m.largura, m.altura, m.profundidade, m.custo, m.preco, m.tamanho);
            colchao->setDataEntrada(m.de,m.me,m.ae);
            colchao->setDataSaida(m.ds,m.ms,m.as);
            lista.push_back(colchao);
        }        
    }

    fechar();
    return lista;
}


void ColchaoDAObin::fechar(){
    arquivo.close();
}