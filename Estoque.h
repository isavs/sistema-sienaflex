#pragma once
#include <iostream>
using namespace std;
#include <list>
#include <map>
#include <stdio.h>
#include "Mercadoria.h"
#include "Colchao.h"

class Estoque
{
private:
    //multimap<list<Mercadoria*>> listaMercadorias;
    list< list<Mercadoria*> > listaMercadorias;
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
        if (colchao != NULL) {
            listaColchoes.push_back(colchao);
        }
    }

    void listar(){
        //iterator it;
        //for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
           // printf ("%s\n", (*it)->getNome());
        //}
    }
};
