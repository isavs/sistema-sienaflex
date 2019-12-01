#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "MercadoriaDAO.h"
#include "Mercadoria.h"
using namespace std;

class MercadoriaDAObin : public MercadoriaDAO {
private:
    fstream arquivo;
      
    struct sMercadoria { 
        int id;
        char nome[30],
            fabricante[30],
            cor[30],
            marca[30];
        float custo,
            preco;
        bool vendida;
    }; 

private:
    bool gravar(const char* nome, sMercadoria mercadoria);

public:
    MercadoriaDAObin();
    ~MercadoriaDAObin();
    bool abrir(const char* nome, std::ios_base::openmode modo);
    bool gravar(const char* nome, Mercadoria* mercadoria);
    list<Mercadoria*> getListaMercadorias(const char* nome);
    void fechar();

};

