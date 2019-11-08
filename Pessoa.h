#pragma once
#include <iostream>
#include "Endereco.h"

class Pessoa
{
protected:
    char nome[300];
    char cpf[300];
    char telefone[300];
    Endereco endereco;

public:
    Pessoa();
    Pessoa(char* nome);
    Pessoa(char* nome, char* cpf, char* telefone, Endereco endereco);
    ~Pessoa();
    const char* getNome();
    const char* getCpf();
    const char* getTelefone();
};
