#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "PessoaDAO.h"
#include "Pessoa.h"
using namespace std;

class PessoaDAObin : public PessoaDAO {
private:
    fstream arquivo;
    struct sPessoa {
        int numero;
        char cep[300],
            rua[300],
            bairro[300],
            cidade[300],
            estado[300],
            pais[300],
            complemento[300],
            nome[30],
            cpf[30],
            telefone[30];
 
    }; 

private:
    bool gravar(const char* nome, sPessoa pessoa);

public:
    PessoaDAObin();
    ~PessoaDAObin();
    bool abrir(const char* nome, std::ios_base::openmode modo);
    bool gravar(const char* nome, Pessoa* pessoa);
    list<Pessoa*> getListaPessoas(const char* nome);
    void fechar();

};

