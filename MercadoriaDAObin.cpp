#include "MercadoriaDAObin.h"
#include <iostream>
#include <string.h>
MercadoriaDAObin::MercadoriaDAObin() {

}
MercadoriaDAObin::~MercadoriaDAObin() {
    fechar();
}

/*Métodos privados*/

bool MercadoriaDAObin::gravar(const char* nome, sMercadoria mercadoria) {

    printf("Chamou gravar\n");
    if(abrir(nome, ios::app)){
            printf("No if gravar\n");
            arquivo.write((const char*)(&mercadoria), sizeof(sMercadoria));
            fechar();
            return true;
        }
    fechar();
    return false;
}

/*Métodos publicos*/

bool MercadoriaDAObin::abrir(const char* nome, std::ios_base::openmode modo){

    arquivo.open(nome, modo);
    printf("chamou abrir\n");
    if(!arquivo.is_open() || !arquivo.good()) {
      return false;
    }

    return true;
}

bool MercadoriaDAObin::gravar(const char* nome, Mercadoria* mercadoria) {
    sMercadoria m;

    m.id = mercadoria->getId();
    strcpy(m.nome, (mercadoria->getNome()).c_str());
    strcpy(m.fabricante, (mercadoria->getFabricante()).c_str());
    strcpy(m.cor, (mercadoria->getCor()).c_str());
    strcpy(m.marca, (mercadoria->getMarca()).c_str());
    m.custo = mercadoria->getCusto();
    m.preco = mercadoria->getPreco();
    m.vendida = mercadoria->getStatus();

    return gravar(nome, m);
}

list<Mercadoria*> MercadoriaDAObin::getListaMercadorias(const char* nome) {
    list<Mercadoria*> lista;
    sMercadoria m;

    if(abrir(nome, ios::in)){
        while(arquivo && !arquivo.eof()) {
            arquivo.read((char *)(&m), sizeof(sMercadoria));
            Mercadoria* mercadoria = new Mercadoria(m.id, m.nome, m.fabricante, m.cor, m.marca, m.custo, m.preco, m.vendida);
            lista.push_back(mercadoria);
        }        
    }

    fechar();
    return lista;
}


void MercadoriaDAObin::fechar(){
    arquivo.close();
}