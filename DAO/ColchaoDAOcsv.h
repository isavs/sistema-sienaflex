#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "ColchaoDAO.h"
#include "../Model/MColchao.h"
using namespace std;

class ColchaoDAOcsv : public ColchaoDAO {
private:
    fstream arquivo;
private:
    string ler(const char* nome);
    bool abrir(const char* s, std::ios_base::openmode modo);
    MColchao* getColchao(string linha);
    string copiar(string *s, char parada);
    bool gravar(const char* nome, string s);

public:
    ColchaoDAOcsv();
    ~ColchaoDAOcsv();
    bool gravar(const char* nome, MColchao* colchao);
    list<MColchao*> getListaColchoes(const char* nome);
    void fechar();

};

