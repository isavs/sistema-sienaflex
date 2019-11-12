#pragma once
#include <iostream>
using namespace std;
#include <list>
#include <map>
#include <stdio.h>
#include "Mercadoria.h"

class Estoque
{
private:
    //multimap<list<Mercadoria*>> listaMercadorias;
    list< list<Mercadoria*> > listaMercadorias;
    list<Mercadoria*> listaColchoes;
    list<Mercadoria*> listaPoltronas;
    //list<Colchao*> listaColchoes;


public:
    Estoque();
    ~Estoque();

    void inicializarListas();
    void adicionarColchao(Mercadoria* colchao);
    void adicionarPoltrona(Mercadoria* poltrona);
    /*
    void adicionarColchao(Colchao* colchao){
        if (colchao != NULL) {
            listaColchoes.push_back(colchao);
        }
    }

    void listar(){
        std::list<Colchao*>::iterator it;
        for (it = listaColchoes.begin(); it != listaColchoes.end(); ++it){
           printf ("%s\n", (*it)->getNome());
        }
    }*/
};
