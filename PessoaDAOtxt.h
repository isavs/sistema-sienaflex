#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "PessoaDAO.h"
#include "Pessoa.h"
#include "Endereco.h"
using namespace std;

class PessoaDAOtxt : public PessoaDAO {
private:
    fstream arquivo;
private:
    string ler(const char* nome);
    bool abrir(const char* s, std::ios_base::openmode modo);
    Pessoa* getPessoa(string linha);
    Endereco* getEndereco(string linha);
    string copiar(string *s, char parada);
    bool gravar(const char* nome, string s);

public:
    PessoaDAOtxt();
    ~PessoaDAOtxt();
    bool gravar(const char* nome, Pessoa* Pessoa);
    list<Pessoa*> getListaPessoas(const char* nome);
    void fechar();

};

