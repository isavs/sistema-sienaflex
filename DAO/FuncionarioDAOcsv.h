#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "FuncionarioDAO.h"
#include "../Model/MFuncionario.h"
#include "../Util/UEndereco.h"
using namespace std;

class FuncionarioDAOcsv : public FuncionarioDAO {
private:
    fstream arquivo;
private:
    string ler(const char* nome);
    bool abrir(const char* s, std::ios_base::openmode modo);
    MFuncionario* getFuncionario(string linha);
    UEndereco* getEndereco(string linha);
    string copiar(string *s, char parada);
    bool gravar(const char* nome, string s);

public:
    FuncionarioDAOcsv();
    ~FuncionarioDAOcsv();
    bool gravar(const char* nome, MFuncionario* funcionario);
    list<MFuncionario*> getListaFuncionarios(const char* nome);
    void fechar();

};

