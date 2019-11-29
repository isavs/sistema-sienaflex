#pragma once
#include <string>
using namespace std;

class EntidadeDAO {
public:
    virtual string ler(const char* nome) = 0;
    virtual bool abrir(const char* s) = 0;
    virtual bool gravar(const char* nome, string s) = 0;
    virtual void limpar(const char* nome) = 0;
    virtual void fechar() = 0;
};
