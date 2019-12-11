#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "EstofadoDAO.h"
#include "../Model/MEstofado.h"
using namespace std;

class EstofadoDAOcsv : public EstofadoDAO {
private:
    fstream arquivo;
private:
    string ler(const char* nome);
    bool abrir(const char* s, std::ios_base::openmode modo);
    MEstofado* getEstofado(string linha);
    string copiar(string *s, char parada);
    bool gravar(const char* nome, string s);

public:
    EstofadoDAOcsv();
    ~EstofadoDAOcsv();
    bool gravar(const char* nome, MEstofado* estofado);
    list<MEstofado*> getListaEstofados(const char* nome);
    void fechar();

};

