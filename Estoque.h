#pragma once
#include <iostream>
using namespace std;
#include <list>
#include <map>

#include "Mercadoria.h"
#include "Colchao.h"

class Estoque
{
private:
    //multimap<list<Mercadoria*>> listaMercadorias;
    list<list<Mercadoria*>> listaMercadorias;
    static list<Colchao*> listaColchoes;
    //list<Base*> listaBases;
    //list<Cabeceira*> listaCabeceiras;
    //list<Sofa*> listaSofas;
    //list<Poltrona*> listaPoltronas;
    //list<Puff*> listaPuffs;


public:
    Estoque();
    ~Estoque();

    static void adicionarColchao(Colchao* colchao){
        if (colchao != nullptr) {
            listaColchoes.push_back(colchao);
        }
    }
};