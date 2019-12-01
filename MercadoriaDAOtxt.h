#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "MercadoriaDAO.h"
#include "Mercadoria.h"
using namespace std;

class MercadoriaDAOtxt : public MercadoriaDAO {
private:
    fstream arquivo;
private:
    string ler(const char* nome);
    bool abrir(const char* s, std::ios_base::openmode modo);
    Mercadoria* getMercadoria(string linha);
    string copiar(string *s, char parada);
    bool gravar(const char* nome, string s);

public:
    MercadoriaDAOtxt();
    ~MercadoriaDAOtxt();
    bool gravar(const char* nome, Mercadoria* mercadoria);
    list<Mercadoria*> getListaMercadorias(const char* nome);
    void fechar();

};

