#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "EstofadoDAO.h"
#include "../Model/MEstofado.h"
using namespace std;

class EstofadoDAObin : public EstofadoDAO {
private:
    fstream arquivo;
      
    struct sEstofado { 
        int id,
            lugares,
            ds, ms, as,
            de, me, ae;
        char nome[30],
            fabricante[30],
            cor[30];
        float largura,
            altura,
            profundidade,
            custo,
            preco;
        bool vendida;
    };

private:
    bool gravar(sEstofado estofado, const char* nome);

public:
    EstofadoDAObin();
    ~EstofadoDAObin();
    bool abrir(const char* nome, std::ios_base::openmode modo);
    bool gravar(const char* nome, MEstofado* estofado);
    list<MEstofado*> getListaEstofados(const char* nome);
    void fechar();

};

