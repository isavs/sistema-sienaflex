#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "ColchaoDAO.h"
#include "../Model/MColchao.h"
using namespace std;

class ColchaoDAObin : public ColchaoDAO {
private:
    fstream arquivo;
      
    struct sColchao { 
        int id;
        char nome[30],
            fabricante[30],
            cor[30],
            tamanho[30];
        float largura,
            altura,
            profundidade,
            custo,
            preco;
        bool vendida;
    };

private:
    bool gravar(sColchao colchao, const char* nome);

public:
    ColchaoDAObin();
    ~ColchaoDAObin();
    bool abrir(const char* nome, std::ios_base::openmode modo);
    bool gravar(const char* nome, MColchao* colchao);
    list<MColchao*> getListaColchoes(const char* nome);
    void fechar();

};

